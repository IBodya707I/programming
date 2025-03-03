#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
	int a[10][10],i,j,n,**dp,*p[10],s;
	cout<<"enter n ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		p[i]=a[i];
		dp=p;
		for(j=0;j<n;j++)
		{
			*(*(dp+i)+j)=rand()%10;
			cout<<*(*(dp+i)+j)<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	for(i=0;i<n;i++)
	{
		p[i]=a[i];
		dp=p;
		if(i%2==0)
		{
		for(j=0;j<n;j++)
		{
			cout<<*(*(dp+i)+j)<<" ";	
		}
	}
	else
	{
		for(j=n-1;j>=0;j--)
		{
			cout<<*(*(dp+i)+j)<<" ";	
		}
	}
		cout<<endl;
	}
	return 0;
}
