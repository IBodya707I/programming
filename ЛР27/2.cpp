#include <iostream>
#include <stdlib.h>
using namespace std;
void func(int *a,int n)
{
	int i,j=0,m,*p;
	p=a;
	for(i=0;i<n;i++)
	{
		if(*p%2==0&&(i+1)%2!=0)
		{
			m++;
		}
		p++;
	}
	p=a;
	int *b=new int[m];
	for(i=0;i<n;i++)
	{
		if(*p%2==0&&(i+1)%2!=0)
		{
			b[j]=*p;
			cout<<b[j]<<" ";
			j++;
		}
		p++;
	}
	delete []b;
}
int main()
{
	int i,n;
	cout<<"enter n ";
	cin>>n;
	int *a=new int[n];
	for(i=0;i<n;i++)
	{
		a[i]=rand()%10;
		cout<<a[i]<<" ";
	}
	cout<<endl;
	func(a,n);
	delete []a;
	return 0;
}
