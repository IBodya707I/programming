#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
	int a[10][10],i,j,n,**dp,*p[10],max,min;
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
	max=a[0][0];
	min=a[0][n-1];
	for(i=0;i<n-1;i++)
	{
		p[i]=a[i];
		dp=p;
		for(j=0;j<n-1;j++)
		{
			if(i==j&&*(*(dp+i+1)+j+1)>max)
			{
				max=*(*(dp+i+1)+j+1);
				
			}	
		}
	}
	for(i=0;i<n-1;i++)
	{
		p[i]=a[i];
		dp=p;
		for(j=0;j<n-1;j++)
		{
			if(i+j+1==n&&*(*(dp+i-1)+j-1)<min)
			{
				min=*(*(dp+i+1)+j-1);
				
			}	
		}
	}
	cout<<"max = "<<max<<"   min = "<<min<<endl;
	cout<<max-min;
	
	return 0;
}
