#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
void function(int *b,int n,int &k)
{
	int i,a,c;
	k=0;
	for(i=0;i<n;i++)
	{
		a=b[i]/10;
		c=b[i]%10;
		if(a==c)
		k++;
	}
}
int main()
{
	srand(time(NULL));
	int **a,n,i,j,s=0;
	cout<<"enter n ";  
	cin>>n;
	a=new int*[n];
	for(i=0;i<n;i++)
	a[i]=new int[n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			a[i][j]=10+rand()%89;
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	for(i=0;i<n;i++)
	{
		int k=0;
		int *b=new int[n];
		for(j=0;j<n;j++)
		{
			b[j]=a[j][i];		
		}
		function(b,n,k);
		if(k==0)
		{
			for(int j=0;j<n;j++)
			{
				s=s+a[j][i];
			}
			cout<<i+1<<" suma = "<<s<<endl;
		}
		delete []b;
	}
	for(i=0;i<n;i++)
	delete[]a[i];
	delete []a;
	return 0;
}
