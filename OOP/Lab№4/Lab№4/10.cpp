#include<iostream>
#include<vector>
#include<assert.h>
#include<algorithm>
#include<string>
#include<clocale>
#include<windows.h>
#include<iomanip>
using namespace std;
int k = 1;
void counterk()
{
	cout << "\n������� ���������� " << k << " ���;";
	k++;
}
void counterz(int& a)
{
	cout << "\n������� ���������� " << a << " ���;";
	a++;
}
int main()
{
	setlocale(LC_ALL, "Rus");
	int z = 1;
	for (int i = 0; i < 13; i++)
	{
		counterk();
		counterz(z);
	}
}