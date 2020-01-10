#include <stdio.h>
#include <limits.h>

#define TRUE	1
#define FALSE	0
#define VERTICES	5		/* 정점의 수 */
#define INF	10000	/* 무한대 (연결이 없는 경우) */

/* 네트워크의 인접행렬 */
int weight[VERTICES][VERTICES] = {
	{ 0, 10, INF, 50, INF },
{ 10, 0, 45, 30, 60 },
{ INF, 45, 0, 5, 20 },
{ 50, 30, 5, 0, INF },
{ INF, 60, 20, INF, 0 } };

int A[VERTICES][VERTICES];
int prev[VERTICES][VERTICES]; // 추가되는 배열

void printMatrix(int A[][VERTICES], int n)
{
	int i, j, k;
	//printf("      %3s %3s %3s %3s %3s\n", "[0]", "[1]", "[2]", "[3]", "[4]");
	//printf("--------------------------\n");
	for (i = 0; i<n; i++) {
		//printf("[%d]| ", i);
		for (j = 0; j<n; j++)
			if (A[i][j] == INF)
				printf("INF ");
			else
				printf("%3d ", A[i][j]);

		printf("\n");
	}
	printf("==========================\n");
}

void printPath(int s, int e) // 추가
{
	// 코드 추가
	int path[5];
	int i = 0, j = e;

	path[0] = e;

	while (1)
	{
		if (prev[s][j] == -1)
			break;

		i++;

		path[i] = prev[s][j];
		j = prev[s][j];
	}

	printf("%d", s);
	for (; i >= 0; i--)
		printf("->%d", path[i]);

	printf("(%d)", A[s][e]);
}

// 이 함수에 추가가 필요
void floyd(int n)
{
	FILE *fp;
	int i, j, k;

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			A[i][j] = weight[i][j];
			prev[i][j] = -1;
		}

	//printf("초기 상태\n"); // 나중에 주석화
	//printMatrix(A, n); // 나중에 주석화

	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if (A[i][k] + A[k][j] < A[i][j]) {
					A[i][j] = A[i][k] + A[k][j];
					prev[i][j] = k;
				}
		//printf("%d를 경유해서 다시 계산\n", k); // 나중에 주석화
		printMatrix(A, n); // 나중에 주석화
		printMatrix(prev, n);
	}
}

int main(void)
{
	int start, end;
	scanf("%d", &start);
	scanf("%d", &end);
	floyd(VERTICES);

	printPath(start, end);
	//호출 부분 추가
}