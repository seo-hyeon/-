#include <stdio.h>

typedef struct ListNode {
	int number;
	struct ListNode *link;
} ListNode;

void displayList1(ListNode *head)
{
	ListNode *temp = head;

	for (temp = head; temp != NULL; temp = temp->link)
		printf("%d -> ", temp->number);
}

void displayList2(ListNode *head)
{
	if (head == NULL)
		return;
	else
	{
		printf("%d -> ", head->number);
		displayList2(head->link);
	}

}

int main(void)
{
	ListNode *head, *newNode, *temp;
	
	newNode = (ListNode *)malloc(sizeof(ListNode));
	newNode->number = 10;
	newNode->link = NULL;
	head = newNode;

	newNode = (ListNode *)malloc(sizeof(ListNode));
	newNode->number = 20;
	newNode->link = NULL;
	head->link = newNode;

	newNode = (ListNode *)malloc(sizeof(ListNode));
	newNode->number = 30;
	newNode->link = NULL;
	head->link->link = newNode;

	newNode = (ListNode *)malloc(sizeof(ListNode));
	newNode->number = 44;
	newNode->link = NULL;
	temp = (ListNode *)malloc(sizeof(ListNode));
	head->link->link->link = temp;
	temp->number = newNode->number;
	temp->link = newNode->link;

	newNode = (ListNode *)malloc(sizeof(ListNode));
	newNode->number = 1;
	newNode->link = NULL;
	temp = head;
	head = newNode;
	head->link = temp;

	displayList1(head);
	printf("\n");
	displayList2(head);
	printf("\n");
}