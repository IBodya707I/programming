#include <iostream>
#include <time.h>
using namespace std;
template <typename T>
void countElementsEqualFirst(T a[],int n)
{
	T first=a[0];
	int i,count=0;
	for(i=1;i<n;i++)
	{
		if(first==a[i])
			count++;
	}
	cout<<"Count elements equal first - "<<count<<endl;
}
template <typename T>
void swapElements(T a[],int index1,int index2,int n)
{
	int i;
	if(index1>=n||index2>=n)
	{
		cout<<"error "<<endl;
		return;
	}
	swap(a[index1],a[index2]);
	cout<<"swap completed "<<endl;
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
template <typename T>
void injectionElement(T a[],T x,int index,int &n)
{
	int i;
	if(index>=n)
	{
		cout<<"error "<<endl;
		return;
	}
	i=n-1;
	while(i>=index)
	{
		a[i+1]=a[i];
		i--;
	}
	a[i+1]=x;
	n++;
	cout<<"injection complete"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
template <typename T>
void longestIntervalWithSameElements(T a[],int n)
{
	int i,c=0,maxCount=0,x;
	for(i=0;i<n;i++)
	{
		if(i==0||a[i]!=x)
		{
			x=a[i];
			c=0;
		}
		c++;
		if(c>maxCount)
				maxCount=c;
	}
	cout<<"longest interval with same elements - "<<maxCount<<endl;
}
template <typename T>
void sortBetweenMinAndMax(T a[],int n)
{
	int i,j;
	T min=a[0],max=a[0];
	int indexMax=0,indexMin=0;
	for(i=0;i<n;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
			indexMax=i;
		}
		if(a[i]<min)
		{
			min=a[i];
			indexMin=i;
		}
	}
	if(indexMin==indexMax)
	{
		cout<<"error "<<endl;
		return;
	}
	int start,end;
	if(indexMin>indexMax)
	{
		start=indexMax;
		end=indexMin;
	}
	if(indexMin<indexMax)
	{
		end=indexMax;
		start=indexMin;
	}
	for(i=start+1;i<=end-1;i++)
	{
		for(j=start+1;j<end-1;j++)
		if(a[j]>a[j+1])
		{
			swap(a[j],a[j+1]);
		}
	}
	cout<<"sort completed "<<endl;
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	srand(time(NULL));
	int n,i;
	cout<<"n = ";
	cin>>n;
	int v=n*2;
	int a[v];
	for(i=0;i<n;i++)
	{
		a[i]=rand()%10;
		cout<<a[i]<<" ";
	}
	cout<<endl;
	countElementsEqualFirst(a,n);
	int index1,index2;
	cout<<"enter 2 index to swap ";
	cin>>index1>>index2;
	swapElements(a,index1,index2,n);
	int element,index;
	cout<<"enter element and index ";
	cin>>element>>index;
	injectionElement(a,element,index,n);
	longestIntervalWithSameElements(a,n);
	sortBetweenMinAndMax(a,n);
	return 0;
}