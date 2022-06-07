#include<iostream>
#include<math.h>
#include<sstream>
#include<assert.h>
#include<algorithm>
#include<string>
#include<clocale>
#include<STDLIB.h>
#include<iomanip>
using namespace std;

const int LIMIT = 100;
class safearay
{
private:
	int arr[LIMIT];
	int lowerbound;
	int upperbound;
public:
	safearay(int low, int up) : lowerbound(low), upperbound(up)
	{
		if (lowerbound > upperbound)
		{
			wcout << "Error";
		}
		if (lowerbound - upperbound >= LIMIT)
		{
			wcout << "Error";
		}
	}
	int& operator[] (int n)
	{
		if (n<lowerbound || n > upperbound)
		{
			wcout << "Error";
		}
		return arr[n - lowerbound];
	}
};
int main()
{
	int low, up;
	wcout << "Lowerbound - "; wcin >> low;
	wcout << "Upperbound - "; wcin >> up;
	safearay sa1(low, up);
	for (int j = low; j <= up; j++)
	{
		sa1[j] = j * 10;
	}
	for (int j = low; j <= up; j++)
	{
		int temp = sa1[j];
		wcout << "Element " << j << " = " << temp << endl;
	}
}
