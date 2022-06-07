#include<iostream>
#include<vector>
#include<assert.h>
#include<algorithm>
#include<string>
#include<clocale>
#include<windows.h>
#include<iomanip>
using namespace std;

double power(double n, int p)
{
	double v = 1;
	for (int i = 0; i < p; i++)
		v = v * n;
	return v;
}
double power(char n, int p)
{
	double v = 1;
	for (int i = 0; i < p; i++)
		v = v * (int(n) - 48);
	return v;
}
double power(int n, int p)
{
	double v = 1;
	for (int i = 0; i < p; i++)
		v = v * n;
	return v;
}
double power(long n, int p)
{
	double v = 1;
	for (int i = 0; i < p; i++)
		v = v * n;
	return v;
}
double power(float n, int p)
{
	double v = 1;
	for (int i = 0; i < p; i++)
		v = v * n;
	return v;
}
int main()
{
	setlocale(LC_ALL, "Rus");
	double n;
	char nc;
	int ni;
	float nf;
	long nl;
	int p;
	cin >> n >> nc >> ni >> nl >> nf >> p;
	cout << power(n, p) << " " << power(nc, p) << " " << power(ni, p) << " " << power(nl, p) << " " << power(nf, p);
}