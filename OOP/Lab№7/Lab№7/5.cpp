#include<iostream>
#include<math.h>
#include<sstream>
#include<assert.h>
#include<algorithm>
#include<string>
#include<clocale>
#include<STDLIB.h>
#include<iomanip>
using namespace std;

class c_time

{
private:      int hrs, mins, secs;     public:

    c_time() :hrs(0), mins(0), secs(0) //конструктор без аргументов 
    {};
    //конструктор с тремя аргументами     
    c_time(int h, int m, int s) :hrs(h), mins(m), secs(s) {};
    void display()const           //формат 11:59:59       
    {
		cout << endl << setw(2) << setfill('0') << hrs << ":" << setw(2) << setfill('0') << mins << ":" << setw(2) << setfill('0') << secs;
    }
    //void add_time(c_time t1, c_time t2)//сложить две переменные 
    //{

    //    secs = t1.secs + t2.secs;     //сложить секунды       
    //    if (secs > 59)               //если перебор, 
    //    {
    //        secs -= 60; mins++;
    //    }   //прибавить минуту       
    //    mins += t1.mins + t2.mins;   //сложить минуты       
    //    if (mins > 59)        //если слишком много минут,         
    //    {
    //        mins -= 60; hrs++;
    //    }   //прибавить час        
    //    hrs += t1.hrs + t2.hrs; //сложить часы 
    //}
	c_time operator + (c_time t2)
	{
		long totalsecs = (hrs * 3600) + (mins * 60) + secs + (t2.hrs * 3600) + (t2.mins * 60) + t2.secs;
		int h = totalsecs / (3600);
		int m = totalsecs % (3600) / 60;
		int s = totalsecs % (3600) % 60;
		return c_time(h, m, s);
	}
	c_time operator ++ ()
	{
		++hrs; ++mins; ++secs;
		if (secs > 59)
		{
	        secs -= 60; mins++;
	    }
	    if (mins > 59)
	    {
	        mins -= 60; hrs++;
	    }
		return c_time(hrs, mins, secs);
	}
	c_time operator -- ()
	{
		--hrs, --mins, --secs;
		if (secs < 0)
		{
			secs += 60; mins--;
		}
		if (mins < 0)
		{
			mins += 60; hrs--;
		}
		return c_time(hrs, mins, secs);
	}
	c_time operator ++ (int)
	{
		int thrs = hrs, tmins = mins, tsecs = secs;
		++hrs; ++mins; ++secs;
		if (secs > 59)
		{
			secs -= 60; mins++;
		}
		if (mins > 59)
		{
			mins -= 60; hrs++;
		}
		return c_time(thrs, tmins, tsecs);
	}
	c_time operator -- (int)
	{
		int thrs = hrs, tmins = mins, tsecs = secs;
		--hrs, --mins, --secs;
		if (secs < 0)
		{
			secs += 60; mins--;
		}
		if (mins < 0)
		{
			mins += 60; hrs--;
		}
		return c_time(thrs, tmins, tsecs);
	}
    };


int main()
{
	c_time time_1(13, 3, 7), time_2(3, 17, 4);
	c_time stime;
	stime = time_1 + time_2;
	time_1.display();
	time_2.display();
	stime.display();
	cout << endl;
	++time_1; time_1.display();
	--time_2; time_2.display();
	cout << endl;
	stime = time_1++; stime.display(); cout << endl << "="; time_1.display();
	cout << endl;
	stime = time_2--; stime.display(); cout << endl << "="; time_2.display();
	return 0;
}