#include <iostream>
using namespace std;

class Array
{
private:
	int* ptr;
	int size;
public:
	Array() : ptr(0), size(0)
	{ }
	Array(int s)
	{
		size = s;
		ptr = new int[s];
	}
	Array(Array& arr)
	{
		size = arr.size;
		ptr = new int[size];
		for (int i = 0; i < size; i++)
			*(ptr + i) = *(arr.ptr + i);
	}
	~Array()
	{
		delete[] ptr;
	}
	int& operator[] (int j)
	{
		return *(ptr + j);
	}
	Array& operator= (Array& arr)
	{
		if (this == &arr) return *this;

		delete[] ptr;
		size = arr.size;
		ptr = new int[size];
		for (int i = 0; i < size; i++)
			*(ptr + i) = *(arr.ptr + i);
		return *this;
	}
	void display()
	{
		for (int i = 0; i < size; i++)
			cout << *(ptr + i) << ' ';
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");

	const int ASIZE = 10;
	Array arr1(ASIZE);

	for (int j = 0; j < ASIZE; j++)
		arr1[j] = j * j;
	cout << "arr1 = "; arr1.display(); cout << endl;

	Array arr2(arr1);
	cout << "arr2 = "; arr2.display(); cout << endl;

	Array arr3(10), arr4(5), arr5(15);
	arr3 = arr1;
	arr4 = arr1;
	arr5 = arr1;
	cout << "arr3 = "; arr3.display(); cout << endl;
	cout << "arr4 = "; arr4.display(); cout << endl;
	cout << "arr5 = "; arr5.display(); cout << endl;
	arr1 = arr1;
	cout << "arr1 = "; arr1.display(); cout << endl;
	Array arr6, arr7;
	arr7 = arr6 = arr1;
	cout << "arr6 = "; arr6.display(); cout << endl;
	cout << "arr7 = "; arr7.display(); cout << endl;

	return 0;
}
