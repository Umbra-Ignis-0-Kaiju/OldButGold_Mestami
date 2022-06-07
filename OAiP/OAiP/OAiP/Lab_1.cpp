#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int k, z, r;
	printf("¬ведите k, z & r: ");
	scanf_s("%d %d %d", &k, &z, &r);
	printf("%.2f", ((float)(k + z) * z + r) / r);
	return 0;
}