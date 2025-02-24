#include <iostream>
using namespace std;
int main()
{
	int a,b,c,*pmin,*pmax;
	cout<<"enter 3 numbers";
	cin>>a>>b>>c;
	pmin=&a;
	pmax=&a;
	if(b>*pmax)
	pmax=&b;
	if(c>*pmax)
	pmax=&c;
	if(b<*pmin)
	pmin=&b;
	if(c<*pmin)
	pmin=&c;
	cout<<"max = "<<*pmax<<endl<<"min = "<<*pmin<<endl;
	cout<<"addres max - "<<pmax<<endl<<"adress min - "<<pmin;
	return 0;
}
