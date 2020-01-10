#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 5

int visited[MAX_VERTICES];

typedef struct GraphNode
{
	int vertex;
	struct GraphNode *link;
} GraphNode;

typedef struct GraphType {
	int n;	// 정점의 개수
	GraphNode *adj_list[MAX_VERTICES];
} GraphType;

// 그래프 초기화 
void graph_init(GraphType *g)
{
	int v;
	g->n = 0;
	for (v = 0; v<MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
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

	// 방향그래프이므로 아래의 코드는 삭제해야한다
	/*node = (GraphNode *)malloc(sizeof(GraphNode));
	node->vertex = u;
	node->link = g->adj_list[v];
	g->adj_list[v] = node;*/
}

int call_out_degree(GraphType *g, int v)
{
	// 코드 작성
	int total = 0;
	GraphNode *n;
	n = g->adj_list[v];

	while (n != NULL)
	{
		n = n->link;
		total++;
	}
	return total;
}

int main(void) //변경하지 마라
{
	GraphType g;
	int num;
	int u, v;

	graph_init(&g);

	scanf("%d", &num); // 정점의 개수
	g.n = num;
	scanf("%d %d", &u, &v);
	while (u != -1 && v != -1) {
		insert_edge(&g, u, v);
		scanf("%d %d", &u, &v);
	}

	scanf("%d", &v);
	printf("%d\n", call_out_degree(&g, v));
}