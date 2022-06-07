#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <malloc.h>

int main()
{
	int temp, k, j;
	int* arr;
	setlocale(LC_ALL, "Rus");
	printf("¬ведите размер массива k: ");
	scanf_s("%d", &k);
	arr = (int*)malloc(k * sizeof(int));
	for (int o = 0; o < k; o++)
	{
		printf("¬ведите arr[%d]: ", o + 1);
		scanf_s("%d", &arr[o]);
	}

	for (int d = k / 2; d > 0; d /= 2) 
	{
		for (int i = d; i < k; i++) 
		{
			temp = arr[i];
			for (j = i; j >= d; j -= d) 
			{
				if (temp < arr[j - d])
					arr[j] = arr[j - d];
				else 
					break;
			}
			arr[j] = temp;
		}
	}

	int i;
	int d = k / 2;
	while (d > 0) {
		i = d;
		while (i < k) {
			temp = arr[i];
			j = i;
			while (j >= d) {
				if (temp < arr[j - d]) {
					arr[j] = arr[j - d];
					j = j - d;
				}
				else break;
			}
			arr[j] = temp;
			i++;
		}
		d = d / 2;
	}

	printf("\n");
	for (int o = 0; o < k; o++)
	{
		printf("arr[%d]: %d \n", o + 1, arr[o]);
	}

}
