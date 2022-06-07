#include <iostream>
using namespace std;
const int fm_SIZE = 100;
float fmemory[fm_SIZE];
int fmem_top = 0;
const int pm_SIZE = 100;
int pmemory[pm_SIZE];
int pmem_top = 0;

class Float
{
private:
	int addr;
public:
	Float(float value)
	{
		fmemory[fmem_top] = value;
		addr = fmem_top;
		fmem_top++;
	}
	int operator& () const
	{
		return addr;
	}
};

class ptrFloat
{
private:
	int addr;
public:
	ptrFloat(int value)
	{
		pmemory[pmem_top] = value;
		addr = pmem_top;
		pmem_top++;
	}
	float& operator* () const
	{
		return fmemory[pmemory[addr]];
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	Float var1 = 1.234f;
	Float var2 = 5.678f;

	ptrFloat ptr1 = &var1;
	ptrFloat ptr2 = &var2;

	cout << "*ptr1 = " << *ptr1 << endl;
	cout << "*ptr2 = " << *ptr2 << endl << endl;

	*ptr1 = 7.123f;
	*ptr2 = 8.456f;

	cout << "*ptr1 = " << *ptr1 << endl;
	cout << "*ptr2 = " << *ptr2 << endl;

	return 0;
}