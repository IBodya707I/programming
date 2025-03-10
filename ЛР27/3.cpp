#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
	int i,n,k=0,j,m=0,s;
	cout<<"Enter n ";
	cin>>n;
	float *a=new float[n];
	for(i=0;i<n;i++)
	{
		a[i]=rand()%100;
		a[i]=a[i]/10;
		cout<<a[i]<<" ";
	}
	cout<<endl;
	for(i=0;i<n;i++)
	{
		int c=a[i];
		if(c%2==0)
		k++;
	}
	int e;
	float *b=new float[k];
	for(i=0;i<n;i++)
	{
		int c=a[i];
		float v=a[i];
		e=m-1;
		if(c%2==0)
		{
		while(e>=0&&b[e]>v)
		{
			b[e+1]=b[e];
			e--;
		}
		b[e+1]=v;
		m++;
	}
	}
	for(i=0;i<m;i++)
	{
		cout<<b[i]<<" ";
	}
	delete []a;
	delete []b;
	return 0;
}
