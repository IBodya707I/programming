#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
int main()
{
	string line, a,b,c;
	int i,n,k=0,l=0,j;
	ifstream file("text.txt");
	if(!file)
	{
		cout<<"error ";
		return 0;
	}
	while(getline(file,line))
	cout<<line<<endl;
	n=line.length();
	for(i=0;i<n;i++)
	{
		if(isalpha(line[i]))
		{
			k++;
		}
		if(line[i]==' ')
		k=0;
		if(k==3)
		{
			if(line[i+1]==' '||line[i+1]=='\0')
			{
				a+=line[i-2];
				a+=line[i-1];
				a+=line[i];
				a+=' ';
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if((i==0&&islower(line[i])))
		{
			while(line[i+l]!=' '||line[i+1]=='\0')
			{
				b+=line[i+l];
				l++;
			}
			l=0;
			b+=' ';	
		}
		if(line[i-1]==' '&&islower(line[i]))
		{
			while(line[i+l]!=' '&&i+l<n)
			{
				b+=line[i+l];
				l++;
			}
			l=0;
			b+=' ';
		}
	}
	cout<<a<<endl;
	b+='\0';
	cout<<b<<endl;
	i=0;
	while(i<n)
	{
		line[i]=tolower(line[i]);
		i++;
	}
	cout<<"enter word ";
	cin>>c;
	int m=c.length();
	k=0;
	for(i=0;i<n;i++)
	{
		l=0;
		for(j=0;j<m;j++)
		{
			if(line[i+j]==c[j])
			{
				l++;
			}
		}
		if(l==m&&(line[l+i]==' '||i+l==n))
		k++;
	}
	cout<<"count = "<<k;
	return 0;
}
