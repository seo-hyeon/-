#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef int element;
typedef struct TreeNode {
	element data;
	struct TreeNode *left, *right;
} TreeNode;
// key를 이진 탐색 트리 root에 삽입한다. 
// key가 이미 root안에 있으면 삽입되지 않는다.

TreeNode *insertNode(TreeNode *root, element key) // 그대로 둔다. 아직 배우지 않은 함수
{
	TreeNode *p, *t; // p는 부모노드, t는 현재노드 
	TreeNode *n;	    // n은 새로운 노드

	t = root;
	p = NULL;

	// 탐색을 먼저 수행, 반복을 이용해서 search(위의 search함수 참조)
	while (t != NULL) { // 현재노드가 NULL이 될때까지
						//if( key == t->key ) return root;
		p = t; // 현재노드를 부모노드로 하고
			   // 현재노드를 전진
		if (key <= t->data)
			t = t->left;
		else
			t = t->right;
	}
	// key가 트리 안에 없으므로 삽입 가능
	n = (TreeNode *)malloc(sizeof(TreeNode));
	if (n == NULL) exit(1);
	// 데이터 복사
	n->data = key;
	n->left = n->right = NULL;

	// 부모 노드와 링크 연결
	if (p != NULL)
		if (key <= p->data)
			p->left = n;
		else
			p->right = n;
	else // 애초에 트리가 비어있었으면
		root = n;

	return root;
}

void inorder(TreeNode *root) {
	if (root) {
		inorder(root->left);	// 왼쪽서브트리 순회
		printf("%d ", root->data); 	// 노드 방문
		inorder(root->right);	// 오른쪽서브트리 순회
	}
}
// 전위 순회
void preorder(TreeNode *root) {
	if (root) {
		printf("%d ", root->data); 	// 노드 방문
		preorder(root->left);	// 왼쪽서브트리 순회
		preorder(root->right);	// 오른쪽서브트리 순회
	}
}
void printCheck(TreeNode *node)
{
	preorder(node); printf("\n");
	inorder(node); printf("\n");
}

void replaceKeyValue(TreeNode *root, int oldKey, int newKey)
{
	if (root == NULL) return;
	else {
		// 코드 작성
		if (root->data == oldKey)
			root->data = newKey;

		replaceKeyValue(root->left, oldKey, newKey);
		replaceKeyValue(root->right, oldKey, newKey);
	}
}

int main(void) // 변경하지 마라
{
	int n;
	int oldKey, newKey;

	TreeNode *root = NULL;

	// (A) 입력부분
	scanf("%d", &n);
	while (n != -1) {
		root = insertNode(root, n);
		scanf("%d", &n);
	}

	//printCheck(root); 트리모양 체크를 위해. 프로스쿨에 올릴때는 주석으로 만든다
	scanf("%d", &oldKey);
	scanf("%d", &newKey);
	replaceKeyValue(root, oldKey, newKey);
	printCheck(root);
}