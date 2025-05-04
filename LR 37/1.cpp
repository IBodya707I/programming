#include <iostream>
using namespace std;
class student
{
	protected:
	string name;
	int year;
	string gender;
	public:
	student()
	{
		name="Rybonka Bohdan Romanovych";
		year=2007;
		gender="man";
	}
	void setName(string n)
	{
		name=n;
	}
	void setYear(int y)
	{
		year=y;
	}
	void setGender(string g)
	{
		gender=g;
	}
	int calculateAge(int nowYear)
	{
		return 	nowYear-year;
	}	
};
class worker:public student
{
	private:
	int salary;
	string placeOfWork;
	public:
	void setSalary(int s)
	{
		salary=s;
	}
	void setPlaceOfWork(string p)
	{
		placeOfWork=p;
	}
	worker(int s,string p){
		salary=s;
		placeOfWork=p;
	}	
	void print()
	{
		cout<<"name "<<name<<endl<<"year "<<year<<endl<<"gender "<<gender<<endl<<"salary "<<salary<<endl<<"place of work "<<placeOfWork<<endl;
	}
};
int main()
{
	student A;
	cout<<"age "<<A.calculateAge(2025)<<endl;
	worker B(20000,"Chernivtsi");
	B.print();
	cout<<"age "<<B.calculateAge(2025)<<endl;
	return 0;
}