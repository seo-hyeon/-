#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DlistNode {
	element data;
	struct DlistNode *llink;
	struct DlistNode *rlink;
} DlistNode;

// 이중 연결 리스트를 초기화
void init(DlistNode *phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}

void display2(DlistNode *phead)
{
	DlistNode *p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("%d->", p->data);
	}
	printf("|\n");
}
// 노드 new_node를 노드 before의 오른쪽에 삽입한다.

void dinsert_node(DlistNode *before, element data)
{
	DlistNode *new_node;
	new_node = (DlistNode *)malloc(sizeof(DlistNode));
	new_node->data = data;
	new_node->llink = NULL;
	new_node->rlink = NULL;

	new_node->llink = before;
	new_node->rlink = before->rlink;
	before->rlink->llink = new_node;
	before->rlink = new_node;
}

void dremoveNodeByKey(DlistNode *head_node, element key) // 추가
{
	DlistNode *p, *d;
	if (head_node == NULL) return; // 삭제할 노드가 없으면 그냥 끝
	
								   // 코드 작성

	p = head_node->llink;

	while (p != head_node)
	{
		if (p->data == key)
		{
			d = p;

			p->llink->rlink = p->rlink;
			p->rlink->llink = p->llink;

			p = p->llink;
			free(d);
		}
		else
			p = p->llink;
	}
}

int main(void) // 변경하지 마라
{
	DlistNode head_node;
	int n, key;
	init(&head_node);
	scanf("%d", &n);
	while (n != -1) {
		dinsert_node(head_node.llink, n);
		scanf("%d", &n);
	}

	//display2(&head_node);
	scanf("%d", &key);
	dremoveNodeByKey(&head_node, key);
	display2(&head_node);
}