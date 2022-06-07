#include<iostream>
#include<math.h>
#include<assert.h>
#include<algorithm>
#include<string>
#include<clocale>
#include<STDLIB.h>
#include<iomanip>
using namespace std;

class safearay
{
private:
    int LIMIT[10];
public:
    void putel(int i, int znach)
    {
        if (isArray(i))
        {
            LIMIT[i] = znach;
        }
    }

    int getel(int i)
    {
        if (isArray(i))
        {
            return LIMIT[i];
        }
        return 0;
    }
    bool isArray(int i)
    {
        if ((i >= 0) && (i <= 9))
        {
            return true;
        }
        else
        {
            cout << "¬не массива";
            return false;
        }
    }
};

int main()
{
    setlocale(LC_ALL, "Rus");
    safearay mas;
    int k, z;
    char e;
    do
    {
        cout << "¬ведите значение элемента массива и его индекс: ";
        cin >> z >> k;
        mas.putel(k, z);
        cout << "\n¬ведите индекс элемента значение которого хотите получить: ";
        cin >> k;
        z = mas.getel(k);
        cout << "Ёлемент под номером " << k << " = " << z << endl;
        cout << endl << "ѕродолжить? (y/n)   ";
        cin >> e;
        cout << endl;
    } while (e != 'n');
}