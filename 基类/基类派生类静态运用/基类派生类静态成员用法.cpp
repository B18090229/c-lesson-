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
class Date                         //定义一个下面要用到的日期类 
{
	private:
	int year;
	int month;
	int day;
	public:
	Date()
	{
	}
	Date(int y,int m,int d)                 //构造函数不多说 
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
class Product                         //主类 
{
       string name;
       double price;
       Date deptime;
       string factory;
       bool easy_break;
       Date valtime; 
       string color;
       double high;
       static int count;          //静态函数特性，所有这个类型的类对象公用这一个成员，通俗的讲就是，我申请一个Product类型的A，把count++，那么再申请一个同样类型的B，它的count值也是count+1后的值。 
       string num[10]={"One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten"};       //通过搭配静态成员，来记录是第几次构造函数 
public:
       Product(string n,double p=0,int depyear=2000,int depmonth=1,int depday=1,string f="unnamed",bool easy=0,int valyear=2000,int valmonth=1,int valday=1,string col="undefined",double h=0)       //构造函数不解释 
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
	   void SetProduct(string n,double p=0,int depyear=2000,int depmonth=1,int depday=1,string f="unnamed",bool easy=0,int valyear=2000,int valmonth=1,int valday=1,string col="undefined",double h=0)        //set函数提供修改成员接口 
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
int Product::count=0;                   //重要！！！！！静态类型的对象成员一定要在类之外初始化 （重要！！重要！！重要！！） 
void Product::output()                  //输出函数不解释 
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
