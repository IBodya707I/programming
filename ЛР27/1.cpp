#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
	int i,n,m,k,j;
	cout<<"enter n,m ";
	cin>>n>>m;
	int *a=new int[n];
	int *b=new int[m];
	for(i=0;i<n;i++)
	{
		a[i]=rand()%10;
		cout<<a[i]<<" ";
		if(a[i]%3!=0)
		k++;
	}
	cout<<endl;
	for(i=0;i<m;i++)
	{
		b[i]=rand()%10;
		cout<<b[i]<<" ";
		if(b[i]%3!=0)
		j++;
	}
	cout<<endl;

	if(k>j)
	{
		for(i=0;i<n;i++)
		{
			cout<<a[i]<<" ";
		}
}
	else
	{
		for(i=0;i<m;i++)
		{
			cout<<b[i]<<" ";
		}
	}
	if(k==j)
	cout<<"k=j";
	delete []a;
	delete []b;
	
	return 0;
}
