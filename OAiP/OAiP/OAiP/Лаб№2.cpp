#include <iostream>

int main()
{
	setlocale(LC_ALL, "Rus");

	float x, y, s, p;
	printf("������� 4 int x � y:\n");
	scanf_s("%f", &x);
	scanf_s("%f", &y);
	s = x * y;
	p = 2 * (x + y);
	printf("��������: %f", s);
	printf("\n�������: %f", p);
}