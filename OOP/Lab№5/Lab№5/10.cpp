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
		cout << deg << "�" << minute << "\' " << dir << endl;
	}
	void in()
	{
		cout << "\n������� ��������� ����: ";
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
		cout << "����� �������: " << num << endl << "��� ���������: \n";
		cout << "������:";
		shir.in();
		cout << "�������:";
		dolg.in();
	}
	void out()
	{
		cout << "\n\n����� �������: " << num << endl << "����������:\n";
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
