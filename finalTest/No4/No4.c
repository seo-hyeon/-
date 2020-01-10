#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
typedef int element;
typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
} StackType;

// 스택 초기화 함수
void init(StackType *s)
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
// 삽입함수
void push(StackType *s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->stack[++(s->top)] = item;
}
// 삭제함수
element pop(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->stack[(s->top)--];
}
// 피크함수
element peek(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
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

	// 필요한 변수 추가

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
	// 필요한 코드 추가
	printf("%d\n", result);
}