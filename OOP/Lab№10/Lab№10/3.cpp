#include <iostream>
using namespace std;

class Distance
{
private:
	int feet;
	float inches;
public:
	Distance() : feet(0), inches(0.0)
	{ }
	Distance(float fltfeet)
	{
		feet = static_cast<int>(fltfeet);
		inches = 12 * (fltfeet - feet);
	}
	Distance(int ft, float in) : feet(ft), inches(in)
	{ }
	void showdist() const
	{
		cout << feet << "\'-" << inches << '\"';
	}
	friend float operator* (Distance, Distance);
};
float operator* (Distance d1, Distance d2)
{
	return (d1.feet + d1.inches / 12) * (d2.feet + d2.inches / 12);
}

int main()
{
	setlocale(LC_ALL, "Russian");

	Distance dist1 = 2.5;
	Distance dist2 = 1.25;
	float Wdist;
	cout << "dist1 = "; dist1.showdist();
	cout << "\ndist2 = "; dist2.showdist();
	Wdist = dist1 * dist2;
	cout << "\n\ndist1 * dist2 = " << Wdist << " кв. футов";
	Wdist = dist2 * dist1;
	cout << "\ndist2 * dist1 = " << Wdist << " кв. футов";
	Wdist = 7.5 * dist1;
	cout << "\n\n7.5 * dist1 = " << Wdist << " кв. футов";
	Wdist = dist1 * 7.5;
	cout << "\ndist1 * 7.5 = " << Wdist << " кв. футов\n";

	return 0;
}
