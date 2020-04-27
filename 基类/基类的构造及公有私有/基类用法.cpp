#include<iostream>
#include<cmath>
#include<queue>
using namespace std;
class Employee
{
	protected:
		string name;   //����
		int working_years;   //����
	public:
		Employee(string nm="unnamed",int wy=0);
		string Getname();
		double ComputePay();    //���乤�ʣ����ǣ�����*35
		void SetWorkyears(int wy);
};
Employee::Employee(string nm,int wy)
{
  	name=nm;
  	working_years=wy;
}
string Employee::Getname()
{
  	return name;
}
double Employee::ComputePay()
{
  return 35*working_years;
}
void Employee::SetWorkyears(int wy)
{
  	working_years=wy;
}
class Worker: public Employee
{
	private:
	double pay_per_hour;  //ÿСʱ���ʶ�
	int work_time;             //���¹���ʱ��
	public:
	Worker(string nm="unnamed",int wy=0,int wt=0,double pa=0);
	double count_pay();             //���㹤�ʣ�������˵���ļ������
	void SetWorktime(int wt);    //���õ��¹���ʱ��
	void Setpay_per_hour(int x);  //����ÿСʱ���ʶ�
};
Worker::Worker(string nm,int wy,int wt,double pa):Employee(nm,wy)
{
	pay_per_hour=pa;
	work_time=wt;
}
double Worker::count_pay()
{
	return pay_per_hour*work_time+ComputePay();
}
void Worker::SetWorktime(int wt)
{
	work_time=wt;
}
void Worker::Setpay_per_hour(int x)
{
	pay_per_hour=x;
}
class SalesPerson:public Employee
{
	private:
		double pay_per_hour;   //ÿСʱ���ʶ�
		double saleroom;       //�����۳���Ʒ���
		int work_time;         //���¹���ʱ��
	public:
		SalesPerson(string nm="unnamed",int wy=0,double ph=0,double sr=0,int wt=0);
		double count_pay();           //���㹤�ʣ�������˵���ļ������
		void SetWorktime(int wt);     //���õ��¹���ʱ��
		void Setpay_per_hour(int x);  //����ÿСʱ���ʶ�
		void Setsalesroom(double sr); //���õ����۳���Ʒ���
};
SalesPerson::SalesPerson(string nm,int wy,double ph,double sr,int wt):Employee(nm,wy)
{
	pay_per_hour=ph;
	saleroom=sr;
	work_time=wt;
}
double SalesPerson::count_pay()
{
	return work_time*pay_per_hour+ComputePay()+0.01*saleroom;		
}
void SalesPerson::SetWorktime(int wt)
{
	work_time=wt;
}
void SalesPerson::Setpay_per_hour(int x)
{
	pay_per_hour=x;
}
void SalesPerson::Setsalesroom(double sr)
{
	saleroom=sr;
}
class Manager:public Employee
{
	public:
		Manager(string nm="unnamed",int wy=0);
		double count_pay();
};
Manager::Manager(string nm,int wy):Employee(nm,wy){}
double Manager::count_pay()
{
	return 1000+ComputePay();
}
int main()
{
	Worker work("zhangqiang",3,200);
	work.Setpay_per_hour(50);
	cout<<"����="<<work.count_pay()<<endl;
	work.SetWorktime(180);
	work.SetWorkyears(10);
	work.Setpay_per_hour(30);
	cout<<work.Getname()<<"  "<<work.count_pay()<<endl;


	SalesPerson sales("wangjun",5,300000,25);



	sales.SetWorktime(40);
	sales.Setpay_per_hour(80);
	sales.Setsalesroom(450000);
	cout<<sales.Getname()<<"  "<<sales.count_pay()<<endl;



	Manager mana("sunchao",20);
	cout<<mana.Getname()<<"  "<<mana.count_pay()<<endl;
	return 0;
}
