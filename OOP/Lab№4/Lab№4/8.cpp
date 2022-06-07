#include<iostream>
#include<vector>
#include<assert.h>
#include<algorithm>
#include<string>
#include<clocale>
#include<windows.h>
#include<iomanip>
using namespace std;
int a, b;
void swap(int x, int y)
{
	a = y;
	b = x;
}


int main()
{
	cin >> a >> b;
	swap(a, b);
	cout << endl << a << " " << b;
}