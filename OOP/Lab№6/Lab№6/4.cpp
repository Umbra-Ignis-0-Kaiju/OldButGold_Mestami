#include<iostream>
#include<vector>
#include<assert.h>
#include<algorithm>
#include<string>
#include<clocale>
#include<windows.h>
#include<iomanip>
using namespace std;

int maxint(int n, int* m)
{
	int max = 0;
	for (int i = 0; i < n; i++)
		if (m[i] > m[max])
			max = i;
	return max;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int N, max;
	cout << "������� ���������� ��������� �������: ";
	cin >> N;
	int* mas = new int[N];
	cout << "������� ��� �������� �������: ";
	for (int i = 0; i < N; i++)
		cin >> mas[i];
	max = maxint(N, mas);
	cout << "������ ����������� �������� = " << max << "\nmas[" << max << "] = " << mas[max];
}
