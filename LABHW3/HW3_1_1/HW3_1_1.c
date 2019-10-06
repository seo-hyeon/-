#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 3 //3���� ����
#define MAX_STRING 100 // �߰�

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
// �ʱ�ȭ �Լ�
void init(QueueType *q)
{
	q->front = q->rear = 0;
}
// ���� ���� ���� �Լ�
int is_empty(QueueType *q)
{
	return (q->front == q->rear);
}
// ��ȭ ���� ���� �Լ�
int is_full(QueueType *q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
// ���� �Լ�
void enqueue(QueueType *q, element item)
{
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}
// ���� �Լ�
element dequeue(QueueType *q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}
// ���� �Լ�
element peek(QueueType *q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	return q->queue[(q->front + 1) % MAX_QUEUE_SIZE];
}

int get_count(QueueType *q)
{
	return q->rear - q->front - 1;
}

void print_queue(QueueType *q)
{
	int i;
	printf("%d��: ", get_count(q) + 1);

	for (i = q->front + 1; i <= q->rear; i++)
		printf("%s ", q->queue[i].name);
	printf("\n");
}

void checkCouple(QueueType *q, QueueType *op, element e)
{
	if (is_empty(op) && is_full(q))
		printf("���� ����ڰ� �����ϴ�. ����ڰ� ��á���� ���ȸ�� �̿�\n");
	else if (is_empty(op))
	{
		printf("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�\n");
		enqueue(q, e);
	}
	else
		printf("Ŀ���� ź���߽��ϴ�! %s�� %s\n", e.name, dequeue(op).name);
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

	printf("���� �ּ� ���α׷��Դϴ�.\n");

	do
	{
		printf("i(nsert, ���Է�), c(heck, ����� üũ), q(uit): ");
		scanf("%c", &answer);

		switch (answer) {
		case 'i' :
			printf("�̸��� �Է�: ");
			scanf("%s", n);
			getchar();
			printf("������ �Է�(m or f): ");
			scanf("%c", &g);
			
			strcpy(e.name, n);

			if (g == 'm')
				checkCouple(&man, &woman, e);
			else
				checkCouple(&woman, &man, e);
			break;
		case 'c' :
			printf("���� ����� ");
			print_queue(&man);
			printf("���� ����� ");
			print_queue(&woman);
			break;
		}
		getchar();
	} while (answer != 'q');
}