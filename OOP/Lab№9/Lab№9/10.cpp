#include <iostream>
using namespace std;
const int MAXSIZE = 10,
NUMARRAYS = 10;

int main()
{
	int j, k;
	int* ap[NUMARRAYS];
	for (j = 0; j < NUMARRAYS; j++)
		*(ap + j) = new int[MAXSIZE];
	for (j = 0; j < NUMARRAYS; j++)
		for (k = 0; k < MAXSIZE; k++)
			*(*(ap + j) + k) = (j * 10 + k) * 10;
	for (j = 0; j < NUMARRAYS; j++)
		for (k = 0; k < MAXSIZE; k++)
			cout << *(*(ap + j) + k) << ((k == MAXSIZE - 1) ? L'\n' : L' ');
	return 0;
}
