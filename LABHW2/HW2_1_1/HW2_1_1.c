#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 3

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// ���� �ʱ�ȭ �Լ�
void init_stack(StackType *s)
{
	s->top = -1;
}

// ���� ���� ���� �Լ�
int is_empty(StackType *s)
{
	return (s->top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full(StackType *s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

void stack_print(StackType *s)
{
	int i;

	if (is_empty(s))
		printf("<empty>\n");
	else
	{
		for (i = s->top; i >= 0; i--)
		{
			printf("%d", s->data[i]);

			if (i == s->top)
				printf(" <- top");

			printf("\n");
		}
	}

	printf("--\n");
}

// �����Լ�
void push(StackType *s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		//return;
	}
	else s->data[++(s->top)] = item;

	stack_print(s);
}
// �����Լ�
element pop(StackType *s)
{
	int num;

	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		stack_print(s);
		exit(1);
	}
	else
	{
		num = s->data[(s->top)--];
		stack_print(s);
		return num;
	}
}
// ��ũ�Լ�
element peek(StackType *s)
{
	int num;

	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		stack_print(s);
		exit(1);
	}
	else
	{
		num = s->data[s->top];
		stack_print(s);
		return num;
	}
}


int main(void)
{
	StackType s;

	init_stack(&s);
	stack_print(&s);
	push(&s, 10);
	push(&s, 20);
	push(&s, 30);
	push(&s, 40);
	pop(&s);
	push(&s, 50);
	pop(&s);
	pop(&s);
	pop(&s);
}