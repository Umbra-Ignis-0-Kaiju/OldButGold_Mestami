#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <malloc.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int k, j, ch = 0, nc = 0, z;
	printf("Введите размер массива k: ");
	scanf_s("%d", &k);
	int* arr;
	arr = (int*)malloc(k * sizeof(int));
	for (int i = 0; i < k; i++)
	{
		printf("Введите arr[%d]: ", i + 1);
		scanf_s("%d", &arr[i]);
	}
	for (int i = 0; i < k; i++) //подсчёт количества чётных и нечётных чисел
	{
		if (arr[i] % 2 == 0)
			ch++;
		else
			nc++;
	}
	
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (abs(arr[i] % 2) == abs(arr[j] % 2))
			{
				if (arr[i] > arr[j] && j > i)
				{
					z = arr[i];
					arr[i] = arr[j];
					arr[j] = z;
				}
				else if (arr[i] < arr[j] && j < i)
				{
					z = arr[i];
					arr[i] = arr[j];
					arr[j] = z;
				}
			}
			else if (abs(arr[i] % 2) == 0 && abs(arr[j] % 2) == 1 && j > i)
			{
				z = arr[i];
				arr[i] = arr[j];
				arr[j] = z;
			}
			else if (arr[i] % 2 == 1 && arr[j] % 2 == 0 && j < i)
			{
				z = arr[i];
				arr[i] = arr[j];
				arr[j] = z;
			}
		}
	}

	/*int i = 0;
	while (i < k)
	{
		j = 0;
		while (j < k)
		{
			if (abs(arr[i] % 2) == abs(arr[j] % 2))
			{
				if (arr[i] > arr[j] && j > i)
				{
					z = arr[i];
					arr[i] = arr[j];
					arr[j] = z;
				}
				else if (arr[i] < arr[j] && j < i)
				{
					z = arr[i];
					arr[i] = arr[j];
					arr[j] = z;
				}
			}
			else if (abs(arr[i] % 2) == 0 && abs(arr[j] % 2) == 1 && j > i)
			{
				z = arr[i];
				arr[i] = arr[j];
				arr[j] = z;
			}
			else if (arr[i] % 2 == 1 && arr[j] % 2 == 0 && j < i)
			{
				z = arr[i];
				arr[i] = arr[j];
				arr[j] = z;
			}
			j++;
		}
		i++;
	}*/

	if (ch + nc == 0)
	{
		printf("\nМассива нет!");
	}
	else if (ch == 0)
	{
		printf("\nНечётные числа: \n");
		for (int i = 0; i < k; i++)
		{
			printf("arr[%d]: %d \n", i+1, arr[i]);
		}
		printf("\nЧётных чисел нет");
	}
	else if (nc == 0)
	{
		printf("\nНечётных чисел нет \n");
		printf("\nЧётные числа: \n");
		for (int i = 0; i < k; i++)
		{
			printf("arr[%d]: %d \n", i+1, arr[i]);
		}
	}
	else
	{
		printf("\nНечётные числа: \n");
		for (int i = 0; i < nc; i++)
		{
			printf("arr[%d]: %d \n", i+1, arr[i]);
		}
		printf("\nЧётные числа: \n");
		for (int i = k-ch; i < k; i++)
		{
			printf("arr[%d]: %d \n", i+1, arr[i]);
		}
	}
}