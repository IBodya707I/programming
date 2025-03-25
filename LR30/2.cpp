#include <iostream>
using namespace std;
int area(int a, int b=7, int c=8)
{
	return 2*(a*b+b*c+a*c);
}
int main()
{
	cout<<"1 parameter "<<area(3)<<endl;
	cout<<"2 parameter "<<area(3,4)<<endl;
	cout<<"3 parameter "<<area(3,4,5)<<endl;
	return 0;
}
