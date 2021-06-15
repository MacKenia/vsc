#ifndef DATE_H
#define DATE_H
#include<iostream>
using namespace std;
class date
{
private:
	int year;
	int month;
	int day;
public:
	string DAte;
	date()
	{
		year = 2021;
		month = 1;
		day = 1;
	}
	void setdate1(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
		while (1)
		{
			if (month < 0 || month>12)
			{
				cout << "月份不存在，请重输：";
				cin >> month;
			}
			else break;
			if (day < 0 || day>30)
			{
				cout << "日期不存在，请重输：";
				cin >> day;
			}
		}
	}
	void tiaozhen()
	{
		if (day < 0)
		{
			month--;
			day += 30;
		}
		if (day<0||day > 30)
		{
			month++;
			day -= 30;
		}
		if (month < 0)
		{
			year--;
			month + -12;
		}
		if (month > 12)
		{
			year++;
			month -= 12;
		}

	}
	date operator+(int a)
	{
		day += a;
		tiaozhen();
		return *this;
	}
	int gety()
	{
		return year;
	}
	int getm()
	{
		return month;
	}
	int getd()
	{
		return day;
	}
};
#endif // !DATE_H
