#include <stdio.h>

#define MAX_STACK_SIZE 100
#define MAX_STRING 100
typedef char element;
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

element peek(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->stack[s->top];
}

int palindrome(char str[])
{
	StackType s;
	int i;

	init(&s);

	for (i = 0; str[i] != '\0'; i++)
		push(&s, str[i]);

	for (i = 0; str[i] != '\0'; i++)
		if (str[i] != pop(&s))
			return 0;

	return 1;
}
void main()
{
	char word[MAX_STRING];

	printf("Enter a word to check palindrome: ");
	scanf("%s", word);

	if (palindrome(word))
		printf("palindrome �Դϴ�.\n");
	else
		printf("palindrome�� �ƴմϴ�.\n");
}

