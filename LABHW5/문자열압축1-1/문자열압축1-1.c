#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 하나의 문자 연속을 표현하여 압축문자열을  출력하고 그 길이를 반환한다.
int solution(char *s)
{
	// 코드
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