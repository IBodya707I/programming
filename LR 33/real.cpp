#include "head.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>
using namespace std;
	Employee::Employee()
	{
		surname="-";
		departament="-";
		year=2025;
		salary=1000;
		bonus=100;
	}
	Employee::Employee(string sn,string dep, int y, float s)
	{
		surname=sn;
		departament=dep;
		year=y;
		salary=s;
	}	
	string Employee::getSurname()
	{
		return surname;
	}
	string Employee::getDepartament()
	{
		return departament;
	}
	int Employee::getYear()
	{
		return year;
	}
	float Employee::getSalary()
	{
		return salary;
	}
	float Employee::getBonus()
	{
		return bonus;
	}
	void Employee::setSurname(string S)
	{
		surname=S;
	}
	void Employee::setDepartament(string d)
	{
		departament=d;
	}
	void Employee::setYear(int y)
	{
		year=y;
	}
	void Employee::setSalary(float s)
	{
		salary=s;
	}
	int Employee::getExperience(int nowYear)
	{
		return nowYear-year;
	}
	void Employee::Bonus_(int nowYear)
	{
		int t=getExperience(nowYear);
		if(t<=10)
		{
			bonus=salary*0.10;
		}
		else if(t>10&&t<25)
		{
			bonus=salary*0.25;
		}
		else if(t>=25)
		{
			bonus=salary*0.4;
		}
	}
	void Employee::setExperience(int nowYear)
	{
		experience=nowYear-year;
	}
	void analyticsByDepartament(Employee Employees[],int n)
	{
		vector<string> departaments;
		string t;
		int i,j;
		for(i=0;i<n;i++)
		{
			bool found=false;
			for(j=0;j<departaments.size();j++)
			{
				if(departaments[j]==Employees[i].departament)
				{
					found=true;
				}
			}
			if(!found)
				departaments.push_back(Employees[i].departament);
		}
		for(i=0;i<departaments.size();i++)
		{
			int count=0,sumSalary=0;
			cout<<departaments[i]<<": ";
			for(j=0;j<n;j++)
			{
				if(Employees[j].departament==departaments[i])
				{
					count++;
					sumSalary+=Employees[j].salary;
				}
			}
			cout<<"all salary "<<sumSalary<<" count employees "<<count<<endl;
		}
	}
	void sort(Employee Employees[],int n)
	{
		int i,j;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n-1;j++)
			{
				if(Employees[j].experience>Employees[j+1].experience)
				{
					swap(Employees[j],Employees[j+1]);
				}
			}
		}
	}
	float avgExperience(int n,Employee Employee[],int nowYear)
	{
		float sum=0;
		int i;
		for(i=0;i<n;i++)
		{
			sum=sum+Employee[i].experience;
		}
		return sum/n;
	}
	void Vacations::addEmployees(Employee Employees[],Vacations Vacations[],int n)
	{
		int i;
		for(i=0;i<n;i++)
		{
			Vacations[i].worker=Employees[i].surname;
		}
	}
	void Vacations::setPeriod(Employee Employees[],Vacations Vacations[],int n,int nowYear)
	{
		int i;
		for(i=0;i<n;i++)
		{
			if((Employees[i].salary+Employees[i].getBonus())<12500&&Employees[i].getExperience(nowYear)<10)
				Vacations[i].period=14;
			else if((Employees[i].salary+Employees[i].getBonus())>25000&&Employees[i].getExperience(nowYear)>25)
				Vacations[i].period=28;
			else
				Vacations[i].period=21;
		}
	}
	void Vacations::setDates(Vacations Vacations[],int n)
	{
		int i;
		for(i=0;i<n;i++)
		{
			cout<<Vacations[i].worker<<" vaction date ";
			cin>>Vacations[i].date;
		}
	}
	string Vacations::calculationEndVacation(string startVacation, int days)
	{
		tm date={};
		istringstream s(startVacation);
		s>>get_time(&date,"%d.%m.%y");
		time_t start=mktime(&date);
		start+=days*60*60*24;
		tm *endVacation=localtime(&start);
		ostringstream result;
		result<<put_time(endVacation,"%d.%m.%y");
		return result.str();
	}
	void Vacations::showVacation()
	{
		cout<<"worker "<<worker<<" period "<<period<<" start vacation "<<date<<" end vacation "<<endVacation<<endl;
	}
	int Vacations::getPeriod()
	{
		return period;
	}
	string Vacations::getDate()
	{
		return date;
	}
	void Vacations::setEndDate(string date)
	{
		endVacation=date;
	}
	int Vacations::getDays()
	{
		return period;
	}
	