#include<iostream>
#include<vector>
#include<assert.h>
#include<algorithm>
#include<string>
#include<clocale>
#include<windows.h>
#include<iomanip>
using namespace std;
class employee
{
private:
	int number;
	float money;
public:
	void set(int n, float m)
	{
		number = n;
		money = m;
	}
	void info()
	{
		cout << "\n��������� �" << number << " �������� ������� � �������: " << money;
	}
};
int main()
{
	setlocale(LC_ALL, "Rus");
	int n; float m;
	employee one, two, three;
	cout << "������� ����� � ������� ������� ����������: ";
	cin >> n >> m;
	one.set(n, m);
	cout << "������� ����� � ������� ������� ����������: ";
	cin >> n >> m;
	two.set(n, m);
	cout << "������� ����� � ������� �������� ����������: ";
	cin >> n >> m;
	three.set(n, m);
	one.info();
	two.info();
	three.info();
}