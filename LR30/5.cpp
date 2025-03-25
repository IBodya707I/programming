#include <iostream>
#include <stdarg.h>
using namespace std;
void function (int a[],int b[],int k=4,...)
{
	va_list args;
	va_start(args,k);
	int i;
	for(i=0;i<k;i++)
	{
		int x=va_arg(args,int);
		if(a[x]!=b[x])
		cout<<x<<" ";
	}
	va_end(args);
}
void enter(int &x)
{
	cout<<"enter x ";
	cin>>x;
	while(x<0||x>10)
	{
		cout<<"enter again ";
		cin>>x;
	}
}
int main()
{
	int a[]={5,78,9,3,8,2,8,2,8,5,3};
	int b[]={7,32,9,5,8,4,1,9,5,5,2};
	int i,q,e,r,t;
	for(i=0;i<11;i++)
	cout<<a[i]<<" ";
	cout<<endl;
	for(i=0;i<11;i++)
	cout<<b[i]<<" ";
	cout<<endl;
	enter(q);
	enter(e);
	enter(r);
	enter(t);
	function(a,b,4,q,e,r,t);
	return 0;
}
