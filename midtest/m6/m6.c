#include <stdio.h>
#include <stdlib.h>

typedef int element;	// 요소의 타입
typedef struct QueueNode {	// 큐의 노드의 타입 
	element data;
	struct QueueNode *link;
} QueueNode;

typedef struct {		// 큐 ADT 구현
	QueueNode *front, *rear;
} LinkedQueueType;

// 큐 초기화 함수
void init_queue(LinkedQueueType *q)
{
	q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(LinkedQueueType *q)
{
	return (q->front == NULL);
}
// 포화 상태 검출 함수
int is_full(LinkedQueueType *q)
{
	return 0;
}
// 삽입 함수
void enqueue(LinkedQueueType *q, element data)
{
	QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
	temp->data = data; 		// 데이터 저장
	temp->link = NULL; 		// 링크 필드를 NULL
	if (is_empty(q)) { 		// 큐가 공백이면
		q->front = temp;
		q->rear = temp;
	}
	else { 		// 큐가 공백이 아니면
		q->rear->link = temp;  // 순서가 중요
		q->rear = temp;
	}
}
// 삭제 함수
element dequeue(LinkedQueueType *q)
{
	QueueNode *temp = q->front;
	element data;
	if (is_empty(q)) {		// 공백상태
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		data = temp->data; 		// 데이터를 꺼낸다.
		q->front = q->front->link; // front를 다음노드를 가리키도록 한다.
		if (q->front == NULL) 	// 공백 상태
			q->rear = NULL;
		free(temp); 			// 동적메모리 해제
		return data; 			// 데이터 반환
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
	if (is_empty(q)) {		// 공백상태
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		return temp->data; 			// 데이터 반환
	}
}

int main(void)
{
	element item;
	element data;
	int sum = 0;
	int group = 0; // 큐활용-2를 위해 필요
	LinkedQueueType q;

	init_queue(&q);

	// -1가 나올때까지 읽어서 큐에 넣는다
	scanf("%d", &data);
	while (data != -1) {
		enqueue(&q, data);
		scanf("%d", &data);
	}

	// 코드 추가
	sum += peek(&q);

	while (sum <= 100)
	{
		printf("%d ", dequeue(&q));

		if (is_empty(&q) == 1)
			break;

		sum += peek(&q);
	}

	printf("\n");
	print_queue(&q); // 큐 출력

	return 0;
}