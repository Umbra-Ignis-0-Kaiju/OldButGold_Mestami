#include<iostream>
#include<vector>
#include<assert.h>
#include<algorithm>
#include<string>
#include<clocale>
#include<windows.h>
#include<iomanip>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	long int O1, O2, o1, o2;
	char t, space;
	do
	{
		cout << "\nВведите первый операнд, операцию, а затем второй операнд: ";
		cin >> O1 >> space >> o1 >> t >> O2 >> space >> o2;
		if (t == '+')
		{
			O1 = O1 * o2 + O2 * o1;
			o1 = o1 * o2;
		}
		else if (t == '-')
		{
			O1 = O1 * o2 - O2 * o1;
			o1 = o1 * o2;
		}
		else if (t == '*')
		{
			O1 = O1 * O2;
			o1 = o1 * o2;
		}
		else
		{
			O1 = O1 * o2;
			o1 = o1 * O2;
		}
		cout << "Результат работы: " << O1 << space << o1 << "\n\nПродолжить? (y/n)   ";
		cin >> t;
	} while (t == 'y');
}