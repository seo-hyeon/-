#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { 	// ��� Ÿ��
	element data;
	struct ListNode *link;
} ListNode;

// ����Ʈ�� �׸� ���
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
	
	printf("%d->����Ʈ�� ��\n", p->data); // ������ ��� ���
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
	return head;	// ����� ��� �����͸� ��ȯ�Ѵ�. 
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
	return head;	// ����� ��� �����͸� ��ȯ�Ѵ�. 
}

ListNode* delete_last(ListNode *head)
{
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	ListNode *remove = (ListNode *)malloc(sizeof(ListNode));

	if (head == NULL)
	{
		printf("����Ʈ�� ����־� ������ ����\n");
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
// ���� ���� ����Ʈ �׽�Ʈ ���α׷�
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
	printf("����: %d\n", get_size(head));

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
	printf("����: %d\n", get_size(head));

	return 0;
}