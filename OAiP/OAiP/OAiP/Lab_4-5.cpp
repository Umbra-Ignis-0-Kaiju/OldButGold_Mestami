#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <malloc.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int k, z, i = 1, j = 0;
	printf("¬ведите размер массива k: ");
	scanf_s("%d", &k);
	int* arr;
	arr = (int*)malloc(k * sizeof(int));
	for (int r = 0; r < k; r++)
	{
		printf("¬ведите arr[%d]: ", r + 1);
		scanf_s("%d", &arr[r]);
	}
	/*while (i < k)
	{
		while (j < k - i)
		{
			if (arr[j] > arr[j + 1])
			{
				z = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = z;
			}
			j++;
		}
		j = 0;
		i++;
	}*/
	for (int i = 1; i < k; i++) 
	{
		for (int j = 0; j < k-i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				z = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = z;
			}
		}
	}
	printf("\n");
	for (int r = 0; r < k; r++)
	{
		printf("arr[%d]: %d \n", r + 1, arr[r]);
	}
	free(arr);
}
