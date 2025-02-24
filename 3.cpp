#include <iostream>
using namespace std;
int main()
{
	int a[4],i,j,*p,k=0,*pmax,*pmin;
	float s=0;
	p=a;
	for(i=0;i<4;i++)
	{
		cout<<"enter number ";
		cin>>*p;
		for(j=0;j<4;j++)
		{
			if(*p==*(p+j-i))
			k++;	
	}
			if(k>1)
			{
			cout<<"try again"<<endl;
			i--;
			p--;
			}	
			k=0;
			p++;	
	}
	p=a;
	pmax=a;
	pmin=a;
	for(i=0;i<4;i++)
	{
		s=s+*p;
		if(*p>*pmax)
		pmax=p;
		if(*p<*pmin)
		pmin=p;
		p++;	
	}	
	cout<<"average = "<<s/4<<endl;
	p=a;
	for(i=0;i<4;i++)
	{
		if(*p!=*pmax&&*p!=*pmin)
		cout<<*p<<" ";
		p++;
	}
	return 0;
}
