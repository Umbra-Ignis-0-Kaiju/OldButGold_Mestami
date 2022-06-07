#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <locale>
#define eps 0.000001

using namespace std;

class Point
{
public:
    double x, y;
    Point(double x = 0, double y = 0) :x(x), y(y) {}
    Point operator + (Point a)
    {
        return Point(a.x + x, a.y + y);
    }
    Point operator - (Point a)
    {
        return Point(x - a.x, y - a.y);
    }
    bool operator < (const Point& a) const
    {
        if (x == a.x)
            return y < a.y;
        return x < a.x;
    }
    bool operator == (const Point& a) const
    {
        if (x == a.x && y == a.y)
            return 1;
        return 0;
    }
    bool operator != (const Point& a) const
    {
        if (x == a.x && y == a.y)
            return 0;
        return 1;
    }
};
    ostream& operator << (ostream& out, Point lul)
    {
        out << "(" << lul.x << ", " << lul.y << ")";
        return out;
    }

vector <Point> ::iterator poly;
vector <Point> ::iterator unpoly;

typedef Point Vector;

double cross(Vector a, Vector b)
{
    return a.x * b.y - a.y * b.x;
}

double dot(Vector a, Vector b)
{
    return a.x * b.x + a.y * b.y;
}

bool isclock(Point p0, Point p1, Point p2)
{
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if (cross(a, b) < -eps) return true;
    return false;
}

double getDistance(Point a, Point b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

typedef vector<Point> Polygon;
Polygon andrew(Polygon s)
{
    Polygon u, l;
    if (s.size() < 3) return s;
    sort(s.begin(), s.end());
    u.push_back(s[0]);
    u.push_back(s[1]);
    l.push_back(s[s.size() - 1]);
    l.push_back(s[s.size() - 2]);
    //printf("l[n-2]:%.2f %.2f\nl[n-1]:%.2f %.2f\n", l[l.size() - 2].x, l[l.size() - 2].y, l[l.size() - 1].x, l[l.size() - 1].y);
    for (int i = 2; i < s.size(); i++)
    {
        for (int n = u.size(); n >= 2 && isclock(u[n - 2], u[n - 1], s[i]) != true; n--)
        {
           // cout << u[n - 2].x << ' ' << u[n - 2].y << '\n' << u[n - 1].x << u[n - 1].y << endl;
            u.pop_back();
        }
        u.push_back(s[i]);
    }
    for (int i = s.size() - 3; i >= 0; i--)
    {
        cout << i << endl;
        for (int n = l.size(); n >= 2 && isclock(l[n - 2], l[n - 1], s[i]) != true; n--)
        {
            //cout << i << endl;
            //printf("del:\nl[n-2]:%.2f %.2f\nl[n-1]:%.2f %.2f\n", l[n - 2].x, l[n - 2].y, l[n - 1].x, l[n - 1].y);

            l.pop_back();
        }

        l.push_back(s[i]);
    }
    //    for(auto &p : u) printf("%.2f %.2f\n",p.x,p.y);
    //    printf("yes\n");
    //    for(auto &p : l) printf("%.2f %.2f\n",p.x,p.y);

    for (int i = 1; i < u.size() - 1; i++) l.push_back(u[i]);
    return l;
}

Polygon unandrew(Polygon one, Polygon two)
{
    Polygon t;
    bool it;
    for (int i = 0; i < one.size(); i++)
    {
        it = 0;
        for (int j = 0; j < two.size(); j++)
            if (one[i].x == two[j].x && one[i].y == two[j].y)
                it = 1;
        if (it == 0)
            t.push_back(one[i]);
    }
    return t;
}
bool find(Polygon &mas, Point obj)
{
    unpoly = mas.begin();
    for (; unpoly != mas.end(); unpoly++)
        if (*unpoly == obj)
            break;
    if (unpoly == mas.end())
        return 0;
    else if (*unpoly != obj)
        return 0;
    return 1;
}


int main()
{
    setlocale(LC_ALL, "Ru");
    int f;
    char sch = 'y';
    bool it = false;
    Polygon mas;
    Polygon obol;
    Polygon vne;
    Point temp;
    while (sch == 'y')
    {
        cout << "\n����� �� ������� ������ ���������������:"
            << "\n1 - ������� ������ ���������"
            << "\n2 - ������� �������� �������� �� ��������� ���������"
            << "\n3 - ���������� ����� �� ���������"
            << "\n4 - �������� ����� �� ��������"
            << "\n5 - ������� ���������� ����� � �������� ��������"
            << "\n6 - ������� ������ ����� �������� ��������"
            << "\n7 - ������������ �������� ����� ������������ �������� �������"
            << "\n8 - �������������� �������� ��������\n";
        cin >> f;
        if (it == false && f == 1)
            it = true;
        else if (it == false)
            cout << "��������� ��� �� �������(\n";
        else if (it == true && f == 1)
        {
            mas.clear();
            obol.clear();
            vne.clear();
        }
        else
            switch (f)
            {
            case 2:
                obol = andrew(mas);
                vne = unandrew(mas, obol);
                break;
            case 3:
                cout << "\n������� ���������� ����� ������� ������ ��������: ";
                cin >> temp.x >> temp.y;
                if (mas.size() == 0)
                {
                    cout << "\n����� ���������.";
                    mas.push_back(temp);
                }
                else if (find(mas, temp))
                    cout << "\n������ ����� ��� ����������.";
                else
                {
                    cout << "\n����� ���������.";
                    mas.push_back(temp);
                }
                break;
            case 4:
                cout << "\n������� ���������� ����� ������� ������ �������: ";
                cin >> temp.x >> temp.y;
                if (find(mas, temp))
                    mas.erase(unpoly);
                else
                    cout << "\n����� �� ����������.";
                break;
            case 5:
                cout << "\n� ������� �������� �������� " << obol.size() << " ���������";
                break;
            case 6:
                if (obol.size() == 0)
                {
                    cout << "\n�������� �� �������";
                    break;
                }
                cout << "\n�������� �������� ��������:";
                poly = obol.begin();
                for (; poly != obol.end(); poly++)
                    cout << endl << *poly;
                break;
            case 7:
                //��� ��� ��������������� ��������� ���, ��� ��� ����
                break;
            case 8:
                //��� ��� ��������������� ��������� ���, ��� ��� ����
                break;
            }
        cout << "\n������ ���������� ������ � ����������? (y/n)   ";
        cin >> sch;
    }
}