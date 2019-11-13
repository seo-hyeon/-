#include <stdio.h>
typedef struct element{
	int freq[100];
}element;

int findSmall(element e, int size)
{
	int min = e.freq[0], i;

	for (i = 1; i < size; i++)
		if (min > e.freq[i])
			min = e.freq[i];

	return min;
}
int findSecondSmall(element e, int s, int size)
{
	int min = 1000, i, flag = 0;

	for (i = 0; i < size; i++)
	{
		if (e.freq[i] == s && flag == 0)
		{
			flag++;
			continue;
		}
		if (min > e.freq[i])
			min = e.freq[i];
	}

	return min;
}
void placeArray(element * e, int size, int n1, int n2, int sum)
{
	int i, flag = 0;

	for (i = 0; i < size - 1; i++)
	{
		if (e->freq[i] == n1 && flag == 0)
		{
			e->freq[i] = sum;

			if (n1 == n2)
				flag = 1;
		}
		if (e->freq[i] == n2)
		{
			if (e->freq[size - 1] == n1)
				e->freq[i] = sum;
			else
				e->freq[i] = e->freq[size - 1];
		}
	}
}
void print_huffman_code(element e, int size, int key, char result[])
{
	int n1, n2;
	char r[100];
	r[1] = '\0';

	if (size == 1)
	{
		printf("%s", result);
		return;
	}
	else
	{
		n1 = findSmall(e, size);
		n2 = findSecondSmall(e, n1, size);

		if (n1 == n2 && n1 == key)
		{
			if (result[0] == '\0')
				r[0] = '1';
			else
				r[0] = '0';

			strcat(r, result);
			result = r;
			key = n1 + n2;

		}
		else if (key == n2)
		{
			r[0] = '0';
			strcat(r, result);
			result = r;
			key = n1 + n2;
		}
		else if (key == n1)
		{
			r[0] = '1';
			strcat(r, result);
			result = r;
			key = n1 + n2;
		}

		placeArray(&e, size, n1, n2, n1 + n2);

		print_huffman_code(e, size - 1, key, result);
	}
}
int main(void)
{
	//int freq[] = { 15, 12, 8, 6, 4 };
	int freq[] = { 1, 10, 11, 14, 15, 35, 45, 1000 };
	int i, size = 8;
	char result[100];
	element e;

	for (i = 0; i < size; i++)
		e.freq[i] = freq[i];

	result[0] = '\0';
	for (i = 0; i < size; i++)
	{
		printf("%d: ", e.freq[i]);
		print_huffman_code(e, size, e.freq[i], result);
		printf("\n");

		result[0] = '\0';
	}
}