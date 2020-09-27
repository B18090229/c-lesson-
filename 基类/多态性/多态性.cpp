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
class shape{
	public: 
	virtual double volume()=0;                     //纯虚函数定义，注：含有纯虚函数的类叫做抽象类 
};
class cylinder:public shape
{
	private:
		double r,h;
	public:
	cylinder(){}
	cylinder(double r1,double h1)
	{
		r=r1;
		h=h1;
	}
	double volume()                       //对于虚函数的重载，如果不实现，怎此类也为抽象类 
	{
		return  3.1415*r*r*h;
	}
};
class sphere:public shape                   
{
	private:
		double r;
	public:
		sphere(){}
		sphere(int x)
		{
			r=x;
		}
		double volume()                        //对于虚函数的重载，如果不实现，怎此类也为抽象类 
		{
			return 4.0/3.0*3.1415*r*r*r;
		}
};
int main() {
   shape *p;
   double  r,h;
   cout<<"input r & h："<<endl;
   cin>>r>>h;
   cylinder cy(r,h);
   sphere sp(r);
   p=&cy;                                     //因为已经定义了虚函数，所以编译器在编译的时候会自动跳转到对应类输出响应的虚函数的实现；注意这里有一个坑，多态性与赋值兼容原理的区别 
   cout<<p-> volume()<<endl;    		
   p=&sp;
   cout<<p-> volume()<<endl; 
   return 0;
}
