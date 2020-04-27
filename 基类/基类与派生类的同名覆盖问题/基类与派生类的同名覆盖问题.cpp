#include<iostream>
#include<sstream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<ctime>
#include<bitset>
#include<iterator>
using namespace std;
class Station
{
	protected:
		string from;  //表示起始地名
        string to;    //表示目标地名
	public:
		Station(string fr="皇家邮电学院",string t="皇家没电学院");
		void disp();    //同名成员函数 
};
Station::Station(string fr,string t)
{
	from=fr;
	to=t;
}
void Station::disp()
{
	cout<<from<<" "<<to<<" ";
}
class Mile
{
	protected:
		double mile;
	public:
		Mile(double m=0);
		void disp();    //同名成员函数 
};
Mile::Mile(double m)
{
	mile=m;
}
void Mile::disp()
{
	cout<<mile<<" ";
}
class Price:public Station,public Mile
{
	double price;
	public:
		Price(string fr="皇家邮电学院",string t="皇家没电学院",double m=0);
		void disp();
};
Price::Price(string fr,string t,double m):Station(fr,t),Mile(m)
{
	price=mile<=3?8:8+(int)(2*(mile-3))*0.7+0.7*(2*(mile-3)-(int)(2*(mile-3))==0?0:1);
}
void Price::disp()         //又是同名 
{
	Station::disp();      //同名覆盖问题的一种常用解决办法 
	Mile::disp();
	cout<<price<<endl;
}
int main()
{
	string fr,t;
	double m;
	cin>>fr>>t>>m;
	Price A(fr,t,m);
	A.disp();               //如果派生类和基类有同名成员函数，默认调用派生类中的，如果要调用基类的同名函数，要加上域访问符，例：A.Mile::disp(); 
	return 0;
}
