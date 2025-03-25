#include <iostream>
#include <time.h>
using namespace std;
void vvid(int *a,int n)
{
	int x=0,i;
	cout<<"vvid: 1. random 2. manually ";
	cin>>x;
	while(x!=1&&x!=2)
	{
		cout<<"try again ";
		cin>>x;
	}
	if(x==1)
	{
		srand(time(NULL));
		int q,w;
		cout<<"enter a,b ";
		cin>>q>>w;
		for(i=0;i<n;i++)
		{
			a[i]=q+rand()%w;
		}
	}
	if(x==2)
	{
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
	}
}
void vuvid (int *a,int n)
{
	int x=0,i;
	cout<<"vuvid: 1. in line 2. in column ";
	cin>>x;
	while(x!=1&&x!=2)
	{
		cout<<"try again ";
		cin>>x;
	}
	if(x==1)
	{
		for(i=0;i<n;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
	if(x==2)
	{
		for(i=0;i<n;i++)
		{
			cout<<a[i]<<endl;
		}
	}
}
void delete_pair(int *a,int &n)
{
	int i,j=0,max,min,k_min=0,k_max=0;
	max=a[0];
	min=a[0];
	for(i=0;i<n;i++)
	{
		if(a[i]>max)
		max=a[i];
		if(a[i]<min)
		min=a[i];
	}
	for(i=0;i<n;i++)
	{
		if(a[i]==max||a[i]==min)
		{
			if(a[i]==max)
			{
				if(k_max==0)
				{
					a[j]=a[i];
					j++;
				}
				k_max++;	
			}
			if(a[i]==min)
			{
				if(k_min==0)
				{
					a[j]=a[i];
					j++;
				}
				k_min++;
			}
		}
		else
		{
			a[j]=a[i];
			j++;
		}
	}
	n=j;	
}
void function(int *a,int n)
{
	int i,j=0,min,x=0;
	min=a[0];
	for(i=0;i<n;i++)
	{
		if(a[i]<min)
		{
			min=a[i];
			x=i;
		}
	}
	int *b=new int[n];
	for(i=x;i<n;i++)
	b[i-x]=a[i];
	for(i=0;i<x;i++)
	b[n-x+i]=a[i];
	for(i=0;i<n;i++)
	a[i]=b[i];
	delete []b;
}
void function1(int *a,int &n)
{
	int i,j=0,max,min,x_min=0,x_max=0;
	max=a[0];
	min=a[0];
	for(i=0;i<n;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
			x_max=i;
		}
		if(a[i]<min)
		{
			min=a[i];
			x_min=i;
		}
	}
	if(x_min<x_max)
	{
		for(i=x_min;i<=x_max;i++)
		{
			a[j]=a[i];
			j++;
		}
	}
	if(x_max<x_min)
	{
		for(i=x_max;i<=x_min;i++)
		{
			a[j]=a[i];
			j++;
		}
	}
	n=j;
}
int *function2(int *a,int n,int &c)
{
	int i;
	int *b=new int[n];
	int q=0,w=0;
	for(i=0;i<n;i++)
	{
		if(a[i]%2==0)
		{
			q++;
		}
		else
		w++;
	}
	if(w>q)
	{
		for(i=0;i<n;i++)
		{
			if(a[i]%2!=0)
			{
				b[c]=a[i];
				c++;
			}
		}
	}
	if(w<=q)
	{
		for(i=0;i<n;i++)
		{
			if(a[i]%2==0)
			{
				b[c]=a[i];
				c++;
			}
		}		
	}
	return b;
}
int main()
{
	int i,n,c=0;
	cout<<"enter n ";
	cin>>n;
	int *a=new int[n];
	vvid(a,n);
	vuvid(a,n);
	delete_pair(a,n);
	vuvid(a,n);
	function(a,n);
	vuvid(a,n);
	function1(a,n);
	vuvid(a,n);
	int *b=function2(a,n,c);
	vuvid(b,c);	
	return 0;
}
