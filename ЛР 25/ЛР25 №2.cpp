#include <iostream>
using namespace std;
int main()
{
	int a[10],i,n,*r,k=0;
	r=a;
	cout<<"enter n ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>*r;
		r++;
	}
	r=a;
	for(i=0;i<n-2;i++)
	{
		if(*r>*(r+1)&&*(r+1)>*(r+2))
		{
			k++;
			cout<<*r<<" "<<*(r+1)<<" "<<*(r+2)<<endl;
		}
		r++;
	}
	return 0;
}
