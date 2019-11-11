#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define MAX_STRING 100

typedef struct {
	int id;
	char name[MAX_STRING];
	char tel[MAX_STRING];
	char dept[MAX_STRING];
} element;
typedef struct TreeNode {
	element data;
	struct TreeNode *left, *right;
} TreeNode;

TreeNode * search(TreeNode * node, int key)  // ���� ���ľ�
{
	TreeNode* p;

	if (node == NULL)
		return NULL;
	else if (node->data.id == key)
		return node;
	else
	{
		p = search(node->left, key);
		if (p != NULL)
			return p;

		p = search(node->right, key); 
		if (p != NULL)
			return p;

		return NULL;
	}
}

TreeNode * new_node(element data)
{
	TreeNode * new_node;

	new_node = (TreeNode * )malloc(sizeof(TreeNode));
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->data = data;
}

TreeNode * insert_node(TreeNode * node, element data) // ���� ���ľ�
{
	if (node == NULL)
	{
		node = new_node(data);
		return node;
	}
	else
	{
		if (data.id > node->data.id)
			node->right = insert_node(node->right, data);
		else
			node->left = insert_node(node->left, data);

		return node;
	}
	/*TreeNode * root = node;

	if (node == NULL)
	{
		node = new_node(data);
		return node;
	}

	while (1) 
	{
		if (node->data.id > data.id)
		{
			if (node->left == NULL)
				break;

			node = node->left;
		}
		else
		{
			if (node->right == NULL)
				break;

			node = node->right;
		}
	}

	if (node->data.id > data.id)
		node->left = new_node(data);
	else
		node->right = new_node(data);

	return root;*/
}

TreeNode * min_value_node(TreeNode * node) // �״��
{
	TreeNode * current = node;

	// �� ���� �ܸ� ��带 ã���� ������
	while (current->left != NULL)
		current = current->left;

	return current;
}

TreeNode * delete_node(TreeNode * root, int key) // ���� ���ľ�
{	

	/*if (root == NULL) return root;


	if (key < root->data.id)
		root->left = delete_node(root->left, key);
	if (key > root->data.id)
		root->right = delete_node(root->right, key);
	else {
		if (root->left == NULL) {
			TreeNode *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode *temp = root->left;
			free(root);
			return temp;
		}
		TreeNode *temp = min_value_node(root->right);
		root->data = temp->data;
		root->right = delete_node(root->right, temp->data.id);
	}
	return root;

	/*
	TreeNode * del;
	TreeNode * node = root;

	while (1)
	{
		if (node->left->data.id == key)
		{
			del = node->left;

			node->left = del->left;
			break;
		}
		else if (node->right->data.id == key)
		{
			del = node->right;

			node->right = del->right;
			break;
		}
		else
		{
			if (node->data.id > key)
				node = node->left;
			else
				node = node->right;
		}
	}

	if (del->left == NULL && del->right == NULL)
		free(del);
	return root;*/
}

//�� �л� ���� ���
void print_data(element * e)
{
	printf("-----------------------------------\n");
	printf("�й�: %d\n", e->id);
	printf("�̸�: %s\n", e->name);
	printf("��ȭ��ȣ: %s\n", e->tel);
	printf("�а�: %s\n", e->dept);
}

// ���� ��ȸ
void inorder(TreeNode * root)
{
	if (root)
	{
		inorder(root->left);
		print_data(&root->data);
		inorder(root->right);
	}
}

int get_node_count(TreeNode *node)
{
	int count = 0;
	if (node != NULL)
		count = 1 + get_node_count(node->left) + get_node_count(node->right);
	return count;
}
int main(void)
{
	TreeNode *root = NULL;
	TreeNode *node;
	element data;
	char choice;
	int id;
	char name[MAX_STRING];
	char tel[MAX_STRING];
	char dept[MAX_STRING];

	printf("Enter i(nsert), d(elete), s(earch), p(rint), c(ount), q(uit):");
	scanf("%c", &choice);


	while (choice != 'q') {
		switch (choice) {
		case 'i':
			printf("�й� �Է�:");
			scanf("%d", &id);
			printf("�̸� �Է�:");
			scanf("%s", name);;
			printf("��ȭ��ȣ �Է�:");
			scanf("%s", tel);;
			printf("�а� �Է�:");
			scanf("%s", dept);;

			data.id = id;
			strcpy(data.name, name);
			strcpy(data.tel, tel);
			strcpy(data.dept, dept);

			root = insert_node(root, data);
			break;
		case 'p':
			printf("�л� ���� �й� �� ���\n");
			inorder(root);
			printf("\n");
			break;
		case 'd':
			printf("������ �й� �Է�:");
			scanf("%d", &id);
			root = delete_node(root, id);
			break;
		case 's':
			printf("Ž���� �й� �Է�:");
			scanf("%d", &id);

			node = search(root, id);
			if (node != NULL)
				print_data(&(node->data));
			else
				printf("id�� %d�� �л��� �����ϴ�.\n", id);
			break;

		case 'c':
			printf("���� ����� �л��� �� ���� %d\n", get_node_count(root));
			break;
		}

		while (getchar() != '\n'); // ���� ���

		printf("Enter i(nsert), d(elete), s(earch), p(rint), c(ount), q(uit):");
		scanf("%c", &choice);
	}
}

