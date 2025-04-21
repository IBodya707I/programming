#include <iostream>
using namespace std;
class Matrix
{
	int size;
	int **data;
	public:
	Matrix(int s=3)
	{
		size=s;
		data=new int*[size];
		int i,j;
		for(i=0;i<size;i++)
		{
			for(j=0;j<size;j++)
			{
				data[i]=new int[size];
			}
		}
	}
	~Matrix()
	{
		cout<<"delete"<<endl;
	}
	void RandomFill()
	{
		int min=0,max=0,i,j;
		while(min>=max)
		{
			cout<<"enter min, max ";
			cin>>min>>max;
		}
		for(i=0;i<size;i++)
		{
			for(j=0;j<size;j++)
			{
				data[i][j]=min+rand()%(max-min+1);
			}
		}
	}
	void print()
	{
		int i,j;
		for(i=0;i<size;i++)
		{
			for(j=0;j<size;j++)
			{
				cout<<data[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	friend Matrix operator+(Matrix &a,Matrix &b);
	friend bool operator==(Matrix &a,Matrix &b);
	friend Matrix operator-(Matrix &a,Matrix &b);
	friend Matrix operator*(Matrix &a,Matrix &b);
};
Matrix operator+(Matrix &a,Matrix &b)
	{
		Matrix result(a.size);
		int i,j;
		for(i=0;i<a.size;i++)
		{
			for(j=0;j<a.size;j++)
			{
				result.data[i][j]=a.data[i][j]+b.data[i][j];
			}
		}
		return result;
	}
Matrix operator-(Matrix &a,Matrix &b)
	{
		Matrix result(a.size);
		int i,j;
		for(i=0;i<a.size;i++)
		{
			for(j=0;j<a.size;j++)
			{
				result.data[i][j]=a.data[i][j]-b.data[i][j];
			}
		}
		return result;
	}
Matrix operator*(Matrix &a,Matrix &b)
	{
		Matrix result(a.size);
		int i,j,k;
		for(i=0;i<a.size;i++)
		{
			for(j=0;j<a.size;j++)
			{
				for(k=0;k<a.size;k++)
				{
					result.data[i][j]=result.data[i][j]+a.data[i][k]*b.data[i][j];
				}
			}
		}
		return result;
	}
bool operator==(Matrix &a,Matrix &b)
{
	int i,j;
	for(i=0;i<a.size;i++)
	{
		for(j=0;j<a.size;j++)
		{
			if(a.data[i][j]!=b.data[i][j])
				return false;
		}
	}
	return true;
}
int main()
{
	Matrix a,b;
	a.RandomFill();
	a.print();
	b.RandomFill();
	b.print();
	Matrix c=a+b;
	c.print();
	Matrix d=a-b;
	d.print();
	Matrix e=a*b;
	e.print();
	if(a==b)
		cout<<"a==b"<<endl;
	else
		cout<<"a!=b"<<endl;
	return 0;
}