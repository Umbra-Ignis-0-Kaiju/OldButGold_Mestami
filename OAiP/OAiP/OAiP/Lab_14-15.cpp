#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <malloc.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int k, temp, z = 2;
	printf("¬ведите размер массива k: ");
	scanf_s("%d", &k);
	int* arr;
	arr = (int*)malloc(k * sizeof(int));
	for (int r = 0; r < k; r++)
	{
		printf("¬ведите arr[%d]: ", r + 1);
		scanf_s("%d", &arr[r]);
	}

	int i = 1;
	while (i < k) {
		if (arr[i - 1] > arr[i]) {
			temp = arr[i];
			arr[i] = arr[i - 1];
			arr[i - 1] = temp;
			i--;
			if (i > 0) continue;
		}
		i = z++;
	}

	for (int i = 1; i < k;)
	{
		if (arr[i - 1] > arr[i])
		{
			temp = arr[i];
			arr[i] = arr[i - 1];
			arr[i - 1] = temp;
			i--;
			if (i > 0) continue;
		}
		i = z++;
	}

	printf("\n");
	for (int r = 0; r < k; r++)
	{
		printf("arr[%d]: %d \n", r + 1, arr[r]);
	}
	free(arr);
}
