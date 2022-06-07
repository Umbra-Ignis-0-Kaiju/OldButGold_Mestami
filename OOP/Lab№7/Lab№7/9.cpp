#include<iostream>
#include<io.h>
#include<iomanip>
#include<windows.h>
#include<math.h>
#include<sstream>
#include<assert.h>
#include<algorithm>
#include<string>
#include<clocale>
#include<sstream>
#include<iomanip>
using namespace std;

const double PI = 3.14;

class Polar
{
private:
	double radius;
	double angle;
public:
	Polar() : radius(0.0), angle(0.0)
	{}
	void get(bool in_radians)
	{
		cout << "Radius - "; wcin >> radius;
		if (radius < 0)
		{
			cout << "Error";
		}
		if (in_radians)
		{
			cout << "   введите угол (в радианах): "; wcin >> angle;
		}
		else
		{
			cout << "   введите угол (в градусах): "; int deg; wcin >> deg;
			angle = deg * PI / 180;
		}
	}
	void put(bool in_radians)
	{
		cout << "   радиус: " << radius << endl;

		if (in_radians)
		{
			cout << "   угол (в радианах): " << angle << endl;
		}
		else
		{
			cout << "   угол (в градусах): " << angle * 180 / PI << endl;
		}
	}
	Polar operator+ (Polar p) const;
};
int main()
{
	setlocale(LC_ALL, "Russian");
	Polar p1, p2, res;
	cout << "Введите первую точку в полярных координатах : \n"; p1.get(false);
	cout << "Введите вторую точку в полярных координатах:\n"; p2.get(false);
	res = p1 + p2;

	cout << "Результат сложения:\n"; res.put(false);
}
Polar Polar::operator+ (Polar p) const
{
	double x = radius * cos(angle);
	double y = radius * sin(angle);

	x += p.radius * cos(p.angle);
	y += p.radius * sin(p.angle);

	Polar res;
	res.radius = sqrt(x * x + y * y);
	res.angle = atan2(y, x);
	return res;
}