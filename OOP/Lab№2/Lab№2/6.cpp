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
	int n;
	unsigned long int fact;
	do
	{
		fact = 1;
		cout << "Введите число: ";
		cin >> n;
		if (n != 0)
		{
			for (int i = 1; i <= n; i++)
				fact *= i;
			cout << endl << "Факториал = " << fact << endl << endl << endl;
		}
	} while (n != 0);
}