#include <iostream>
using namespace std;
void function(int a[],int b[],int n=8)
{
	int x,i,j;
	for(i=0;i<n;i++)
	{
		x=rand()%12;
		b[i]=a[x];
		for(j=0;j<i;j++)
		{
			if(b[j]==b[i])
			i--;
		}
	}
	for(i=0;i<n;i++)
	{
		cout<<b[i]<<" ";
	}
}
int main()
{
	int a[12],b[12],n,i,j;
	for(i=0;i<12;i++)
	{
		a[i]=1+rand()%49;
		for(j=0;j<i;j++)
		{
			if(a[i]==a[j])
			i--;
		}
	}
	for(i=0;i<12;i++)
	cout<<a[i]<<" ";
	cout<<endl<<"enter n ";
	cin>>n;
	function(a,b,n);
	return 0;
}
