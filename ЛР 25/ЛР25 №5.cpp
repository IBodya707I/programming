#include <iostream>
using namespace std;
int main()
{
	int a[16],n,i,*r,s=0,j;
	cout<<"enter n ";
	cin>>n;
	r=a;
	for(i=0;i<n;i++)
	{
		cin>>*r;
		r++;
	}
	r=a;
	for(i=0;i<n;i++)
	{
		if(*(r+i)%5==0)
		{	
			n++;
			for(j=n-1;j>i+1;j--)
			{
				*(r+j)=*(r+j-1);
			}
			*(r+i+1)=s;
			s=s+*(r+i);
			i++;
		}
		s=s+*(r+i);
	}
	r=a;
	for(i=0;i<n;i++)
	{
		cout<<*r<<" ";
		r++;
	}
	
	return 0;
}
