#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	
	float x, y, s, p;
	
	printf("������� 4 int x � y:\n");
	scanf_s("%d", &x);
	scanf_s("%d", &y);
	s = x * y;
	p = 2 * (x + y);
	printf("��������: %f", s);
	printf("\n�������: %f", p);
	
}