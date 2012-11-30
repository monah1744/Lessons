#include "c_2_2.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

using namespace std;
int main ()
{
	Date t(2012,01,01);
	cout<<t.GetDate()<<endl;
	Date t2(2013, 01, 01);
	cout<<t2.GetDate()<<endl;
	//t2.GetFuture(100);
	cout<<t2.GetDate()<<endl;
	//t=t+100;
	int z=int(t);
	int z1=int(t2);
	int z2=t-t2;
	cout<<t.GetDate()<<endl;
	cout<<(z)<<endl;
	cout<<(z1)<<endl;
	cout<<(z2)<<endl;
}