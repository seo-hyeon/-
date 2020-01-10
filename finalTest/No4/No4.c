#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
typedef int element;
typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
} StackType;

// ���� �ʱ�ȭ �Լ�
void init(StackType *s)
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
// �����Լ�
void push(StackType *s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->stack[++(s->top)] = item;
}
// �����Լ�
element pop(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->stack[(s->top)--];
}
// ��ũ�Լ�
element peek(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->stack[s->top];
}

void cal(StackType *s, char* num)
{
}
int main(void)
{
	char s[100];
	StackType stack;
	int result, i, j, num;

	// �ʿ��� ���� �߰�

	init(&stack);
	scanf("%s", s);

	for (j = 0; j * 3 < strlen(&s); j++)
	{
		num = 0;

		for (i = 0; i < 3 && (j * 3 + i)<strlen(&s); i++)
		{
			num *= 10;
			num = num + s[j * 3 + i] - '0';
		}
		printf("%d\n", num);
		push(&stack, num);
	}

	i = 0;
	result = 0;
	while (1)
	{
		if (is_empty(&stack)) {
			break;
		}

		if (i % 2 == 0)
			result += pop(&stack);
		else
			result -= pop(&stack);

		i++;
	}
	// �ʿ��� �ڵ� �߰�
	printf("%d\n", result);
}