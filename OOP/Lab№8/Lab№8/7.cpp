#include <iostream>
using namespace std;

class Counter
{
protected:
	unsigned int count;
public:
	Counter() : count(0)
	{}
	Counter(int c) : count(c)
	{}
	unsigned int get_count() const
	{
		return count;
	}
	Counter operator++ ()
	{
		return Counter(++count);
	}
};
class CountDn : public Counter
{
public:
	CountDn() : Counter()
	{ }
	CountDn(int c) : Counter(c)
	{ }
	CountDn operator-- ()
	{
		return CountDn(--count);
	}
};
class Counter2 : public CountDn
{
public:
	Counter2() : CountDn()
	{ }
	Counter2(int c) : CountDn(c)
	{ }
	Counter2(Counter ctr) : CountDn(ctr.get_count())
	{ }
	Counter2(CountDn cdn) : CountDn(cdn.get_count())
	{ }
	Counter2 operator++ (int)
	{
		return Counter2(count++);
	}
	Counter2 operator-- (int)
	{
		return Counter2(count--);
	}
	using CountDn::operator++;
	using CountDn::operator--;
};
int main()
{
	setlocale(LC_ALL, "Russian");
	Counter2 c1;
	Counter2 c2(100);
	cout << "c1 = " << c1.get_count();
	cout << "\nc2 = " << c2.get_count();

	++c1; ++c1; ++c1;
	cout << "\nc1 = " << c1.get_count();

	--c2; --c2;
	cout << "\nc2 = " << c2.get_count();

	Counter2 c3 = ++c1;
	cout << "\nc3 = " << c3.get_count();
	cout << ", c1 = " << c1.get_count();

	Counter2 c4 = --c2;
	cout << "\nc4 = " << c4.get_count();
	cout << ", c2 = " << c2.get_count();

	c1++;
	cout << "\nc1 = " << c1.get_count();

	c2--;
	cout << "\nc2 = " << c2.get_count();

	Counter2 c5 = c1++;
	cout << "\nc5 = " << c5.get_count();
	cout << ", c1 = " << c1.get_count();

	Counter2 c6 = c2--;
	cout << "\nc6 = " << c6.get_count();
	cout << ", c2 = " << c2.get_count();

	cout << endl;

	return 0;
}
