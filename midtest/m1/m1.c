#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode *link;
} ListNode;

ListNode *insert_last(ListNode *head, element data)
{
	ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));
	new_node->data = data;
	if (head == NULL) {
		head = new_node;
		new_node->link = new_node;
	}
	else {
		new_node->link = head->link;
		head->link = new_node;
		head = new_node;
	}
	return head;
}

void display(ListNode *head)
{
	ListNode *p, *front;
	if (head == NULL) { printf("|"); return; }

	front = head->link;
	p = front;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != front);
	printf("|\n");
}

void increaseOneTwoEtc(ListNode *head)
{
	ListNode *p;
	int i;

	if (head == NULL)
		return;

	p = head->link;

	for (i = 1; p != head; i++)
	{
		p->data += i;
		p = p->link;
	}

	head->data += i;
}

int main(void)
{
	ListNode *list = NULL;
	int num;

	scanf("%d", &num);
	while (num != -1) {
		list = insert_last(list, num);
		scanf("%d", &num);
	}
	//display(list); 
	increaseOneTwoEtc(list);
	display(list);
}