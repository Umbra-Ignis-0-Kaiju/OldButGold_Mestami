#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <malloc.h>

int main()
{
	int temp, k, z, min;
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
	for (int i = 0; i < k - 1; i++)
	{
		min = i;
		z = arr[i];
		for (int h = i + 1; h < k; h++)
		{
			if (arr[h] > arr[min])
			{
				min = h;
				z = arr[min];
			}
		}
		temp = arr[i];
		arr[i] = z;
		arr[min] = temp;
	}

	int i = 0, h;
	while (i < k - 1)
	{
		min = i;
		z = arr[i];
		h = i + 1;
		while (h < k)
		{
			if (arr[h] > arr[min])
			{
				min = h;
				z = arr[min];
			}
			h++;
		}
		temp = arr[i];
		arr[i] = z;
		arr[min] = temp;
		i++;
	}

	printf("\n");
	for (int o = 0; o < k; o++)
	{
		printf("arr[%d]: %d \n", o + 1, arr[o]);
	}

}
