#include<iostream>
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
class Date                         //����һ������Ҫ�õ��������� 
{
	private:
	int year;
	int month;
	int day;
	public:
	Date()
	{
	}
	Date(int y,int m,int d)                 //���캯������˵ 
	{
		year=y;
		month=m;
		day=d;
	}
	void SetDate(int y,int m,int d)
	{
		year=y;
		month=m;
		day=d;
	}
	int Getyear()
	{
		return year;
	}
	int Getmonth()
	{
		return month;
	}
	int Getday()
	{
		return day;
	}
};
class Product                         //���� 
{
       string name;
       double price;
       Date deptime;
       string factory;
       bool easy_break;
       Date valtime; 
       string color;
       double high;
       static int count;          //��̬�������ԣ�����������͵����������һ����Ա��ͨ�׵Ľ����ǣ�������һ��Product���͵�A����count++����ô������һ��ͬ�����͵�B������countֵҲ��count+1���ֵ�� 
       string num[10]={"One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten"};       //ͨ�����侲̬��Ա������¼�ǵڼ��ι��캯�� 
public:
       Product(string n,double p=0,int depyear=2000,int depmonth=1,int depday=1,string f="unnamed",bool easy=0,int valyear=2000,int valmonth=1,int valday=1,string col="undefined",double h=0)       //���캯�������� 
	   {
	   		cout<<"Constrcting "<<num[count]<<"...."<<endl;
	   		count++;
	   		name=n;
	   		price=p;
	   		deptime.SetDate(depyear,depmonth,depday);
	   		factory=f;
	   		easy_break=easy;
	   		valtime.SetDate(valyear,valmonth,valday);
	   		color=col;
	   		high=h;
	   }
	   void SetProduct(string n,double p=0,int depyear=2000,int depmonth=1,int depday=1,string f="unnamed",bool easy=0,int valyear=2000,int valmonth=1,int valday=1,string col="undefined",double h=0)        //set�����ṩ�޸ĳ�Ա�ӿ� 
	   {
	   		name=n;
	   		price=p;
	   		deptime.SetDate(depyear,depmonth,depday);
	   		factory=f;
	   		easy_break=easy;
	   		valtime.SetDate(valyear,valmonth,valday);
	   		color=col;
	   		high=h;
	   }
       void output(); 
};
int Product::count=0;                   //��Ҫ������������̬���͵Ķ����Աһ��Ҫ����֮���ʼ�� ����Ҫ������Ҫ������Ҫ������ 
void Product::output()                  //������������� 
{
       cout<<name<<" "<<price<<endl;
       cout<<deptime.Getyear()<<"-"<<deptime.Getmonth()<<"-"<<deptime.Getday()<<endl;
       cout<<factory<<" "<<easy_break<<endl;
       cout<<valtime.Getyear()<<"-"<<valtime.Getmonth()<<"-"<<valtime.Getday()<<endl;
} 
int main()
{
       string  s;
       cin>>s;
       Product p1("car");
       Product p2("glass",3.00);
       Product p3("pen",5.00,2009,3,14);
       p1.SetProduct("car",100000.0,2009,3,14,"nanjing",0,2010,10,14,"red",1.5);
       p1.output();
       p2.output();
       p3.output();
       return 0;
}
