#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int k, z, r, ans, count = 0;
	printf("������� k, z & r: ");
	scanf_s("%d %d %d", &k, &z, &r);
	ans = (k*z)%r;
	printf("Ans ����� ���������� = %d", ans);
	printf("\n");
	if (ans % 2 == 1)
	{
		ans = ans * 5 - 1;
		printf("Ans ����� ��������� = %d", ans);
		printf("\n");
		printf("������� ans*5-1 �� 2 �� ��������� � ����: ");
	}
	else
	{
		ans = ans * 7;
		printf("Ans ����� ��������� = %d", ans);
		printf("\n");
		printf("������� ans*7 �� 2 �� ��������� � ����: ");
	}
	while (ans != 0)
	{
		ans /= 2;
		count++;
	}
	printf("%d", count);
	return 0;
}