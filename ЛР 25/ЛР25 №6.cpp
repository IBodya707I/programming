#include <iostream>
using namespace std;
int main()
{
	int a[16],n,i,*r,j;
	cout<<"enter n ";
	cin>>n;
	r=a;
	for(i=0;i<n;i++)
	{
		cin>>*r;
		r++;
	}
	r=a;
	for(i=0;i<n;)
	{
		for(j=0;j<n;)
		{
			if(*(r+i)<*(r+j))
			{
				swap(*(r+i),*(r+j));
			}
			j=j+2;
		}
		i=i+2;
	}
	for(i=1;i<n;)
	{
		for(j=1;j<n;)
		{
			if(*(r+i)>*(r+j))
			{
				swap(*(r+i),*(r+j));
			}
			j=j+2;
		}
		i=i+2;
	}
	for(i=0;i<n;i++)
	{
		cout<<*r<<" ";
		r++;
	}	
	return 0;
}
