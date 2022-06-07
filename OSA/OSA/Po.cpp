#include <iostream>
#include <vector>

using namespace std;

struct complex
{
	float real = 0;
	float imag = 0;
	complex()
	{
		real = 0;
		imag = 0;
	};
	complex(float one, float two)
	{
		real = one;
		imag = two;
	};
};
ostream& operator << (ostream& out, complex num)
{
	out << "(" << num.real << ", " << num.imag << ")";
	return out;
}
complex operator + (complex one, complex two)
{
	one.imag += two.imag;
	one.real += two.real;
	return one;
}
complex operator - (complex one, complex two)
{
	one.imag -= two.imag;
	one.real -= two.real;
	return one;
}
complex operator * (complex one, complex two)
{
	one.imag *= two.imag;
	one.real *= two.real;
	return one;
}

class CCV
{
private:
	vector<complex> vec;
public:
	CCV()
	{
		vector<complex> kk;
		vec = kk;
	}
	CCV(int random)
	{
		vector<complex> kk(random);
		vec = kk;
	};
	~CCV()
	{
		vec.clear();
	}
	int size()
	{
		return vec.size();
	}
	complex back(int i)
	{
		complex t;
		if (i >= int(vec.size()))
			return t;
		return vec[i];
	}
	void back_all()
	{
		for (int i = 0; i < int(vec.size()); i++)
			cout << "(" << vec[i].real << ", " << vec[i].imag << ")  ";
		cout << endl;
	}
	void push(complex why)
	{
		vec.push_back(why);
	}
	CCV operator = (CCV v1)
	{
		vec.clear();
		for (int i = 0; i < v1.size(); i++)
			vec.push_back(v1[i]);
		return *this;
	}
	complex& operator [] (const int index)
	{
		return vec[index];
	}
	
};

	CCV operator + (CCV v1, CCV v2)
	{
		CCV v3;
		complex t1, t2;
		for (int i = 0; i < ceil((v1.size() + v2.size()) / 2) + 1; i++)
		{
			v3.push(v1.back(i) + v2.back(i));
		}
		return v3;
	}
	CCV operator - (CCV v1, CCV v2)
	{
		CCV v3;
		complex t1, t2;
		for (int i = 0; i < ceil((v1.size() + v2.size()) / 2) + 1; i++)
		{
			v3.push(v1.back(i) - v2.back(i));
		}
		return v3;
	}
	CCV operator * (CCV v1, CCV v2)
	{
		CCV v3;
		complex t1, t2;
		for (int i = 0; i < ceil((v1.size() + v2.size()) / 2) + 1; i++)
		{
			v3.push(v1.back(i) * v2.back(i));
		}
		return v3;
	}
int main()
{
	CCV slojna;
	CCV master(3);
	CCV test;
	slojna.push(complex(6.3f, 7.4f));
	slojna.push(complex(0.23f, 4.22f));
	master[0] = complex(2.3f, 5.2f);
	master[2] = complex(1.5f, 3.8f);
	cout << master.back(5) << "\n";
	master.back_all();
	slojna.back_all();
	test = master + slojna;
	test.back_all();
	test = master - slojna;
	test.back_all();
	test = master * slojna;
	test.back_all();
}