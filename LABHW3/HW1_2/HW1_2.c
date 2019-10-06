#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode *link;
} ListNode;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_next(ListNode * head, ListNode *pre, element value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

ListNode* insert_first(ListNode *head, int value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

ListNode* insert_last(ListNode *head, int value)
{
	ListNode *temp = head;
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = NULL;

	if (temp == NULL)
		head = p;
	else
	{
		while (temp->link != NULL)
			temp = temp->link;
		
		temp->link = p;
	}

	return head;
}

ListNode* delete_next(ListNode *head, ListNode *pre)
{
	ListNode *removed;
	removed = pre->link;
	pre->link = removed->link; //pre->link = pre->link->link�� ����
	free(remove);
	
	return head;
}

ListNode* delete_first(ListNode *head)
{
	ListNode *removed;

	if (head == NULL)
		error("������ �׸��� ����"); //head�� NULL�̾ ������ ���� �ʴ´�.
	else
	{
		removed = head;
		head = head->link; //head = remove->link�� ����

		free(removed);
	}

	return head;
}

ListNode* delete_last(ListNode *head)
{
	ListNode *temp = head;
	ListNode *prevTemp;
	ListNode *removed;

	if (head == NULL)
		error("������ �и��� ����");

	if (head->link == NULL)
	{
		free(temp);
		return NULL;
	}

	while (temp->link)
	{
		prevTemp = temp;
		temp = temp->link;
	}
	prevTemp->link = NULL;
	free(temp);

	return head;
}

void print_list(ListNode *head)
{
	ListNode *p;

	for (p = head; p != NULL; p= p->link)
		printf("%d->", p->data);
	printf("NULL\n");
}

int is_in_list(ListNode *head, element x)
{
	ListNode *p;
	p = head;

	while (p != NULL)
	{
		if (p->data == x)
			return 1;
		
		p = p->link;
	}

	return 0;
}

int get_length(ListNode *head)
{
	ListNode *p;
	int i = 0;
	p = head;

	while (p != NULL)
	{
		p = p->link;
		i++;
	}

	return i;
}

int get_total(ListNode *head)
{
	ListNode *p;
	int sum = 0;
	p = head;

	while (p != NULL)
	{
		sum += p->data;
		p = p->link;
	}

	return sum;
}

element get_entry(ListNode *head, int pos)
{
	ListNode *p;
	int i;
	p = head;

	for (i = 0; i < pos; i++, p = p->link);

	return p->data;
}

ListNode* insert_pos(ListNode *head, int pos, element value)
{
	ListNode *temp;
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	int i;

	temp = head;
	p->data = value;

	for (i = 0; i < pos -1; i++, temp = temp->link);
	
	p->link = temp->link;
	temp->link = p;

	return head;
}

ListNode* delete_pos(ListNode *head, int pos)
{
	ListNode *temp;
	ListNode *remove;
	int i;

	temp = head;

	for (i = 0; i < pos -1; i++, temp = temp->link);

	remove = temp->link;
	temp->link = remove->link;
	free(remove);

	return head;
}

ListNode* reverse(ListNode *head)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	ListNode *prevTemp = head->link;
	ListNode *temp = head;
	p = temp;

	while (prevTemp->link != NULL)
	{
		p = prevTemp->link;

		if (temp == head)
			temp->link = NULL;

		prevTemp->link = temp;
		temp = prevTemp;
		prevTemp = p;
	}
	prevTemp->link = temp;
	
	return prevTemp;
}

ListNode* concat(ListNode *head1, ListNode *head2)
{
	ListNode *p;

	if (head1 == NULL)
		return head2;
	else if(head2 == NULL)
		return head1;
	else
	{
		p = head1;

		while (p->link != NULL)
			p = p->link;

		p->link = head2;

		return head1;
	}
}
int main(void)
{
	ListNode *list1 = NULL, *list2 = NULL, *list3;

	list1 = insert_first(list1, 10);
	list1 = insert_first(list1, 20);
	list1 = insert_first(list1, 30);
	printf("list1 = ");
	print_list(list1);

	list1 = delete_first(list1);
	printf("list1 = ");
	print_list(list1);

	list2 = insert_first(list2, 11);
	list2 = insert_last(list2, 22);
	list2 = insert_last(list2, 33);
	list2 = insert_last(list2, 44);
	printf("list2 = ");
	print_list(list2);

	list2 = delete_last(list2);
	printf("list2 = ");
	print_list(list2);

	list3 = reverse(list2);
	printf("list3 = ");
	print_list(list3);

	list1 = concat(list1, list3);
	printf("list1 = ");
	print_list(list1);

	printf("\n--------------------------\n");
	printf("List1 �ȿ� 10�� ����: %d\n", is_in_list(list1, 10));
	printf("List1 �ȿ� 1�� ����: %d\n", is_in_list(list1, 1));
	printf("List1�� ����: %d\n", get_length(list1));
	printf("List1�� �� ��: %d\n", get_total(list1));
	printf("List1�� '1'��ġ�� �ִ� ��� ��ȯ: %d\n", get_entry(list1, 1));
	printf("List1�� '2'��ġ�� '1'�� ���� ��� �߰�\n");
	list1 = insert_pos(list1, 2, 1);
	print_list(list1);
	printf("List1�� '2'��ġ�� ��� ����\n");
	list1 = delete_pos(list1, 2);
	print_list(list1);
}