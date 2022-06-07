#include <iostream>
#include <conio.h>
using namespace std;
////////////////////////////////////////////////////////////////
class queue
{
private:
    static const int MAX = 10;
    int q[MAX];
    int head;
    int tail;
    unsigned int el;
public:
    queue()
    {
        head = 0; 
        tail = -1; 
        el = 0;
    }
    void put(int var)
    {
        if (tail == MAX - 1)
            tail = -1;
        if (el == MAX)
            cout << "Очередь переполнена" << endl;
        else
        {
            q[++tail] = var; 
            el++;
        }
    }
    int get()
    {
        if (head == MAX)
            head = 0;
        if (el == 0)
        {
            cout << "Очередь пуста" << endl; 
            return 0;
        }
        else 
        { 
            el--; 
            return q[head++]; 
        }
    }
};
////////////////////////////////////////////////////////////////
int main()
{
    setlocale(LC_ALL, "Rus");
    queue q;
    char x;
    int n;
    do
    {
        cout << "\nВвести/вывести значение (p/g)" << endl; 
        cin >> x; 
        cout << endl;
        switch (x)
        {
        case 'p':
        {
            cout << "Введите значение: ";
            cin >> n;
            q.put(n);
            break;
        }
        case 'g':
        {
            n = q.get();
            if (n != 0)
                cout << "Значение: " << n << endl;
            break;
        }
        case '0':
            return 0;
        }
    } while (true);
    return 0;
}