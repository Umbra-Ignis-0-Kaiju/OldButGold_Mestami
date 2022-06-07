#include <iostream>
using namespace std;

const int SIZE = 10;

int main()
{
	int a0[SIZE], a1[SIZE], a2[SIZE], a3[SIZE], a4[SIZE],
		a5[SIZE], a6[SIZE], a7[SIZE], a8[SIZE], a9[SIZE];

	int* ap[] = { a0, a1, a2, a3, a4, a5, a6, a7, a8, a9 };

	int j, k;

	for (j = 0; j < SIZE; j++)
		for (k = 0; k < SIZE; k++)
			ap[j][k] = (j * 10 + k) * 10;
	for (j = 0; j < SIZE; j++)
		for (k = 0; k < SIZE; k++)
			cout << ap[j][k] << ((k == SIZE - 1) ? L'\n' : L' ');

	return 0;
}
