#include <string>
using namespace std;
class Employee
{
	private:
		string surname, departament;
		int year; 
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
		void Bonus_();
		int getExperience();	
	
};
