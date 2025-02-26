#include <iostream>
using namespace std;
int main()
{
	int a[12],i,n,*r;
	cout<<"enter n ";
	cin>>n;
	r=a;
	for(i=0;i<n;i++)
	{
		cin>>*r;
		r++;
	}
	r=a;
	int min=a[0];
	for(i=1;i<n+1;i++)
	{
		if(i%2==0&&*r<min)
		min=*r;
		r++;	
	}
	cout<<"min z parnum nomerom = "<<min;
	return 0;
}
