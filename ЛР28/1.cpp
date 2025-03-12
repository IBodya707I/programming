#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
	int **a,n,i,j;
	float s=0,x;
	cout<<"enter n ";  
	cin>>n;
	a=new int*[n];
	for(i=0;i<n;i++)
	a[i]=new int[n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			a[i][j]=rand()%10;
			cout<<a[i][j]<<" ";
			s=s+a[i][j];
		}
		cout<<endl;
	}
	x=s/(n*n);
	cout<<x;
	int *b=new int[n];
	for(i=0;i<n;i++)
	{
		int k=0;
		for(j=0;j<n;j++)
		{
			if(a[i][j]<x)
			k++;
		}
		b[i]=k;
	}	
	cout<<endl;
	for(i=0;i<n;i++)
	{
		cout<<b[i]<<" ";
	}
	for(i=0;i<n;i++)
	delete[]a[i];
	delete []a;	
	delete []b;
	return 0;
}
