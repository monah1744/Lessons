#include "c_2_2.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <Windows.h>
#include <time.h>

Date::Date()
{
	time_t rawtime;
	struct tm * timeinfo;
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	m_year = timeinfo->tm_year+1900;
	m_month = timeinfo->tm_mon;
	m_day = timeinfo->tm_mday;
}
Date::Date(int _year, int _month, int _day)
{
	m_year = _year;
	m_month = _month;
	m_day = _day;
}

Date::~Date()
{

}
char * Date::GetDate()
{
	char *tmp = new char[20];
	char *t2 = new char [10];
	strcpy(tmp,itoa(m_day,t2,10));
	strcat(tmp,".");
	strcat(tmp,itoa(m_month,t2,10));
	strcat(tmp,".");
	strcat(tmp,itoa(m_year,t2,10));
	delete [] t2;
	return tmp;
}
void Date::GetFuture (int _days)
{
	for (int i=1;i<=_days;i++)
		Date::next();
}
Date Date::operator+ (int n)
{
	Date T = *this;
	for (int i=1;i<=n;i++)
		T.next();
	return T;
}
int Date::operator- (Date n)
{
	int T = int(*this);
	int T1 = int(n);
	return (T-T1);
}
Date::operator int ()
{
	int T = 0;
	for (int i=m_year-1;i>=1;i--)
	{
		if ((i%4)==0&&(i%100!=0)) T++;
		T+=365;
	}
	if ((m_month%4)==0&&(m_month%100!=0)&&(m_month>2)) T++;
	for (int i=m_month-1;i>=1;i--)
	{
		T+=days[i];
	}
	for (int i=m_day-1;i>=1;i--)
	{
		T=T++;
	}
	T++;
	return T;
}
Date::operator long ()
{
	long int T = 0;
	for (int i=(m_year-1);i>=1;i--)
	{
		if (((i%4)==0)&&(i%100!=0)) T++;
		T+=365;
	}
	if ((m_year%4)==0&&(m_year%100!=0)&&(m_month>2)) T++;
	for (int i=(m_month-1);i>=1;i--)
	{
		T+=days[i];
	}
	for (int i=m_day;i>=1;i--)
	{
		T=T++;
	}
	T++;
	return T;
}
void Date::next() 
	{
		m_day++;
		if (m_day > days[m_month]) 
		{
			if ((m_month==2) && (m_day==29) && (m_year%4==0)) return;
			m_day=1;
			m_month++; // К первому числа следующего месяца
			if (m_month == 13)
			{ // К первому января следующего года
				m_month = 1; m_year++;
			}
		}
	}
int Date::days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31};