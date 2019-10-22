#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef int element;
typedef struct TreeNode {
	element data;
	struct TreeNode *left, *right;
} TreeNode;
// key�� ���� Ž�� Ʈ�� root�� �����Ѵ�. 
// key�� �̹� root�ȿ� ������ ���Ե��� �ʴ´�.

TreeNode *insertNode(TreeNode *root, element key) // �״�� �д�. ���� ����� ���� �Լ�
{
	TreeNode *p, *t; // p�� �θ���, t�� ������ 
	TreeNode *n;	    // n�� ���ο� ���

	t = root;
	p = NULL;

	// Ž���� ���� ����, �ݺ��� �̿��ؼ� search(���� search�Լ� ����)
	while (t != NULL) { // �����尡 NULL�� �ɶ�����
						//if( key == t->key ) return root;
		p = t; // �����带 �θ���� �ϰ�
			   // �����带 ����
		if (key <= t->data)
			t = t->left;
		else
			t = t->right;
	}
	// key�� Ʈ�� �ȿ� �����Ƿ� ���� ����
	n = (TreeNode *)malloc(sizeof(TreeNode));
	if (n == NULL) exit(1);
	// ������ ����
	n->data = key;
	n->left = n->right = NULL;

	// �θ� ���� ��ũ ����
	if (p != NULL)
		if (key <= p->data)
			p->left = n;
		else
			p->right = n;
	else // ���ʿ� Ʈ���� ����־�����
		root = n;

	return root;
}

void inorder(TreeNode *root) {
	if (root) {
		inorder(root->left);	// ���ʼ���Ʈ�� ��ȸ
		printf("%d ", root->data); 	// ��� �湮
		inorder(root->right);	// �����ʼ���Ʈ�� ��ȸ
	}
}
// ���� ��ȸ
void preorder(TreeNode *root) {
	if (root) {
		printf("%d ", root->data); 	// ��� �湮
		preorder(root->left);	// ���ʼ���Ʈ�� ��ȸ
		preorder(root->right);	// �����ʼ���Ʈ�� ��ȸ
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
		// �ڵ� �ۼ�
		if (root->data == oldKey)
			root->data = newKey;

		replaceKeyValue(root->left, oldKey, newKey);
		replaceKeyValue(root->right, oldKey, newKey);
	}
}

int main(void) // �������� ����
{
	int n;
	int oldKey, newKey;

	TreeNode *root = NULL;

	// (A) �Էºκ�
	scanf("%d", &n);
	while (n != -1) {
		root = insertNode(root, n);
		scanf("%d", &n);
	}

	//printCheck(root); Ʈ����� üũ�� ����. ���ν��� �ø����� �ּ����� �����
	scanf("%d", &oldKey);
	scanf("%d", &newKey);
	replaceKeyValue(root, oldKey, newKey);
	printCheck(root);
}