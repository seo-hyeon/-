#include <stdio.h>
#include <stdlib.h>

typedef struct Score {
	int midterm;
	int final;
}Score;

void printScore(Score *p)
{
	printf("�߰���� ������ %d\n", p->midterm);
	printf("�⸻�һ� ������ %d\n", p->final);
}
Score *biggerScore(Score *p1, Score * p2)
{
	if ((p1->midterm + p1->final) > (p2->midterm + p2->final))
		return p1;
	else
		return p2;
}
Score *totalScore(Score *p1, Score *p2)
{
	Score *p;
	p = (Score *)malloc(sizeof(Score));

	p->midterm = p1->midterm + p2->midterm;
	p->final = p1->final + p2->final;

	return p;
}
Score *createScore(int m, int f)
{
	Score *p;
	p = (Score *)malloc(sizeof(Score));

	p->midterm = m;
	p->final = f;

	return p;
}
int main(void)
{
	Score s1, s2;
	Score *p3;

	p3 = (Score *)malloc(sizeof(Score));

	s1.midterm = 50;
	s1.final = 100;
	s2.midterm = 70;
	s2.final = 70;

	printScore(&s1);
	printScore(&s2);

	printf("--------------------------------\n");
	printf("���� ������ ���� ����:\n");
	printScore(biggerScore(&s1, &s2));

	printf("--------------------------------\n");
	printf("�� ������ �� ��:\n");
	printScore(totalScore(&s1, &s2));

	printf("--------------------------------\n");
	p3 = createScore(100, 100);
	printScore(p3);
}