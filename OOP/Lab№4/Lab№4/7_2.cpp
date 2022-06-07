#include<iostream>
#include<vector>
#include<assert.h>
#include<algorithm>
#include<string>
#include<clocale>
#include<windows.h>
#include<iomanip>
using namespace std;

double power(int p, double nd = 0, char nc = 0, int ni = 0, float nf = 0, long nl = 0)
{
	double v = 1;
	for (int i = 0; i < p; i++)
	{
		v = v * (nd + int (nc) + ni + nf + nl);
	}
	return v;
}

int main()
{
	double nd;
	char nc;
	int ni;
	float nf;
	long nl;
	int p;
	cin >> nd >> nc >> ni >> nl >> nf >> p;
	nc = nc - 48;
	cout << power(p, nd) << " " << power(p, nc) << " " << power(p, ni) << " " << power(p, nl) << " " << power(p, nf);
}