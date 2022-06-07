#include<iostream>
#include<vector>
#include<assert.h>
#include<algorithm>
#include<string>
#include<clocale>
#include<windows.h>
#include<iomanip>
using namespace std;
class angle
{
private:
	int deg;
	float minute;
	char dir;
public:
	angle(int d, float m, char u) : deg(d), minute(m), dir(u) {}
	void out()
	{
		cout << endl << deg << "∞" << minute << "\' " << dir;
	}
	void in()
	{
		cout << "\n¬ведите параметры угла: ";
		cin >> deg >> minute >> dir;
	}
};
int mainQ()
{
	setlocale(LC_ALL, "Rus");
	int deg;
	float min;
	char dir;
	cout << "¬ведите параметры угла: ";
	cin >> deg >> min >> dir;
	angle znach(deg, min, dir);
	znach.out();
	while (1)
	{
		znach.in();
		znach.out();
	}
}
int main()
{
	mainQ();
}
