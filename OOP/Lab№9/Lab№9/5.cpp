#include <iostream>
using namespace std;

void addarrays(float*, float*, float*, int);
void display(float*, int);

int main()
{
	setlocale(LC_ALL, "Russian");
	const int SIZE = 7;
	float arr1[SIZE] = { 23.1f, 5.67f, 0.32f, 4.0f, 73.213f, 3.5f, 890.1f },
		arr2[SIZE] = { 11.23f, 7.32f, 444.0f, 32.12f, 79.3f, 5.321f, 45.09f },
		arr3[SIZE];
	addarrays(arr1, arr2, arr3, SIZE);

	cout << "Первый массив = "; display(arr1, SIZE); cout << endl;
	cout << "Второй массив = "; display(arr2, SIZE); cout << endl;
	cout << "Результат сложения = "; display(arr3, SIZE); cout << endl;

	return 0;
}
void addarrays(float* a1, float* a2, float* a3, int N)
{
	for (int j = 0; j < N; j++)
		*(a3 + j) = *(a1 + j) + *(a2 + j);
}

void display(float* a, int N)
{
	for (int j = 0; j < N; j++)
		cout << *(a + j) << ((j != N - 1) ? ", " : "");
}
