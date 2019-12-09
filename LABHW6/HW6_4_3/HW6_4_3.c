#include <stdio.h>
#include <string.h>
#include <limits.h>

#define TRUE	1
#define FALSE	0
#define MAX_VERTICES	100		/* 노드의 수 */
#define INF 	9999		/* 무한 값(연결이 없는 경우) */

int distance[MAX_VERTICES];	/* 시작노드로부터의 최단경로 거리 */
int previous[MAX_VERTICES];	/* 경유 노드  */
int found[MAX_VERTICES];	/* 방문한 노드 표시 */

typedef struct GraphType {
	int n;					// 정점의 개수
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;
typedef struct Station {
	char *name;
}Station;

// 그래프 초기화 
void graph_init(GraphType *g)
{
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = INF;

	for (r = 0; r < MAX_VERTICES; r++) // pak 추가, 자기자신에로의 거리를 0으로
		g->adj_mat[r][r] = 0;
}

/*  */
void read_graph(GraphType *g, char *filename)
{
	int n, u, v;
	FILE *fp = fopen(filename, "r");
	if (fp == NULL) {
		fprintf(stderr, "파일 %s을 열 수 없음!\n", filename); return;
	}
	fscanf(fp, "%d\n", &n);
	g->n = n;
	while (fscanf(fp, "%d %d", &u, &v) != EOF) {
		fscanf(fp, "%d\n", &g->adj_mat[u][v]);
		g->adj_mat[v][u] = g->adj_mat[u][v];
	}
	fclose(fp);
}

int choose(int distance[], int n, int found[])
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n; i++)
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	return minpos;
}

void print_path(int start, int end, Station station[]) // 역을 출력할 수있게 수정
{
	//char station[12] = { "월곡", "종묘", "동대문", "종로3가", "시청", "을지로3가", "동대문역사", "신당", "청구", "약수", "충무로", "서울역" };
	if (start == end)
		printf("%s", station[start].name);
	else {
		print_path(start, previous[end], station);
		printf("-> %s ", station[end].name);
	}
}

void shortest_path(GraphType *g, int start, int end, Station station[])
{
	int i, u, w;
	for (i = 0; i<g->n; i++) /* 초기화 */
	{
		distance[i] = g->adj_mat[start][i];
		found[i] = FALSE;
		previous[i] = start;
	}

	found[start] = TRUE;    /* 시작노드 방문 표시 */
	distance[start] = 0;

	for (i = 0; i < (g->n) - 1; i++) {
		u = choose(distance, g->n, found);
		found[u] = TRUE;

		for (w = 0; w<g->n; w++) {
			if (!found[w])
				if (distance[u] + g->adj_mat[u][w] < distance[w]) {
					distance[w] = distance[u] + g->adj_mat[u][w];
					previous[w] = u;		/* 경유노드 저장 */
				}
		}

		if (u == end)
			break;
	}

	print_path(start, u, station);
	printf(" (%d)\n", distance[u]);
}

void main()
{
	GraphType g;		// 입력 그래프
	char start[50], dest[50];
	int i, sIndex, dIndex, u;

	Station station[12];
	station[0].name = "월곡";
	station[1].name = "종묘";
	station[2].name = "동대문";
	station[3].name = "종로3가";
	station[4].name = "시청";
	station[5].name = "을지로3가";
	station[6].name = "동대문역사";
	station[7].name = "신당";
	station[8].name = "청구";
	station[9].name = "약수";
	station[10].name = "충무로";
	station[11].name = "서울역";

	graph_init(&g);

	read_graph(&g, "input.txt");

	printf("시작점:");
	scanf("%s", start);
	for (i = 0; i < 12; i++)
		if (strcmp(station[i].name, start) == 0)
		{
			sIndex = i;
			break;
		}
	if (i == 12)
	{
		printf("%s 역은 존재하지 않습니다.\n", start);
		return -1;
	}

	printf("도착점:");
	scanf("%s", dest);
	for (i = 0; i < 12; i++)
		if (strcmp(station[i].name, start) == 0)
		{
			dIndex = i;
			break;
		}
	if (i == 12)
	{
		printf("%s 역은 존재하지 않습니다.\n", start);
		return -1;
	}

	shortest_path(&g, sIndex, dIndex, station);
}