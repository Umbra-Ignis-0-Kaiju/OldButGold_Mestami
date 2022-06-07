#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <malloc.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int k, z;
	printf("¬ведите размер массива k: ");
	scanf_s("%d", &k);
	int* arr;
	arr = (int*)malloc(k * sizeof(int));
	for (int r = 0; r < k; r++)
	{
		printf("¬ведите arr[%d]: ", r + 1);
		scanf_s("%d", &arr[r]);
	}
	int step = k-1, i = 0;
	while (step >= 1)
	{
		while (i < k - step)
		{
			if (arr[i] > arr[i + step])
			{
				z = arr[i];
				arr[i] = arr[i + step];
				arr[i + step] = z;
			}
			i++;
		}
		i = 0;
		step /= 1.247;
	}
	/*for (int step = k-1; step >= 1; step /= 1.247)
	{
		for (int i = 0; i < k - step; i++)
		{
			if (arr[i] > arr[i + step])
			{
				z = arr[i];
				arr[i] = arr[i + step];
				arr[i + step] = z;
			}
		}
	}*/
	printf("\n");
	for (int r = 0; r < k; r++)
	{
		printf("arr[%d]: %d \n", r + 1, arr[r]);
	}
	free(arr);
}