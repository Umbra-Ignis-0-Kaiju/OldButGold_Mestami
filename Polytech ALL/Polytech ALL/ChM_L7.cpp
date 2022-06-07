#include<iostream>
#include<cmath>
#include<assert.h>
#include<algorithm>
#include<string>
using namespace std;

double f(double x)
{
	return sqrt(1 + 5 * log(x)) / x;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	double suml = 0, sumr = 0, sumc = 0, sumt = 0, simp = 0, a, b, h;
	int count = 0;
	cout << "������� ������� ��������� a � b: ";
	cin >> a >> b;
	/*cout << "\n\n��� 1 ����";
	cout << "\n����� ���������������: " << fixed << f(1) * 99;
	cout << "\n����������� ���������������: " << fixed << f(50.5) * 99;
	cout << "\n������ ��������������: " << fixed << f(100) * 99;*/
	h = (b - a) / 10;
	// 10 �����
	for (double i = a; i < b; i += h)
	{
		suml += f(i);

		sumr += f(i + h);

		sumc += f(i + h / 2);

		sumt += (f(i) + f(i + h)) / 2;

		/*if (count == 0 || count == 100)
			simp += f(i);
		else */if (count % 2 == 1)
			simp += f(i - h) + 4 * f(i) + f(i + h);
		
		count++;
	}	
	cout.precision();
	cout << "������ �������: 15.568736474";
	cout << "\n\n��� 10 �����";
	cout << "\n����� ���������������: " << fixed << suml * h;
	cout << "\n����������� ���������������: " << fixed << sumc * h;
	cout << "\n������ ��������������: " << fixed << sumr * h;
	cout << "\n\n��������: " << fixed << sumt * h;
	cout << "\n\n��������: " << fixed << simp * (h / 3);

	suml = 0;
	sumr = 0;
	sumc = 0;
	sumt = 0;
	simp = 0;
	count = 0;
	h = (b - a) / 20;
	// 100 �����
	for (double i = a; i < b; i += h)
	{
		suml += f(i);

		sumr += f(i + h);

		sumc += f(i + h / 2);

		sumt += (f(i) + f(i + h)) / 2;

		/*if (count == 0 || count == 100)
			simp += f(i);
		else */if (count % 2 == 1)
			simp += f(i - h) + 4 * f(i) + f(i + h);
		
		count++;
	}
	cout.precision();
	cout << "\n\n\n��� 20 �����";
	cout << "\n����� ���������������: " << fixed << suml * h;
	cout << "\n����������� ���������������: " << fixed << sumc * h;
	cout << "\n������ ��������������: " << fixed << sumr * h;
	cout << "\n\n��������: " << fixed << sumt * h;
	cout << "\n\n��������: " << fixed << simp * (h / 3);

	suml = 0;
	sumr = 0;
	sumc = 0;
	sumt = 0;
	simp = 0;
	count = 0;
	h = (b - a) / 50;
	// 100 �����
	for (double i = a; i < b; i += h)
	{
		suml += f(i);

		sumr += f(i + h);

		sumc += f(i + h / 2);

		sumt += (f(i) + f(i + h)) / 2;

		/*if (count == 0 || count == 100)
			simp += f(i);
		else */if (count % 2 == 1)
			simp += f(i - h) + 4 * f(i) + f(i + h);
		
		count++;
	}
	cout.precision();
	cout << "\n\n\n��� 50 �����";
	cout << "\n����� ���������������: " << fixed << suml * h;
	cout << "\n����������� ���������������: " << fixed << sumc * h;
	cout << "\n������ ��������������: " << fixed << sumr * h;
	cout << "\n\n��������: " << fixed << sumt * h;
	cout << "\n\n��������: " << fixed << simp * (h / 3);

	suml = 0;
	sumr = 0;
	sumc = 0;
	sumt = 0;
	simp = 0;
	count = 0;
	h = (b - a) / 100;
	// 100 �����
	for (double i = a; i < b; i += h)
	{
		suml += f(i);

		sumr += f(i + h);

		sumc += f(i + h / 2);

		sumt += (f(i) + f(i + h)) / 2;

		/*if (count == 0 || count == 100)
			simp += f(i);
		else */if (count % 2 == 1)
			simp += f(i - h) + 4 * f(i) + f(i + h);
		
		count++;
	}
	cout.precision();
	cout << "\n\n\n��� 100 �����";
	cout << "\n����� ���������������: " << fixed << suml * h;
	cout << "\n����������� ���������������: " << fixed << sumc * h;
	cout << "\n������ ��������������: " << fixed << sumr * h;
	cout << "\n\n��������: " << fixed << sumt * h;
	cout << "\n\n��������: " << fixed << simp * (h / 3);

	suml = 0;
	sumr = 0;
	sumc = 0;
	sumt = 0;
	simp = 0;
	count = 0;
	h = (b - a) / 200;
	// 100 �����
	for (double i = a; i < b; i += h)
	{
		suml += f(i);

		sumr += f(i + h);

		sumc += f(i + h / 2);

		sumt += (f(i) + f(i + h)) / 2;

		/*if (count == 0 || count == 100)
			simp += f(i);
		else */if (count % 2 == 1)
			simp += f(i - h) + 4 * f(i) + f(i + h);
		
		count++;
	}
	cout.precision();
	cout << "\n\n\n��� 200 �����";
	cout << "\n����� ���������������: " << fixed << suml * h;
	cout << "\n����������� ���������������: " << fixed << sumc * h;
	cout << "\n������ ��������������: " << fixed << sumr * h;
	cout << "\n\n��������: " << fixed << sumt * h;
	cout << "\n\n��������: " << fixed << simp * (h / 3);

	suml = 0;
	sumr = 0;
	sumc = 0;
	sumt = 0;
	simp = 0;
	count = 0;
	h = (b - a) / 500;
	// 100 �����
	for (double i = a; i < b; i += h)
	{
		suml += f(i);

		sumr += f(i + h);

		sumc += f(i + h / 2);

		sumt += (f(i) + f(i + h)) / 2;

		/*if (count == 0 || count == 100)
			simp += f(i);
		else */if (count % 2 == 1)
			simp += f(i - h) + 4 * f(i) + f(i + h);
		
		count++;
	}
	cout.precision();
	cout << "\n\n\n��� 500 �����";
	cout << "\n����� ���������������: " << fixed << suml * h;
	cout << "\n����������� ���������������: " << fixed << sumc * h;
	cout << "\n������ ��������������: " << fixed << sumr * h;
	cout << "\n\n��������: " << fixed << sumt * h;
	cout << "\n\n��������: " << fixed << simp * (h / 3);

	suml = 0;
	sumr = 0;
	sumc = 0;
	sumt = 0;
	simp = 0;
	count = 0;
	h = (b - a) / 1000;
	// 100 �����
	for (double i = a; i < b; i += h)
	{
		suml += f(i);

		sumr += f(i + h);

		sumc += f(i + h / 2);

		sumt += (f(i) + f(i + h)) / 2;

		/*if (count == 0 || count == 100)
			simp += f(i);
		else */if (count % 2 == 1)
			simp += f(i - h) + 4 * f(i) + f(i + h);
		
		count++;
	}
	cout.precision();
	cout << "\n\n\n��� 1000 �����";
	cout << "\n����� ���������������: " << fixed << suml * h;
	cout << "\n����������� ���������������: " << fixed << sumc * h;
	cout << "\n������ ��������������: " << fixed << sumr * h;
	cout << "\n\n��������: " << fixed << sumt * h;
	cout << "\n\n��������: " << fixed << simp * (h / 3);

	suml = 0;
	sumr = 0;
	sumc = 0;
	sumt = 0;
	simp = 0;
	count = 0;
	h = (b - a) / 5000;
	// 100 �����
	for (double i = a; i < b; i += h)
	{
		suml += f(i);

		sumr += f(i + h);

		sumc += f(i + h / 2);

		sumt += (f(i) + f(i + h)) / 2;

		/*if (count == 0 || count == 100)
			simp += f(i);
		else */if (count % 2 == 1)
			simp += f(i - h) + 4 * f(i) + f(i + h);
		
		count++;
	}
	cout.precision();
	cout << "\n\n\n��� 5000 �����";
	cout << "\n����� ���������������: " << fixed << suml * h;
	cout << "\n����������� ���������������: " << fixed << sumc * h;
	cout << "\n������ ��������������: " << fixed << sumr * h;
	cout << "\n\n��������: " << fixed << sumt * h;
	cout << "\n\n��������: " << fixed << simp * (h / 3);

	suml = 0;
	sumr = 0;
	sumc = 0;
	sumt = 0;
	simp = 0;
	h = (b - a) / 10000;
	count = 0;
	// 10000 �����
	for (double i = a; i < b; i += h)
	{
		suml += f(i);

		sumr += f(i + h);

		sumc += f(i + h / 2);

		sumt += (f(i) + f(i + h)) / 2;

		/*if (count == 0 || count == 100)
			simp += f(i);
		else */if (count % 2 == 1)
			simp += f(i - h) + 4 * f(i) + f(i + h);
		
		count++;
	}
	cout.precision();
	cout << "\n\n\n��� 10000 �����";
	cout << "\n����� ���������������: " << fixed << suml * h;
	cout << "\n����������� ���������������: " << fixed << sumc * h;
	cout << "\n������ ��������������: " << fixed << sumr * h;
	cout << "\n\n��������: " << fixed << sumt * h;
	cout << "\n\n��������: " << fixed << simp * (h / 3);
}