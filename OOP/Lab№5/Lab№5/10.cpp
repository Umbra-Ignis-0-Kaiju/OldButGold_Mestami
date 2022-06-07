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
	void out()
	{
		cout << deg << "°" << minute << "\' " << dir << endl;
	}
	void in()
	{
		cout << "\nВведите параметры угла: ";
		cin >> deg >> minute >> dir;
	}
};
class ship
{
private:
	angle shir;
	angle dolg;
	int num;
	static int count;
public:
	ship()
	{
		count++;
		num = count;
	}
	void in()
	{
		cout << "Номер корабля: " << num << endl << "Его положение: \n";
		cout << "Широта:";
		shir.in();
		cout << "Долгота:";
		dolg.in();
	}
	void out()
	{
		cout << "\n\nНомер корабля: " << num << endl << "Координаты:\n";
		shir.out();
		dolg.out();
	}
};
int ship::count = 0;
void mainQ()
{
	setlocale(LC_ALL, "Rus");
	ship one, two, three;
	one.in();
	two.in();
	three.in();
	one.out();
	two.out();
	three.out();
}
int main()
{
	mainQ();
}
