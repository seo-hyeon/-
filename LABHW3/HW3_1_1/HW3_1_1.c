#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 3 //3으로 설정
#define MAX_STRING 100 // 추가

typedef struct { 
	char name[MAX_STRING];
} element;

typedef struct {
	element  queue[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;
//
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
// 초기화 함수
void init(QueueType *q)
{
	q->front = q->rear = 0;
}
// 공백 상태 검출 함수
int is_empty(QueueType *q)
{
	return (q->front == q->rear);
}
// 포화 상태 검출 함수
int is_full(QueueType *q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
// 삽입 함수
void enqueue(QueueType *q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}
// 삭제 함수
element dequeue(QueueType *q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}
// 보기 함수
element peek(QueueType *q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->queue[(q->front + 1) % MAX_QUEUE_SIZE];
}

int get_count(QueueType *q)
{
	return q->rear - q->front - 1;
}

void print_queue(QueueType *q)
{
	int i;
	printf("%d명: ", get_count(q) + 1);

	for (i = q->front + 1; i <= q->rear; i++)
		printf("%s ", q->queue[i].name);
	printf("\n");
}

void checkCouple(QueueType *q, QueueType *op, element e)
{
	if (is_empty(op) && is_full(q))
		printf("아직 대상자가 없습니다. 대기자가 꽉찼으니 담기회를 이용\n");
	else if (is_empty(op))
	{
		printf("아직 대상자가 없습니다. 기다려주십시요\n");
		enqueue(q, e);
	}
	else
		printf("커플이 탄생했습니다! %s과 %s\n", e.name, dequeue(op).name);
}
int main(void)
{
	char answer;
	QueueType man;
	QueueType woman;
	char n[MAX_STRING];
	char g;
	element e;

	init(&man);
	init(&woman);

	printf("미팅 주선 프로그램입니다.\n");

	do
	{
		printf("i(nsert, 고객입력), c(heck, 대기자 체크), q(uit): ");
		scanf("%c", &answer);

		switch (answer) {
		case 'i' :
			printf("이름을 입력: ");
			scanf("%s", n);
			getchar();
			printf("성별을 입력(m or f): ");
			scanf("%c", &g);
			
			strcpy(e.name, n);

			if (g == 'm')
				checkCouple(&man, &woman, e);
			else
				checkCouple(&woman, &man, e);
			break;
		case 'c' :
			printf("남성 대기자 ");
			print_queue(&man);
			printf("여성 대기자 ");
			print_queue(&woman);
			break;
		}
		getchar();
	} while (answer != 'q');
}