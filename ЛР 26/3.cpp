#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
	int a[10][10],i,j,n,**dp,*p[10],s,min,x,b[10];
	cout<<"enter n ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		p[i]=a[i];
		dp=p;
		for(j=0;j<n;j++)
		{
			*(*(dp+i)+j)=-10+rand()%21;
			cout<<*(*(dp+i)+j)<<" ";
		}
		cout<<endl;
	}
	for(i=0;i<n;i++)
	{
		p[i]=a[i];
		dp=p;
		min=*(*(dp+i)+0);
		x=1;
		for(j=0;j<n;j++)
		{
			if(min>*(*(dp+i)+j))
			{
				min=*(*(dp+i)+j);
				x=j+1;
			}
		}
		b[i]=x;
	}
	cout<<endl;
	for(i=0;i<n;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}
