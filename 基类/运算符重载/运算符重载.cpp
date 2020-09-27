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
		Matrix(int r,int c)             //���캯���������� 
		{
			row=r;
			col=c;
			m=new int*[r];
			for(int i=0;i<r;i++)
			m[i]=new int [c];
			cout<<"������þ���Ԫ��:"<<endl;
			for(int i=0;i<row;i++)
			{
				for(int j=0;j<col;j++)
				cin>>m[i][j];
			}
		}
		Matrix operator + (const Matrix &bm)
		{
			Matrix temp;                       //����һ���µı������������Է��ƻ�am��bm�ڵ�ֵ 
			temp.row=bm.row;
			temp.col=bm.col;
			temp.m=new int*[row];
			for(int i=0;i<row;i++)
			temp.m[i]=new int [col];
			if(row!=bm.row||col!=bm.col)
			{
				cout<<"program terminated!"<<endl;         //������в�ͬ��ֱ���˳� 
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
		Matrix operator = (const Matrix &bm)           //��Ŀ˵Ҫ���в�ͬ����ֵ����֪��Ϊʲô���滹���õ���û������ֵ����������в���ȣ���û�취�İ� 
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
		~Matrix()                      //�������������տռ� 
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
	cout<<"������am���������������:"<<endl;
	cin>>row_a>>col_a;
	Matrix am(row_a,col_a);
	cout<<"������bm���������������:"<<endl;
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
