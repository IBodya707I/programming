#include <iostream>
#include "head.h"
using namespace std;
void print(Employee &x,int nowYear)
{
	cout<<"Surname "<<x.getSurname()<<", Departament "<<x.getDepartament()<<", Year "<<x.getYear()<<", Experience "<<x.getExperience(nowYear)<<", salary "<<x.getSalary()<<", Bonus "<<x.getBonus()<<endl;
}
int main()
{
	int year;
	cout<<"enter year ";
	cin>>year;
	Employee e;
	Employee s("Hhhh","It",2024,1200);
	s.Bonus_(year);
	print(e,year);
	print(s,year);
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
		Employees[i].Bonus_(year);
	}
	for(i=0;i<n;i++)
	{
		Employees[i].setExperience(year);
	}
	for(i=0;i<n;i++)
	{
		print(Employees[i],year);
	}
	cout<<"average experience "<<avgExperience(n,Employees,year)<<endl;
	sort(Employees,n);
	for(i=0;i<n;i++)
	{
		print(Employees[i],year);
	}
	analyticsByDepartament(Employees,n);
	Vacations Vacations[n];
	Vacations[0].addEmployees(Employees,Vacations,n);
	Vacations[0].setPeriod(Employees,Vacations,n,year);
	Vacations[0].setDates(Vacations,n);
	for(i=0;i<n;i++)
	{
		Vacations[i].setEndDate(Vacations[i].calculationEndVacation(Vacations[i].getDate(),Vacations[i].getDays()));
	}
	for(i=0;i<n;i++)
	{
		Vacations[i].showVacation();
	}
	return 0;
}
