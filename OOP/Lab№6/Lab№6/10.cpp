#include<iostream>
#include<math.h>
#include<assert.h>
#include<algorithm>
#include<string>
#include<clocale>
#include<STDLIB.h>
#include<iomanip>
using namespace std;

bool trap = 0;
class matrix
{
private:
	static const int Ngr = 10;
	static const int Mgr = 10;
	int matr[Ngr][Mgr];
	int Nchoo; int Mchoo;
public:
	matrix(int N, int M)
	{
		if ((N > 0 && N <= Ngr) && (M > 0 && M <= Mgr))
		{
			Nchoo = N;
			Mchoo = M;
		}
		else
		{
			cout << "�������� ������� �� ���������� � ������� " << Ngr << " �� " << Mgr << endl;
			exit(0);
		}
	}
	void putel(int N, int M, int E)
	{
		if ((N >= 0 && N < Nchoo) && (M >= 0 && M < Mchoo))
		{
			matr[N][M] = E;
		}
		else
		{
			cout << "������ � ������� �� ���������, ������ [" << N << "][" << M << "] ������� �� ������� �������� ������� [" << Nchoo - 1 << "][" << Mchoo - 1 << "]" << endl;
		}
	}
	int getel(int N, int M)
	{
		if ((N >= 0 && N < Nchoo) && (M >= 0 && M < Mchoo))
		{
			trap = 1;
			return matr[N][M];
		}
		else
		{
			cout << "��� ������, ������ [" << N << "][" << M << "] ������� �� ������� �������� ������� [" << Nchoo - 1 << "][" << Mchoo - 1 << "]" << endl;
			return 0;
		}
	}
};
int main()
{
	setlocale(LC_ALL, "Rus");
	int n, m, z;
	char k;
	cout << "������� ������ ������� NxM: ";
	cin >> n >> m;
	matrix mat(n, m);
	do
	{
		trap = 0;
		cout << "\n������/������� �������� (p/g)" << endl;
		cin >> k;
		cout << endl;
		switch (k)
		{
		case 'p':
		{
			cout << "������� �������� � ���������� �� �������: ";
			cin >> z >> n >> m;
			mat.putel(n, m, z);
			break;
		}
		case 'g':
		{
			cout << "������� ���������� �� ������� NxM: ";
			cin >> n >> m;
			n = mat.getel(n, m);
			if (trap == 1)
				cout << "��������: " << n << endl;
			break;
		}
		case '0':
			return 0;
		} 
	} while (true);
}
