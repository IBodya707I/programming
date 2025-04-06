#include <iostream>
#include "Employee.h"
using namespace std;
float avgExperience(int n,Employee Employee[])
{
	float sum=0;
	int i;
	for(i=0;i<n;i++)
	{
		sum=sum+Employee[i].getExperience();
	}
	return sum/n;
}
void print(Employee &x)
{
	cout<<"Surname "<<x.getSurname()<<", Departament "<<x.getDepartament()<<", Year "<<x.getYear()<<", Experience "<<x.getExperience()<<", salary "<<x.getSalary()<<", Bonus "<<x.getBonus()<<endl;
}
int main()
{
	Employee e;
	Employee s("Hhhh","It",2024,1200);
	s.Bonus_();
	print(e);
	print(s);
	int n,i,j;
	cout<<"n = ";
	cin>>n;
	string sn,d;
	int y,sa;
	Employee Employees[n];
	for(i=0;i<n;i++)
	{
		cout<<"surname ";
		cin>>sn;
		cout<<"departament ";
		cin>>d;
		cout<<"year ";
		cin>>y;
		cout<<"salary ";
		cin>>sa;
		Employees[i]=Employee(sn,d,y,sa);
		Employees[i].Bonus_();
	}
	for(i=0;i<n;i++)
	{
		print(Employees[i]);
	}
	cout<<"average experience = "<<avgExperience(n,Employees)<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(Employees[j].getExperience()>Employees[j+1].getExperience())
			{
				swap(Employees[j],Employees[j+1]);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		print(Employees[i]);
	}
	return 0;
}
