#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <malloc.h>

int k;
int* arr;

void Swipe(int i)
{
	for (int r = k; r > i; r--)
	{
		arr[r] = arr[r - 1];
	}
	return;
}

int main()
{
	int temp;
	setlocale(LC_ALL, "Rus");
	printf("¬ведите размер массива k: ");
	scanf_s("%d", &k);
	arr = (int*)malloc(k * sizeof(int));
	printf("¬ведите arr[1]: ");
	scanf_s("%d", &arr[0]);
	for (int r = 1; r < k; r++)
	{
		printf("¬ведите arr[%d]: ", r + 1);
		scanf_s("%d", &temp);
		for (int i = 0; i < r; i++)
		{
			if (temp < arr[i])
			{
				Swipe(i);
				arr[i] = temp;
				break;
			}
			else if (i == r - 1 && temp > arr[i])
			{
				arr[i+1] = temp;
				break;
			}
		}

		int i = 0;
		while (i < r)
		{
			if (temp < arr[i])
			{
				Swipe(i);
				arr[i] = temp;
				break;
			}
			else if (i == r - 1 && temp > arr[i])
			{
				arr[i + 1] = temp;
				break;
			}
			i++;
		}
	}
	printf("\n");
	for (int r = 0; r < k; r++)
	{
		printf("arr[%d]: %d \n", r + 1, arr[r]);
	}
	
}
