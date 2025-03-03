#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main()
{
	int a[10][10],i,j,n,**dp,*p[10],b[10],k=0,ka=0,kam=0;
	float arf=0,arfm=0;
	srand(time(NULL));
	cout<<"enter n ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		p[i]=a[i];
		dp=p;
		for(j=0;j<n;j++)
		{
			*(*(dp+i)+j)=-10+rand()%21;
			cout<<*(*(dp+i)+j)<<" ";
		}
		cout<<endl;
	}
	for(i=0;i<n;i++)
	{
		p[i]=a[i];
		dp=p;
		for(j=0;j<n;j++)
		{
			if(*(*(dp+i)+j)==0)
			{
				k++;
			}
			if(*(*(dp+i)+j)<0)
			{
				arfm=arfm+*(*(dp+i)+j);
				kam++;
			}
			if(*(*(dp+i)+j)>0)
			{
				arf=arf+*(*(dp+i)+j);
				ka++;
			}
		}
	}
	cout<<"arf >0 = "<<(arf/ka)<<endl<<"arf <0 = "<<(arfm/kam)<<endl<<"count 0 = "<<k;
	return 0;
}

