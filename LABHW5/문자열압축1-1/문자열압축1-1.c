#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// �ϳ��� ���� ������ ǥ���Ͽ� ���๮�ڿ���  ����ϰ� �� ���̸� ��ȯ�Ѵ�.
int solution(char *s)
{
	// �ڵ�
	int i, j = 0, num;
	char compare;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (i == 0)
		{
			compare = s[i];
			num = 1;
		}
		else
		{
			if (compare == s[i])
				//if (strcmp(compare, s[i]) == 0)
				num++;
			else
			{
				if (num != 1)
				{
					s[j] = num + '0';
					j++;
				}
				s[j] = compare;
				j++;

				compare = s[i];
				num = 1;
			}
		}
	}

	if (num != 1)
	{
		s[j] = num + '0';
		j++;
	}

	s[j] = compare;
	j++;

	s[j] = '\0';

	printf("%s\n", s);

	return j;
}

int main(void)
{
	char s[1001];
	scanf("%s", s);
	printf("%d\n", solution(s));
}