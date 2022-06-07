#include <iostream>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <locale.h>
#include <iterator>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

FILE* fp;
void read(int **mas, int size)
{
	fopen_s(&fp, "Graf.txt", "r");
	if (fp == NULL)
		cout << "Cannot open file";
	else
	{
		fscanf_s(fp, "%d", &size);
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				fscanf_s(fp, "%d", &mas[i][j]);
	}
	fclose(fp);
}
void findWay(int a, int b, int** DUG, int N)
{
	a -= 1;
	b -= 1;
	fopen_s(&fp, "Graf.txt", "at");
	int *FIKS = new int[N];
	int *MIN_WEG = new int[N];
	int *VON_PUNKT = new int[N];
	char c[4];
	c[0] = ' ';
	c[1] = '-';
	c[2] = '>';
	c[3] = '\n';
	for (int i = 0; i < N; i++)
	{
		if (i == a)
		{
			FIKS[i] = 1;
			VON_PUNKT[i] = 0;
		}
		else
		{
			FIKS[i] = 0;
			VON_PUNKT[i] = a;
		}
	}
	MIN_WEG = DUG[a];

	int temp;
	bool check = 1; 
	while (check)
	{
		temp = (2 << (sizeof(int) * 8 - 2)) - 1;
		for (int i = 0; i < N; i++)
			if (FIKS[i] == 0 && temp == (2 << (sizeof(int) * 8 - 2)) - 1)
				temp = i;
			else if (FIKS[i] == 0 && MIN_WEG[temp] > MIN_WEG[i])
				temp = i;
		FIKS[temp] = 1;
		for (int i = 0; i < N; i++)
			if (MIN_WEG[i] > MIN_WEG[temp] + DUG[temp][i] && DUG[temp][i] != 0)
			{
				MIN_WEG[i] = MIN_WEG[temp] + DUG[temp][i];
				VON_PUNKT[i] = temp;
			}
		
		check = 0;
		for (int i = 0; i < N; i++)
			if (FIKS[i] == 0)
				check = 1;
	}

	cout << "\nДлина маршрута: " << MIN_WEG[b] << endl;
	temp = b;
	int co;
	co = MIN_WEG[b];
	fwrite(&c[3], sizeof(char), 1, fp);
	fprintf(fp, "%d", co);
	fwrite(&c[0], sizeof(char), 1, fp);
	fwrite(&c[0], sizeof(char), 1, fp);
	fwrite(&c[0], sizeof(char), 1, fp);
	co = a + 1;
	cout << endl << a + 1 << " -> ";
	fprintf(fp, "%d", co);
	fwrite(&c[0], sizeof(char), 1, fp);
	fwrite(&c[1], sizeof(char), 1, fp);
	fwrite(&c[2], sizeof(char), 1, fp);
	fwrite(&c[0], sizeof(char), 1, fp);
	while (1)
	{
			temp = VON_PUNKT[temp];
			if (temp == 0 || temp == a)
				break;
			co = temp + 1;
			fprintf(fp, "%d", co);
			fwrite(&c[0], sizeof(char), 1, fp);
			fwrite(&c[1], sizeof(char), 1, fp);
			fwrite(&c[2], sizeof(char), 1, fp);
			fwrite(&c[0], sizeof(char), 1, fp);
			cout << temp + 1 << " -> ";
	}
	cout << b + 1 << endl;
	co = b + 1;
	fprintf(fp, "%d", co);
	fclose(fp);
}


int main()
{	
	setlocale(LC_ALL, "Rus");
	int size = 0;
	fopen_s(&fp, "Graf.txt", "r");
	if (fp == NULL)
		cout << "Cannot open file";
	else
		fscanf_s(fp, "%d", &size);
	fclose(fp);
	int** mas = new  int*[size];
	for (int i = 0; i < size; i++)
		mas[i] = new int[size];
	read(mas, size);
	cout << size << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << mas[i][j] << " ";
		cout << endl;
	}
	int a, b;
	cin >> a >> b;
	findWay(a, b, mas, size);
 }