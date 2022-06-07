#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <malloc.h>

int* arr; int k;

void QSort(int* arr, int b, int e)
{
	if (b < e)
	{
		int l = b, r = e, m = arr[(l + r) / 2], temp;
		while (l <= r) // for ( ;l <= r; )
		{
			while (arr[l] < m) 
				l++;
			while (arr[r] > m) 
				r--;
			if (l <= r)
			{
				temp = arr[l];
				arr[l] = arr[r];
				arr[r] = temp;
				l++;
				r--;
			}
		} 
		QSort(arr, b, r);
		QSort(arr, l, e);
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	printf("¬ведите размер массива k: ");
	scanf_s("%d", &k);
	arr = (int*)malloc(k * sizeof(int));
	for (int i = 0; i < k; i++)
	{
		printf("¬ведите arr[%d]: ", i + 1);
		scanf_s("%d", &arr[i]);
	}

	QSort(arr, 0, k-1);

	printf("\n");
	for (int r = 0; r < k; r++)
	{
		printf("arr[%d]: %d \n", r + 1, arr[r]);
	}
	free(arr);
}
