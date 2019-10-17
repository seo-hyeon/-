#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define TRUE 1
#define FALSE 0
#define MAX_TREE_SIZE 20

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
}TreeNode;

TreeNode n1 = { 15, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 15, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode *root = &n6;

TreeNode m1 = { 15, NULL, NULL };
TreeNode m2 = { 4, &n1, NULL };
TreeNode m3 = { 16, NULL, NULL };
TreeNode m7 = { 28, NULL, NULL };
TreeNode m4 = { 25, NULL, NULL };
TreeNode m5 = { 15, &m3, &m4 };
TreeNode m6 = { 15, &m2, &m5 };
TreeNode *root2 = &m6;

int get_nonleaf_count(TreeNode *t) 
{
	int left, right;

	if (t != NULL)
	{
		if (t->left == NULL && t->right == NULL)
			return 0;

		left = get_nonleaf_count(t->left);
		right = get_nonleaf_count(t->right);

		return left + right + 1;
	}

	return 0;

	/*	
	if (단말노드이면 node->left == NULL && node->right == NULL)
		return 0;

	L = get_nonleaf_count(t->left);
	R = get_nonleaf_count(t->right);
	
	return (1 + L + R)
	*/
}

int equal(TreeNode *t1, TreeNode *t2)
{
	if (t1 && t2)
	{
		if (t1->data != t2->data || equal(t1->left, t1->left) == FALSE || equal(t1->right, t2->right) == FALSE)
			return FALSE;
	}

	if (t1 == NULL && t2 != NULL)
		return FALSE;
	if (t1 != NULL && t2 == NULL)
		return FALSE;

	return TRUE;
}

int get_oneleaf_count(TreeNode *node)
{
	int left, right;

	if (node)
	{
		left = get_oneleaf_count(node->left);
		right = get_oneleaf_count(node->right);

		if (node->left == NULL && node->right != NULL)
			return left + right + 1;
		if (node->left != NULL && node->right == NULL)
			return left + right + 1;

		return left + right;
	}

	return 0;

}

int get_twoleaf_count(TreeNode *node)
{
	int left, right;

	if (node)
	{
		left = get_twoleaf_count(node->left);
		right = get_twoleaf_count(node->right);

		if (node->left != NULL && node->right != NULL)
			return left + right + 1;

		return left + right;
	}

	return 0;
}

int get_max(TreeNode *node)
{
	int left, right;
	int result = -1;

	if (node)
	{
		result = node->data;

		left = get_max(node->left);
		right = get_max(node->right);

		if (result < left)
			result = left;

		if (result < right)
			result = right;
	}

	return result;
}

int get_min(TreeNode *node)
{
	int left, right;
	int result = 1000;

	if (node)
	{
		result = node->data;

		left = get_min(node->left);
		right = get_min(node->right);

		if (result > left)
			result = left;

		if (result > right)
			result = right;
	}

	return result;
}

void node_increase(TreeNode *node)
{
	if (node)
	{
		node->data = node->data + 1;
		node_increase(node->left);
		node_increase(node->right);
	}
}

void preorder(TreeNode *root)
{
	if (root)
	{
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
/*
int search(TreeNode *node, int key, TreeNode * result[])
{
	int left, right, i;
	TreeNode *n;

	if (node)
	{
		left = search(node->left, key, result);
		right = search(node->right, key, result);

		if (node->data == key)
		{
			for (i = 0; i < MAX_TREE_SIZE; i++)
				if (result)
				{
					result[i] = node;
					break;
				}

			return left + right + 1;
		}
		return left + right;
	}

	return 0;
}
*/
TreeNode *copy(TreeNode *node)
{
	if (node)
	{
		TreeNode *n = (TreeNode *)malloc(sizeof(TreeNode));

		n->data = node->data;
		n->left = copy(node->left);
		n->right = copy(node->right);

		return n;
	}

	return NULL;
}

int main(void)
{
	TreeNode *result[MAX_TREE_SIZE];
	TreeNode *clone;
	int i, num;
	
	
	printf("트리 root중 비단말노드의 개수는 %d.\n", get_nonleaf_count(root));
	printf("트리 root2중 비단말노드의 개수는 %d.\n", get_nonleaf_count(root2));

	printf("트리 root중 자식이 하나만 있는 노드의 개수는 %d.\n", get_oneleaf_count(root));
	printf("트리 root2중 자식이 하나만 있는 노드의 개수는 %d.\n", get_oneleaf_count(root2));

	printf("트리 root중 자식이 둘이 있는 노드의 개수는 %d.\n", get_twoleaf_count(root));
	printf("트리 root2중 자식이 둘이 있는 노드의 개수는 %d.\n", get_twoleaf_count(root2));

	printf("트리 root에서 가장 큰 수는 %d.\n", get_max(root));
	printf("트리 root2에서 가장 큰 수는 %d.\n", get_max(root2));

	printf("트리 root에서 가장 작은 수는 %d.\n", get_min(root));
	printf("트리 root2에서 가장 작은 수는 %d.\n", get_min(root2));
	/*
	num = search(root, 15, result);
	for (i = 0; i < num; i++)
		printf("(0x%p, %d), ", result[i], result[i]->data);
	printf("\n");
	*/
	node_increase(root);
	preorder(root);
	printf("\n");

	printf("%s\n", equal(root, root) ? "같다" : "다르다");
	printf("%s\n", equal(root2, root2) ? "같다" : "다르다");
	printf("%s\n", equal(root, root2) ? "같다" : "다르다");

	clone = copy(root);
	preorder(root);
	printf("\n");
	preorder(clone);
	printf("\n");
}