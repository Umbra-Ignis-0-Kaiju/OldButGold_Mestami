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
	struct employee
	{
		int number;
		float money;
	};
	employee f, s, t;
	cout << "������� ����� � ������� ������� ����������: ";
	cin >> f.number >> f.money;
	cout << "������� ����� � ������� ������� ����������: ";
	cin >> s.number >> s.money;
	cout << "������� ����� � ������� �������� ����������: ";
	cin >> t.number >> t.money;
	cout << "\n��������� �" << f.number << " �������� ������� � �������: " << f.money;
	cout << "\n��������� �" << s.number << " �������� ������� � �������: " << s.money;
	cout << "\n��������� �" << t.number << " �������� ������� � �������: " << t.money;
}