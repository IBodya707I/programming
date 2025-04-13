#include <string>
using namespace std;
class Employee
{
	private:
		string surname, departament;
		int year,experience; 
		float salary, bonus;
	public:
		Employee();
		Employee(string sn,string dep, int y, float s);
		string getSurname();
		string getDepartament();
		int getYear();
		float getSalary();
		float getBonus();
		void setSurname(string S);
		void setDepartament(string d);
		void setYear(int y);
		void setSalary(float s);
		void Bonus_(int nowYear);
		void setExperience(int nowYear);
		int getExperience(int nowYear);	
		friend void analyticsByDepartament(Employee Employees[],int n);
		friend class Vacations;
		friend void sort(Employee Employees[],int n);
		friend float avgExperience(int n,Employee Employee[],int nowYear);
};
class Vacations
{
	private:
		string worker, date,endVacation;
		int period;
	public:
		void addEmployees(Employee Employees[],Vacations Vacations[],int n);
		void setPeriod(Employee Employees[],Vacations Vacations[],int n,int nowYear);
		void setDates(Vacations Vacations[],int n);	
		string calculationEndVacation(string startVacation, int days);
		void showVacation();
		string getDate();
		int getPeriod();
		void setEndDate(string date);
		int getDays();
};