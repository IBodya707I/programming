#include <iostream>
using namespace std;
int main()
{
	int a[16],n,i,*r,k=0;
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
		if(*r<*(r+1))
		{
			cout<<i+2<<" ";
			k++;	
		}
		r++;
	}
	cout<<endl<<"k = "<<k;
	return 0;
}
