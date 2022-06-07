#include<iostream>
#include<vector>
#include<assert.h>
#include<algorithm>
#include<string>
#include<clocale>
using namespace std;

int main()
{
	float M;
	setlocale(LC_ALL, "Rus");
	cout << "Долларов: ";
	cin >> M;
	cout.precision(2);
	cout << endl << "В фунтах стерлингов: " << fixed << M / 1.487;
	cout << endl << "В франках: " << fixed << M / 0.172;
	cout << endl << "В немецких марках: " << fixed << M / 0.584;
	cout << endl << "В японских йенах: " << fixed << M / 0.00955;
}