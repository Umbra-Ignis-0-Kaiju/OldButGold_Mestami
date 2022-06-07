#include<iostream>
#include<vector>
#include<assert.h>
#include<algorithm>
#include<string>
#include<clocale>
#include<iomanip>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	for (int i = 1; i <= 21; i += 2)
	{
		cout << endl << setw(11-i/2);
		for (int j = 0; j < i; j++)
			cout << "X";
	}
}