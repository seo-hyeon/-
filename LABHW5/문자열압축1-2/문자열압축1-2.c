#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 하나의 문자 연속을 표현하여 압축문자열을  출력하고 그 길이를 반환한다.
int solution(char *s)
{
	// 코드
	int i, j = 0, num;
	char compare[3], p[3];

	compare[2] = '\0';
	p[2] = '\0';

	/*if (s[1] == '\0')
	{
		printf("%s", s);
		return 1;
	}*/

	for (i = 0; s[i] != '\0' && s[i + 1] != '\0'; i += 2)
	{
		if (i == 0)
		{
			compare[0] = s[i];
			compare[1] = s[i + 1];
			num = 1;
		}
		else
		{
			p[0] = s[i];
			p[1] = s[i + 1];

			if (strcmp(compare, p) == 0)
				num++;
			else
			{
				if (num != 1)
					s[j++] = num + '0';
				s[j++] = compare[0];
				s[j++] = compare[1];

				compare[0] = s[i];
				compare[1] = s[i + 1];
				num = 1;
			}
		}
	}

	if (num != 1)
		s[j++] = num + '0';

	s[j++] = compare[0];
	s[j++] = compare[1];

	if (s[i] != '\0')
		s[j++] = s[i];

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