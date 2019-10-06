#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { 	// 노드 타입
	element data;
	struct ListNode *link;
} ListNode;

// 리스트의 항목 출력
void print_list(ListNode* head)
{
	ListNode* p;

	if (head == NULL) 
		return;

	p = head->link;

	while (p != head)
	{
		printf("%d->", p->data);
		p = p->link;
	}
	
	printf("%d->리스트의 끝\n", p->data); // 마지막 노드 출력
}

ListNode* insert_first(ListNode* head, element data)
{
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;	// (1)
		head->link = node;		// (2)
	}
	return head;	// 변경된 헤드 포인터를 반환한다. 
}

ListNode* insert_last(ListNode* head, element data)
{
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;	// (1)
		head->link = node;		// (2)
		head = node;		// (3)
	}
	return head;	// 변경된 헤드 포인터를 반환한다. 
}

ListNode* delete_last(ListNode *head)
{
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	ListNode *remove = (ListNode *)malloc(sizeof(ListNode));

	if (head == NULL)
	{
		printf("리스트가 비어있어 삭제를 못함\n");
		return NULL;
	}
	else if (head->link == head)
		return NULL;

	node = head->link;

	while (node->link != head)
		node = node->link;

	remove = head;
	node->link = head->link;
	head = node;

	free(remove);

	return head;
}

int get_size(ListNode *head)
{
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	int i;

	if (head == NULL)
		return 0;

	node = head->link;

	for (i = 1; node != head; i++)
		node = node->link;

	return i;
}

ListNode* search(ListNode *head, element data)
{
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	node = head->link;

	while (node != head)
	{
		if (node->data == data)
			return node;

		node = node->link;
	}

	return head;
}
// 원형 연결 리스트 테스트 프로그램
int main(void)
{
	ListNode *head = NULL;

	// list = 10->20->30->40
	head = insert_last(head, 10);
	print_list(head);
	head = insert_last(head, 20);
	print_list(head);
	head = insert_last(head, 30);
	print_list(head);
	head = insert_last(head, 40);
	print_list(head);
	printf("길이: %d\n", get_size(head));

	printf("%d %d\n", search(head, 20)->data, search(head, 40)->data);

	head = delete_last(head);
	print_list(head);
	head = delete_last(head);
	print_list(head);
	head = delete_last(head);
	print_list(head);
	head = delete_last(head);
	print_list(head);
	head = delete_last(head);
	printf("길이: %d\n", get_size(head));

	return 0;
}