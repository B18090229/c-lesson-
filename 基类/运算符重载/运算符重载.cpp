#include <iostream>
#include <stdlib.h>
using namespace std;
class Matrix
{
	private:
		int row;
		int col;
		int **m;
	public:
		Matrix()
		{
			row=0;
			col=0;
			m=NULL;
		};
		Matrix(int r,int c)             //构造函数，基本功 
		{
			row=r;
			col=c;
			m=new int*[r];
			for(int i=0;i<r;i++)
			m[i]=new int [c];
			cout<<"请输入该矩阵元素:"<<endl;
			for(int i=0;i<row;i++)
			{
				for(int j=0;j<col;j++)
				cin>>m[i][j];
			}
		}
		Matrix operator + (const Matrix &bm)
		{
			Matrix temp;                       //申请一个新的变量保存结果，以防破坏am，bm内的值 
			temp.row=bm.row;
			temp.col=bm.col;
			temp.m=new int*[row];
			for(int i=0;i<row;i++)
			temp.m[i]=new int [col];
			if(row!=bm.row||col!=bm.col)
			{
				cout<<"program terminated!"<<endl;         //如果行列不同，直接退出 
				exit(0);
			}
			else
			{
				for(int i=0;i<row;i++)
				{
					for(int j=0;j<col;j++)
					temp.m[i][j]=m[i][j]+bm.m[i][j];
				}
			}
			return temp;
		}
		Matrix operator = (const Matrix &bm)           //题目说要行列不同不赋值，不知道为什么下面还是用到了没有行列值的情况（行列不相等），没办法改吧 
		{
			delete []m;
			row=bm.row;
			col=bm.col;
			m=new int*[row];
			for(int i=0;i<row;i++)
			m[i]=new int [col];
			for(int i=0;i<row;i++)
			{
				for(int j=0;j<col;j++)
				m[i][j]=bm.m[i][j];
			}
			return *this;
		}
		void disp()
		{
			for(int i=0;i<row;i++)
			{
				cout<<'\t';
				for(int j=0;j<col;j++)
					cout<<m[i][j]<<'\t';
				cout<<endl;
			}
		}
		~Matrix()                      //析构函数，回收空间 
		{
			for(int i=0;i<row;i++)
			delete [] m[i];
			delete [] m;
			row=0;
			col=0;
		}		
};
int main()
{
	int row_a,col_a,row_b,col_b;
	cout<<"请输入am矩阵的行数和列数:"<<endl;
	cin>>row_a>>col_a;
	Matrix am(row_a,col_a);
	cout<<"请输入bm矩阵的行数和列数:"<<endl;
	cin>>row_b>>col_b;
	Matrix bm(row_b,col_b),cm;
	cout<<"am:"<<endl;
	am.disp();
	cout<<"bm:"<<endl;
	bm.disp();
	cm=am+bm;
	cout<<"cm=am+bm:"<<endl;
	cm.disp();
	am=bm;
	cout<<"am=bm:"<<endl;
	am.disp();
	return 0;
}
