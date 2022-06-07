#include<iostream>
#include<vector>
#include<assert.h>
#include<algorithm>
#include<string>
#include <windows.h>
using namespace std;

int main()
{
	int k = 14;
	double a[100] = { 1 };
	double b[100] = { 2 };
	double c[100] = { 1 };
	double d[100] = { 140 };
	for (int i = 0; i < 100; i++)
	{
		a[i] = 1;
		b[i] = 2;
		c[i] = 1;
		d[i] = 10 * k;
	}
	a[0] = 0;
	c[99] = 0;
	double U[100];
	double V[100];
	double x[100];
	U[0] = -(c[0] / b[0]);
	V[0] = (d[0] / b[0]);
	for (int i = 1; i < 100; i++)
	{
		U[i] = -(c[i] / (a[i] * U[i - 1] + b[i]));
		V[i] = ((d[i] - a[i] * V[i - 1]) / (a[i] * U[i - 1] + b[i]));
	}
	x[99] = V[99];
	for (int i = 98; i >= 0; i--)
	{
		x[i] = U[i] * x[i + 1] + V[i];
	}
	for (int i = 0; i < 100; i++)
		cout << "\nx[" << i + 1 << "] = " << x[i];
	for (int i = 1; i < 99; i++)
		cout << endl << d[i] << " = " << a[i]*x[i-1]+b[i]*x[i]+c[i]*x[i+1];
}