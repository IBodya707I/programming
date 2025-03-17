#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main()
{
	srand(time(NULL));
	string a="AEIOUYaeiouy";
	string b="BCDFGHJKLMNPQRSTVWXZbcdfghjklmnpqrstvwxz";
	int i,j,n,m,k,x;
	cout<<"enter n ";
	cin>>n;
	char **c=new char*[n];
	for(i=0;i<n;i++)
	c[i]=new char[n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j||i+j==n-1)
			{
				m=rand()%a.length();
				c[i][j]=a[m];
			}
			else
			{
				m=rand()%b.length();
				c[i][j]=b[m];
			}
			cout<<c[i][j]<<" ";
		}
		cout<<endl;
	}
	string d;
	cout<<"enter word "<<endl;
	cin>>d;
	for(i=0;i<n;i++)
	{
		for(j=0;j<=n-d.length();j++)
		{
			x=0;
			for(k=0;k<d.length();k++)
			{
				if(c[i][j+k]==d[k])
				{
					x++;
				}
			}
			if(x==d.length())
			{
				cout<<i<<"."<<j<<" - "<<i<<"."<<j+d.length()-1<<endl;
			}
		}
	}
	for(j=0;j<n;j++)
	{
		for(i=0;i<=n-d.length();i++)
		{
			x=0;
			for(k=0;k<d.length();k++)
			{
				if(c[i+k][j]==d[k])
				{
					x++;
				}
			}
			if(x==d.length())
			{
				cout<<i<<"."<<j<<" - "<<i+d.length()-1<<"."<<j<<endl;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		delete[] c[i];
	}
	delete []c;
	return 0;
}
