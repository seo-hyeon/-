#include <stdio.h>
#include <stdlib.h>

typedef int element;	// ����� Ÿ��
typedef struct QueueNode {	// ť�� ����� Ÿ�� 
	element data;
	struct QueueNode *link;
} QueueNode;

typedef struct {		// ť ADT ����
	QueueNode *front, *rear;
} LinkedQueueType;

// ť �ʱ�ȭ �Լ�
void init_queue(LinkedQueueType *q)
{
	q->front = q->rear = 0;
}

// ���� ���� ���� �Լ�
int is_empty(LinkedQueueType *q)
{
	return (q->front == NULL);
}
// ��ȭ ���� ���� �Լ�
int is_full(LinkedQueueType *q)
{
	return 0;
}
// ���� �Լ�
void enqueue(LinkedQueueType *q, element data)
{
	QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
	temp->data = data; 		// ������ ����
	temp->link = NULL; 		// ��ũ �ʵ带 NULL
	if (is_empty(q)) { 		// ť�� �����̸�
		q->front = temp;
		q->rear = temp;
	}
	else { 		// ť�� ������ �ƴϸ�
		q->rear->link = temp;  // ������ �߿�
		q->rear = temp;
	}
}
// ���� �Լ�
element dequeue(LinkedQueueType *q)
{
	QueueNode *temp = q->front;
	element data;
	if (is_empty(q)) {		// �������
		fprintf(stderr, "������ �������\n");
		exit(1);
	}
	else {
		data = temp->data; 		// �����͸� ������.
		q->front = q->front->link; // front�� ������带 ����Ű���� �Ѵ�.
		if (q->front == NULL) 	// ���� ����
			q->rear = NULL;
		free(temp); 			// �����޸� ����
		return data; 			// ������ ��ȯ
	}
}
void print_queue(LinkedQueueType *q)
{
	QueueNode *p;
	for (p = q->front; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL\n");
}


element peek(LinkedQueueType *q)
{
	QueueNode *temp = q->front;
	element data;
	if (is_empty(q)) {		// �������
		fprintf(stderr, "������ �������\n");
		exit(1);
	}
	else {
		return temp->data; 			// ������ ��ȯ
	}

}

int main(void)
{
	element item;
	element data;
	int sum = 0;
	LinkedQueueType q;

	init_queue(&q);

	scanf("%d", &data);
	while (data != -1) {
		enqueue(&q, data);
		scanf("%d", &data);
	}

	// �ڵ� �ۼ�
	while (is_empty(&q) != 1)
	{
		if (peek(&q) > 100)
			dequeue(&q);
		else
		{
			if (sum + peek(&q) > 100)
			{
				printf("%d\n", sum);
				sum = 0;
			}

			sum += peek(&q);
			printf("%d ", dequeue(&q));
		}
	}

	printf("%d\n", sum);

	printf("end\n");
	return 0;
}