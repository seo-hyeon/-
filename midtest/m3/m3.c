#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode *link;
} ListNode;

void display(ListNode *head)
{
	ListNode *p = head;
	while (p != NULL) {
		printf("%d->", p->data);
		p = p->link;
	}
	printf("\n");
}


ListNode *insert_last(ListNode *head, element data) // 배우지 않은 함수
{
	ListNode *p;
	ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));
	new_node->data = data;
	new_node->link = NULL;
	if (head == NULL) {   // 공백리스트인 경우
		head = new_node;
	}
	else {
		p = head;
		while (p->link != NULL)
			p = p->link;
		p->link = new_node;
	}
	return head;
}

ListNode *mergeOneByOne(ListNode *list1, ListNode *list2)
{
	ListNode *newList = NULL;
	ListNode *p1 = list1, *p2 = list2;

	// 코드 작성
	
	while (p1 != NULL & p2 != NULL)
	{
		newList = insert_last(newList, p1->data);
		newList = insert_last(newList, p2->data);

		p1 = p1->link;
		p2 = p2->link;
	}

	while (p1 != NULL)
	{
		insert_last(newList, p1->data);
		p1 = p1->link;
	}

	while (p2 != NULL)
	{
		insert_last(newList, p2->data);
		p2 = p2->link;
	}

	return newList;
}

int main(void)
{
	ListNode *list1 = NULL, *list2 = NULL;
	ListNode *list3;
	int n;

	scanf("%d", &n);
	while (n != -1) {
		list1 = insert_last(list1, n);
		scanf("%d", &n);
	}

	scanf("%d", &n);
	while (n != -1) {
		list2 = insert_last(list2, n);
		scanf("%d", &n);
	}

	list3 = mergeOneByOne(list1, list2);
	display(list1);
	display(list2);
	display(list3);
}