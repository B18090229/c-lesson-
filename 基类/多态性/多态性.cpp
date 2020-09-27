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
	virtual double volume()=0;                     //���麯�����壬ע�����д��麯��������������� 
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
	double volume()                       //�����麯�������أ������ʵ�֣�������ҲΪ������ 
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
		double volume()                        //�����麯�������أ������ʵ�֣�������ҲΪ������ 
		{
			return 4.0/3.0*3.1415*r*r*r;
		}
};
int main() {
   shape *p;
   double  r,h;
   cout<<"input r & h��"<<endl;
   cin>>r>>h;
   cylinder cy(r,h);
   sphere sp(r);
   p=&cy;                                     //��Ϊ�Ѿ��������麯�������Ա������ڱ����ʱ����Զ���ת����Ӧ�������Ӧ���麯����ʵ�֣�ע��������һ���ӣ���̬���븳ֵ����ԭ������� 
   cout<<p-> volume()<<endl;    		
   p=&sp;
   cout<<p-> volume()<<endl; 
   return 0;
}
