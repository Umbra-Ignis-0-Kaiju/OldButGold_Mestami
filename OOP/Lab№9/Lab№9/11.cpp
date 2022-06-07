#include <iostream>
using namespace std;

class narrays
{
private:
	const int NUMARRAYS;
	const int MAXSIZE;
	int** ap;
public:
	narrays(int na, int ms) : NUMARRAYS(na), MAXSIZE(ms)
	{
		ap = new int* [NUMARRAYS];
		for (int j = 0; j < NUMARRAYS; j++)
			*(ap + j) = new int[MAXSIZE];
	}
	~narrays()
	{
		for (int j = 0; j < NUMARRAYS; j++)
			delete[] * (ap + j);
		delete[] ap;
	}
	int& operator[] (int n)
	{
		int j = n / MAXSIZE;
		int k = n % MAXSIZE;
		return *(*(ap + j) + k);
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	int numarr;
	int sizearr;

	cout << "¬ведите количество отдельных массивов (больше 0): "; wcin >> numarr;
	cout << "¬ведите количество элементов в каждом отдельном массиве (больше 0): "; wcin >> sizearr;
	cout << endl;

	narrays arr(numarr, sizearr);
	int i;
	for (i = 0; i < numarr * sizearr; i++)
		arr[i] = i * 10;
	for (i = 0; i < numarr * sizearr; i++)
		cout << arr[i] << ((i % sizearr == sizearr - 1) ? L'\n' : L' ');

	return 0;
}
