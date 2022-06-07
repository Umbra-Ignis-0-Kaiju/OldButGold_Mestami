#include <stdio.h>
#include <math.h>
#include <string.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int a, b, c, d, ans;
	char e;
	printf("%s", "¬ведите 4 int a, b, c, d и любую заглавную букву английского алфавита в том же пор€дке дл€ применени€ их в формуле: ((a+b)/(c+d))*((e%2)!=0)");
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	scanf_s("%d", &c);
	scanf_s("%d", &d);
	scanf_s("%s", e);
	ans = ((a + b) / (c + d)) * ((int(e) - 32) % 2) != 0);
}