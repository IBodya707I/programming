#include <iostream>
using namespace std;
int main()
{
	float a,c,*p;
	cout<<"enter a ";
	cin>>a;
	cout<<"enter c ";
	cin>>c;
	p=&a;
	*p=*p*3;
	*p=*p+c;
	p=&c;
	cout<<"addres a - "<<&a<<endl<<"addres c - "<<&c<<endl<<"addres &p - "<<&p<<endl<<"addres p - "<<p<<endl<<"a = "<<a<<endl<<"c = "<<c<<endl<<"*p "<<*p;
	return 0;	
}
