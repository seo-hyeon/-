#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 3

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType *s)
{
	s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType *s)
{
	return (s->top == -1);
}
// 포화 상태 검출 함수
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

// 삽입함수
void push(StackType *s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		//return;
	}
	else s->data[++(s->top)] = item;

	stack_print(s);
}
// 삭제함수
element pop(StackType *s)
{
	int num;

	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
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
// 피크함수
element peek(StackType *s)
{
	int num;

	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
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