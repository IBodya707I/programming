#include <iostream>
using namespace std;
void function(int &q,int **a,int n)
{
	int i,j,k;
	for(j=0;j<n;j++)
	{
		int k=0;
		for(i=0;i<n-1;i++)
		{
			if(a[i][j]>a[i+1][j])
			k++;
		}
		if(k+1==n)
		q++;
	}
}
int main()
{
	int **a,n,i,j,q=0;
	cout<<"enter n ";  
	cin>>n;
	a=new int*[n];
	for(i=0;i<n;i++)
	a[i]=new int[n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	function(q,a,n);
	cout<<q;
	for(i=0;i<n;i++)
	delete []a[i];
	delete []a;

	return 0;
}
