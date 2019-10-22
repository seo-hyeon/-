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
void printCheck(TreeNode *node) // Ʈ������� Ȯ���ϰ����ϴ�
{
	preorder(node); printf("\n");
	inorder(node); printf("\n");
}

int getKeyCount(TreeNode *node, int key)
{
	if (node == NULL) return 0;
	// �ڵ� ����

	if (node->data == key)
		return getKeyCount(node->left, key) + getKeyCount(node->right, key) + 1;

	return getKeyCount(node->left, key) + getKeyCount(node->right, key);
}
int main(void) // �������� ����
{
	int n;
	int key;

	TreeNode *root = NULL;

	// (A) �Էºκ�
	scanf("%d", &n);
	while (n != -1) {
		root = insertNode(root, n);
		scanf("%d", &n);
	}

	//printCheck(root); Ʈ����� üũ�� ����. ���ν��� �ø����� �ּ����� �����
	//printf("ã������ Ű �Է�(-1 for exit):");
	scanf("%d", &key);
	printf("%d\n", getKeyCount(root, key));
}