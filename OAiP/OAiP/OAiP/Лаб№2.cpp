#include <iostream>

int main()
{
	setlocale(LC_ALL, "Rus");

	float x, y, s, p;
	printf("Введите 4 int x и y:\n");
	scanf_s("%f", &x);
	scanf_s("%f", &y);
	s = x * y;
	p = 2 * (x + y);
	printf("Перимерт: %f", s);
	printf("\nПлощадь: %f", p);
}