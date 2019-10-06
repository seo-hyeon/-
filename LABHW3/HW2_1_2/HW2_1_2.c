#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 3
#define MAX_STRING 100

typedef struct {
	int num;
	char numString[MAX_STRING];
} element;

typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
} StackType;

void init(StackType *s) // ���� �ʱ�ȭ �Լ�
{
	s->top = -1;
}
int is_empty(StackType *s) // ���� ���� ���� �Լ�
{
	return (s->top == -1);
}
int is_full(StackType *s) // ��ȭ ���� ���� �Լ�
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
void push(StackType *s, element item) // �����Լ�
{
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->stack[++(s->top)] = item;
}
element pop(StackType *s) // �����Լ�
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->stack[(s->top)--];
}
element peek(StackType *s) // ��ũ�Լ�
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n"); exit(1);
	}
	else return s->stack[s->top];
}

void stack_print(StackType *s) // �����κ�:  ���� ���
{
	int i;

	if (is_empty(s))
		printf("<empty>\n");
	else
	{
		for (i = s->top; i >= 0; i--)
		{
			printf("[%d, %s]", (s->stack[i]).num, (s->stack[i]).numString);

			if (i == s->top)
				printf(" <- top");

			printf("\n");
		}
	}

	printf("--\n");
}

int main(void)
{
	StackType s;
	element e;

	init(&s);
	stack_print(&s);

	e.num = 10;
	strcpy(e.numString, "ten");
	push(&s, e);
	stack_print(&s);

	e.num = 20;
	strcpy(e.numString, "twenty");
	push(&s, e);
	stack_print(&s);

	e.num = 30;
	strcpy(e.numString, "thirty");
	push(&s, e);
	stack_print(&s);

	e.num = 40;
	strcpy(e.numString, "forty");
	push(&s, e);
	stack_print(&s);

	pop(&s);
	stack_print(&s);

	e.num = 50;
	strcpy(e.numString, "fifty");
	push(&s, e);
	stack_print(&s);

	pop(&s);
	stack_print(&s);

	pop(&s);
	stack_print(&s);

	pop(&s);
	stack_print(&s);
}