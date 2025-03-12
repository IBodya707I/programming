#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;
void sort(int *b,int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(b[j]<b[j+1])
			swap(b[j],b[j+1]);
		}
	}
}
int main()
{
	int **a,n,i,j;
	cout<<"enter n ";  
	cin>>n;
	a=new int*[n];
	for(i=0;i<n;i++)
	a[i]=new int[n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			a[i][j]=100+rand()%899;
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}

	for(i=0;i<n;i++)
	{
		int *b=new int[n];
		for(j=0;j<n;j++)
		{
			b[j]=a[i][j];		
		}
		sort(b,n);
		for(int s=0;s<n;s++)
		{
			a[i][s]=b[s];
		}
		delete []b;
	}
	cout<<endl;
	ofstream file("3.txt");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<a[i][j]<<" ";
			file<<a[i][j]<<" ";
		}
		cout<<endl;
		file<<endl;
	}
	file.close();
	for(i=0;i<n;i++)
	delete[] a[i];
	delete []a;	
	return 0;
}
