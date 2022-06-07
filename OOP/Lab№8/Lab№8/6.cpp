#include <iostream>
using namespace std;
const int LIMIT = 100;

class safearray
{
private:
	int arr[LIMIT];
public:
	int& operator[] (int n)
	{
		if (n < 0 || n >= LIMIT)
		{
			cout << "��������� ������!"; exit(1);
		}
		return arr[n];
	}
};

class safehilo : public safearray
{
private:
	int lowerbound;
	int upperbound;
public:
	safehilo(int low, int up) : lowerbound(low), upperbound(up)
	{
		if (lowerbound > upperbound)
		{
			cout << "������! ������� ������� ������� ������� �� ����� ���� ������ ������.\n"; exit(1);
		}
		if (upperbound - lowerbound >= LIMIT)
		{
			cout << "������! � ������� �� ����� ���� ������ " << LIMIT << " ���������.\n"; exit(1);
		}
	}
	int& operator[] (int n)
	{
		if (n < lowerbound || n > upperbound)
		{
			cout << "��������� ������!"; exit(1);
		}
		return safearray::operator[] (n - lowerbound);
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	int low, up;

	cout << "������� ������ ������� ������� ������� : "; wcin >> low;
	cout << "������� ������� ������� ������� �������: "; wcin >> up;

	safehilo sa1(low, up);

	for (int j = low; j <= up; j++)
		sa1[j] = j * 10;
	for (int j = low; j <= up; j++)
	{
		int temp = sa1[j];
		cout << "������� " << j << " ����� " << temp << endl;
	}

	return 0;
}
