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
		string from;  //��ʾ��ʼ����
        string to;    //��ʾĿ�����
	public:
		Station(string fr="�ʼ��ʵ�ѧԺ",string t="�ʼ�û��ѧԺ");
		void disp();    //ͬ����Ա���� 
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
		void disp();    //ͬ����Ա���� 
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
		Price(string fr="�ʼ��ʵ�ѧԺ",string t="�ʼ�û��ѧԺ",double m=0);
		void disp();
};
Price::Price(string fr,string t,double m):Station(fr,t),Mile(m)
{
	price=mile<=3?8:8+(int)(2*(mile-3))*0.7+0.7*(2*(mile-3)-(int)(2*(mile-3))==0?0:1);
}
void Price::disp()         //����ͬ�� 
{
	Station::disp();      //ͬ�����������һ�ֳ��ý���취 
	Mile::disp();
	cout<<price<<endl;
}
int main()
{
	string fr,t;
	double m;
	cin>>fr>>t>>m;
	Price A(fr,t,m);
	A.disp();               //���������ͻ�����ͬ����Ա������Ĭ�ϵ����������еģ����Ҫ���û����ͬ��������Ҫ��������ʷ�������A.Mile::disp(); 
	return 0;
}
