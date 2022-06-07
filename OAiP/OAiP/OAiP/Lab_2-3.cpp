#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int k, z, r, ans, count = 0;
	printf("Введите k, z & r: ");
	scanf_s("%d %d %d", &k, &z, &r);
	ans = (k*z)%r;
	printf("Ans после вычисления = %d", ans);
	printf("\n");
	if (ans % 2 == 1)
	{
		ans = ans * 5 - 1;
		printf("Ans после сравнения = %d", ans);
		printf("\n");
		printf("Делений ans*5-1 на 2 до равенства с нулём: ");
	}
	else
	{
		ans = ans * 7;
		printf("Ans после сравнения = %d", ans);
		printf("\n");
		printf("Делений ans*7 на 2 до равенства с нулём: ");
	}
	while (ans != 0)
	{
		ans /= 2;
		count++;
	}
	printf("%d", count);
	return 0;
}