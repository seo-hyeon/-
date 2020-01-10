#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 20

typedef struct GraphNode
{
	int vertex;
	struct GraphNode *link;
} GraphNode;

typedef struct GraphType {
	int n;	// 정점의 개수
	GraphNode *adj_list[MAX_VERTICES];
} GraphType;


// 오류 처리 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 그래프 초기화 
void graph_init(GraphType *g)
{
	int v;
	g->n = 0;
	for (v = 0; v<MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
}
// 정점 삽입 연산
void insert_vertex(GraphType *g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	g->n++;
}
// 간선 삽입 연산, v를 u의 인접 리스트에 삽입한다.
void insert_edge(GraphType *g, int u, int v)
{
	GraphNode *node;
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	node = (GraphNode *)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
}

void display_graph(GraphType *g)
{
	// 코드 작성
	printf("%d\n", g->n);

	for (int i = 0; i<g->n; i++) {
		GraphNode* ptr = g->adj_list[i];

		while (ptr != NULL) {
			printf("%d %d\n", i, ptr->vertex);
			ptr = ptr->link;
		}
	}
}

int main(void)
{
	GraphType g;
	int u, v;

	graph_init(&g);

	scanf("%d", &g.n);
	scanf("%d %d", &u, &v);
	while (u != -1 && v != -1) {
		insert_edge(&g, u, v);
		scanf("%d %d", &u, &v);
	}

	//scanf("%d %d", &u, &v);
	display_graph(&g);
}