#include<iostream>
#include<vector>
#include<assert.h>
#include<algorithm>
#include<string>
#include<clocale>
#include<windows.h>
#include<iomanip>
using namespace std;
class order
{
private:
	int num;
	static int count;
public:
	order()
	{
		count++;
		num = count;
	}
	void out()
	{
		cout << endl << "Порядковый номер объекта: " << num;
	}
};
int order::count = 0;
int main()
{
	setlocale(LC_ALL, "Rus");
	order one, two, three;
	one.out();
	two.out();
	three.out();
}