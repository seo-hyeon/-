#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {	// ���߿��� ��� Ÿ��
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;

// ���� ���� ����Ʈ�� �ʱ�ȭ
void init(DListNode* phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}

// ���� ���� ����Ʈ�� ��带 ���
void print_dlist(DListNode* phead)
{
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("<-| |%d| |-> ", p->data);
	}
	printf("\n");
}
// ���ο� �����͸� ��� before�� �����ʿ� �����Ѵ�.
void dinsert(DListNode *before, element data)
{
	DListNode *newnode = (DListNode *)malloc(sizeof(DListNode));
	
	newnode->data = data;
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}
// ��� removed�� �����Ѵ�.
void ddelete(DListNode* head, DListNode* removed)
{
	if (removed == head) return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

void print_reverse_dlist(DListNode *head)
{
	DListNode *p;

	for (p = head->llink; p != head; p = p->llink)
	{
		printf("<-| |%d| |-> ", p->data);
	}
	
	printf("\n");
}

DListNode *search(DListNode *head, element data)
{
	DListNode *find;

	for (find = head->rlink; find != head; find = find->rlink)
		if (find->data == data)
			return find;

	return head;
}
// ���� ���� ����Ʈ �׽�Ʈ ���α׷�
int main(void)
{
	DListNode* head = (DListNode *)malloc(sizeof(DListNode));
	init(head);
	printf("�߰� �ܰ�\n");
	for (int i = 0; i < 5; i++) {
		// ��� ����� �����ʿ� ����
		dinsert(head, i);
		print_dlist(head);
	}

	printf("\nreverse\n");
	print_reverse_dlist(head);

	printf("\nsearch 3:\n");
	print_dlist(search(head, 3));
	printf("search 6:\n");
	print_dlist(search(head, 6));

	printf("\n���� �ܰ�\n");
	for (int i = 0; i < 5; i++) {
		print_dlist(head);
		ddelete(head, head->rlink);
	}
	free(head);
	return 0;
}