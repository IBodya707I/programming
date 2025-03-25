#include <iostream>
using namespace std;
void function(int a[],int b[],int c=4, int d=10)
{
	int x=0,i;
	for(i=c;i<=d;i++)
	{
		b[x]=a[i];
		x++;
	}
}
int main()
{
	int a[]={4,7,9,17,22,5,32,4,9,3,15,7};
	int b[12];
	int c,d,i;
	cout<<"enter c,d ";
	cin>>c>>d;
	while(c<0||c>=d||c>12||d>12)
	{
		cout<<"enter c,d ";
		cin>>c>>d;
	}
	function(a,b,c,d);\
	for(i=0;i<12;i++)
	cout<<a[i]<<" ";
	cout<<endl;
	for(i=0;i<d-c+1;i++)
	cout<<b[i]<<" ";
	return 0;
}
