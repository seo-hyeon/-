#include <stdio.h>
#include <string.h>

#define MAX_VERTICES 50

typedef struct GraphType {
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

// 그래프 초기화 
void graph_init(GraphType *g)
{
	int r, c;
	g->n = 0;
	for (r = 0; r<MAX_VERTICES; r++)
		for (c = 0; c<MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0;
}


// 간선 삽입 연산
void insert_edge(GraphType *g, int start, int end)
{
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}

// 간선 삭제 연산
void delete_edge(GraphType *g, int start, int end)
{
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}

	g->adj_mat[start][end] = 0;
	g->adj_mat[end][start] = 0;
}
//
void read_graph(GraphType *g, char *filename)
{
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
	// 코드 삽입

	fclose(fp);
}

//
void write_graph(GraphType *g, char *filename)
{
	int i, j;
	FILE *fp;

	if (filename == NULL) fp = stdout;
	else {
		fp = fopen(filename, "wt");
		if (fp == NULL)
		{
			printf("file %s open error!\n", filename);
			return;
		}
	}

	// 코드 삽입
	fprintf(fp, "%d\n", g->n);

	for (int i = 0; i < g->n; i++) {
		for (int j = i; j < g->n; j++) {
			if (g->adj_mat[i][j] == 1)
				fprintf(fp, "%d %d\n", i, j);
		}
	}

	fputs("\n", fp);
	if (filename != NULL) fclose(fp);
}

void print_adj_mat(GraphType* g)
{
	for (int i = 0; i < g->n; i++) {
		for (int j = 0; j < g->n; j++) {
			printf("%2d ", g->adj_mat[i][j]);
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

	delete_edge(&g, 2, 0);
	write_graph(&g, NULL);	// to stdout

	write_graph(&g, "output.txt");
}