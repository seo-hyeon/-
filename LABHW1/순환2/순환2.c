#include <stdio.h>
void print_fact_exp(int n)
{
	if (n == 1 || n == 0)
	{
		printf("1");
		return;
	}
	else
	{
		printf("%d * ", n);
		print_fact_exp(n - 1);
	}
}
int main(void)
{
	int n;
	printf("Enter a number:");
	scanf("%d", &n);

	printf("%d! = ", n);
	print_fact_exp(n);
	printf("\n");
}