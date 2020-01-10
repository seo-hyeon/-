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

GraphNode *delete_by_key(GraphNode *head, int key)
{
	GraphNode *temp = head;
	GraphNode *prevTemp;
	GraphNode *removed;

	if (head == NULL) error("삭제할 항목이 없음");
	if (temp->vertex == key) { // 첫번째 것을 지우려 하면
		removed = head;
		head = head->link;
		free(removed);
		return head;
	}
	else {
		prevTemp = temp;
		temp = temp->link;
		while (temp != NULL) {
			if (temp->vertex == key) {
				prevTemp->link = temp->link;
				free(temp);
				break;
			}
			prevTemp = temp;
			temp = temp->link;
		}
		return head; // 그대로
	}
}

// 코드 작성: 연결리스트의 연산인 delete_by_key를 사용하여도 좋다
void delete_edge(GraphType *g, int u, int v)
{
	// 코드 작성
	g->adj_list[u] = delete_by_key(g->adj_list[u], v);
}

//앞의 문제에서 작성한 코드를 넣는다
void display_graph(GraphType *g)
{
	// 이전문제에서 정의한 함수 사용
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

	scanf("%d %d", &u, &v);
	delete_edge(&g, u, v);
	display_graph(&g);
}