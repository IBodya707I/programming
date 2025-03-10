#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int min(int *a,int c)
{
	int i,min=a[0];
	for(i=0;i<c;i++)
	{
		if(a[i]<min)
		min=a[i];
	}
	return min;
}
int max(int *a,int c)
{
	int i,max=a[0];
	for(i=0;i<c;i++)
	{
		if(a[i]>max)
		max=a[i];
	}
	return max;
}
int main()
{
	int i,n,m=0,k=0;
	srand(time(NULL));
	cout<<"enter n ";
	cin>>n;
	int *a=new int[n];
	for(i=0;i<n;i++)
	{
		a[i]=-2+rand()%6;
		cout<<a[i]<<" ";
	}
	for(i=0;i<n;i++)
	{
		if(a[i]<0)
		k++;
	}
	int s=n+k;
	int *b=new int[s];
	for(i=0;i<n;i++)
	{
		if(a[i]<0&&i>0)
		{
			b[m]=max(a,i)+min(a,i);
			b[m+1]=a[i];
			m=m+2;
		}
		else
		{
			b[m]=a[i];
			m++;
		}
	}
	cout<<endl;
	for(i=0;i<s;i++)
	{
		cout<<b[i]<<" ";
	}
	delete []a;
	delete []b;
	return 0;
}
