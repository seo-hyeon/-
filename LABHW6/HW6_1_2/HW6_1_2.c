#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
typedef int element;
typedef struct GraphNode
{
	int vertex;
	struct GraphNode *link;
} GraphNode;

typedef struct GraphType {
	int n;	// ������ ����
	GraphNode *adj_list[MAX_VERTICES];
} GraphType;

// �׷��� �ʱ�ȭ 
void graph_init(GraphType *g)
{
	int v;
	g->n = 0;
	for (v = 0; v<MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
}

// ���� ���� ����, v�� u�� ���� ����Ʈ�� �����Ѵ�.
void insert_edge(GraphType *g, int u, int v)
{
	GraphNode *node_u, *node_v;
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "�׷���: ���� ��ȣ ����");
		return;
	}
	node_u = (GraphNode *)malloc(sizeof(GraphNode));
	if (node_u == NULL) {
		fprintf(stderr, "�޸� �Ҵ� ����!\n"); return;
	}

	// �ڵ� ����
	node_u->vertex = v;
	node_u->link = g->adj_list[u];
	g->adj_list[u] = node_u;
}

void remove_node(GraphNode **phead, element item) { // 4�� ����Ʈ���� �н��� �Լ����� ListNode --> GraphNode�� ��������
	GraphNode *p, *prevp;

	if (*phead == NULL)
		printf("����Ʈ�� ����ֽ��ϴ�.\n");
	else if ((*phead)->vertex == item) {
		p = *phead;
		*phead = (*phead)->link;
		free(p);
	}
	else {
		p = *phead;
		do {
			prevp = p;
			p = p->link;
		} while (p != NULL && p->vertex != item);
		if (p != NULL) {
			prevp->link = p->link;
			free(p);
		}
		else
			printf("%d�� ����Ʈ�� ����\n", item);
	}
}
// ���� ���� ����, v�� u�� ���� ����Ʈ���� �����Ѵ�.
void delete_edge(GraphType *g, int u, int v)
{
	GraphNode *node;
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "�׷���: ���� ��ȣ ����");
		return;
	}

	// �ڵ� ����
	// (u, v)�� �����Ѵ�. remove_node�� ���. 

	node = g->adj_list[u];

	remove_node(&node, v);
}

void read_graph(GraphType *g, char *filename)
{
	/*int number, u, v;
	GraphNode *node;
	FILE *fp;
	fp = fopen(filename, "rt");
	if (fp == NULL)
	{
		printf("file open error!\n");
		return;
	}

	// �ڵ� ����

	fclose(fp);*/

	int number, u, v;
	FILE *fp;
	char str[20], a[20];
	int s, e, i;

	fp = fopen(filename, "rt");
	if (fp == NULL)
	{
		printf("file %s open error!\n", filename);
		return;
	}

	if (!feof(fp))
	{
		fgets(str, 80, fp);
		g->n = atoi(str);
	}
	while (!feof(fp))
	{
		fgets(str, 80, fp);

		if (strcmp(str, a) == 0)
			break;

		s = atoi(strtok(str, " "));
		e = atoi(strtok(NULL, " "));

		insert_edge(g, s, e);

		for (i = 0; str[i] != '\0'; i++)
			a[i] = str[i];
		a[i] = '\0';
	}
	// �ڵ� ����

	fclose(fp);
}


void write_graph(GraphType *g, char *filename)
{
	int u;
	FILE *fp;
	GraphNode *ptr;

	if (filename == NULL) fp = stdout;
	else {
		fp = fopen(filename, "w");
		if (fp == NULL)
		{
			printf("file %s open error!\n", filename);
			return;
		}
	}

	// �ڵ� ����
	fprintf(fp, "%d\n", g->n);

	for (int i = 0; i<g->n; i++) {
		GraphNode* ptr = g->adj_list[i];

		while (ptr != NULL) {
			fprintf(fp, "%d %d\n", i, ptr->vertex);
			ptr = ptr->link;
		}
	}

	fputs("\n", fp);

	if (filename != NULL) fclose(fp);
}

void print_adj_list(GraphType* g)
{
	for (int i = 0; i<g->n; i++) {
		GraphNode* p = g->adj_list[i];
		printf("���� %d�� ���� ����Ʈ ", i);
		while (p != NULL) {
			printf("-> %d ", p->vertex);
			p = p->link;
		}
		printf("\n");
	}
}

int main(void)
{
	GraphType g;
	graph_init(&g);

	read_graph(&g, "input.txt");
	write_graph(&g, NULL);	// to stdout

	insert_edge(&g, 1, 3);
	write_graph(&g, NULL);	// to stdout

	delete_edge(&g, 0, 2);
	write_graph(&g, NULL);	// to stdout

	write_graph(&g, "output.txt");
}