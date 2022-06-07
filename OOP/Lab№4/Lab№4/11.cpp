#include<iostream>
#include<vector>
#include<assert.h>
#include<algorithm>
#include<string>
#include<clocale>
#include<windows.h>
#include<iomanip>
using namespace std;
struct sterling
{
	int pounds;
	int shillings;
	int pence;
};
sterling preob(int f, int s, int p)
{
	sterling pr;
	pr.pounds = f;
	pr.shillings = s;
	pr.pence = p;
	return pr;
}
sterling sum(sterling a, sterling b)
{
	sterling z;
	z.pence = a.pence + b.pence;
	z.shillings = a.shillings + b.shillings;
	z.pounds = a.pounds + b.pounds;
	return z;
}
void out(sterling z)
{
	cout << z.pounds << "." << z.shillings << "." << z.pence;
}
int main()
{
	setlocale(LC_ALL, "Rus");
	sterling one, two, suma;
	cout << "Введите первое значение фунтов в старом формате: ";
	int f, s, p;
	char space;
	cin >> f >> space >> s >> space >> p;
	one = preob(f, s, p);
	cout << "Введите второе значение фунтов в старом формате: ";
	cin >> f >> space >> s >> space >> p;
	two = preob(f, s, p);
	suma = sum(one, two);
	out(suma);
}