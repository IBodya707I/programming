#include "Employee.h"
#include <string>
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
	int Employee::getExperience()
	{
		return 2025-year;
	}
	void Employee::Bonus_()
	{
		int t=getExperience();
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

