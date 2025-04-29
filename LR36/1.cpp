#include <iostream>
#include <vector>
using namespace std;
class worker
{
	private:
	string name;
	protected:
	int age,drivingExperience;
	public:
	worker(string n,int a,int e,vector<string> &errors)
	{
		if(a<18)
			errors.push_back("age under 18");
		if(e<0)
			errors.push_back("drivingExperience is negative");
		if(e>age-18)
			errors.push_back("drivingExperience > age from which get driver license");
		name=n;
		age=a;
		drivingExperience=e;
	}
	void setName(string n)
	{
		name=n;
	}
	void setAge(int a,vector<string> &errors)
	{
		if(a<18)
			errors.push_back("age under 18");
		age=a;
	}	
	void setDrivingExperience(int e,vector<string> &errors)
	{
		if(e<0)
			errors.push_back("drivingExperience is negative");
		if(e>age-18)
			errors.push_back("drivingExperience > age from which get driver license");
		drivingExperience=e;
	}
	void printWorker()
	{
		cout<<"Name: "<<name<<" \nAge: "<<age<<" \nDriving Exeprience: "<<drivingExperience<<endl;
	}
	void yearSinceDriving(int year)
	{
		cout<<"Year since driving "<<year-drivingExperience<<endl;
	}
};
class car
{
	private:
	int mileage;
	string brand,registrationNumber;
	protected:
	int yearOfRealease;
	public:
	car()
	{
		registrationNumber="";
		brand="";
		mileage=yearOfRealease=0;	
	}
	car(int m,int y,string b, string r,vector<string> &errors)
	{
		if(m<0)
			errors.push_back("mileage is negative");
		if(y<0)
			errors.push_back("year of realease is negative");
		mileage=m;
		brand=b;
		registrationNumber=r;
		yearOfRealease=y;	
	}
	void setRegistrationNumber(string r)
	{
		registrationNumber=r;
	}
	void setYearOfRealease(int y,vector<string> &errors,int year)
	{
		if(y>year)
			errors.push_back("year of realease > now year");
		yearOfRealease=y;
	}
	void setBrand(string b)
	{
		brand=b;
	}
	void setMileage(int m,vector<string> &errors)
	{
		if(m<0)
			errors.push_back("mileage is negative");
		mileage=m;
	}
	void printCar()
	{
		cout<<"Brand: "<<brand<<"\nRegistration number: "<<registrationNumber<<"\nYear of realease: "<<yearOfRealease<<"\nMileage: "<<mileage<<" km"<<endl;
	}
	void averageCarMileage(int year)
	{
		int yearOfWorking=year-yearOfRealease;
		cout<<"Average Car Mileage: "<<mileage/yearOfWorking<<" km"<<endl;
		
	}
};
class driver: public worker, public car
{
	private:
	int yearOfStartUseCar;
	bool fine=false;
	public:
	driver(vector<string> &errors):worker("",18,0,errors),car(0,2025,"","",errors) {}
	void setAllData(string name_,int age_,int drivingExperience_,int mileage_,string brand_,string registrationNumber_,int yearOfRealease_,int yearOfStartUseCar_,bool fine_,int year,vector<string> &errors)
	{
		if(yearOfStartUseCar_>year)
			errors.push_back("year of start use car > now year");
		setName(name_);
		setAge(age_,errors);
		setDrivingExperience(drivingExperience_,errors);
		setMileage(mileage_,errors);
		setBrand(brand_);
		setRegistrationNumber(registrationNumber_);
		setYearOfRealease(yearOfRealease_,errors,year);
		yearOfStartUseCar=yearOfStartUseCar_;
		fine=fine_;
	}	
	void printDriver()
	{
		cout<<"year of start use car: "<<yearOfStartUseCar<<endl;
		if(fine)
			cout<<"driver has fine "<<endl;
		else
			cout<<"driver has no fine "<<endl;
	}
	void ageCarOrDrivingExperience(int year)
	{
		int ageCar=year-yearOfRealease;
		if(drivingExperience<ageCar)
			cout<<"Age of the car more than "<<ageCar-drivingExperience<<" years "<<endl;
		else if(drivingExperience>ageCar)
			cout<<"driving Experience more than "<<drivingExperience-ageCar<<" years "<<endl;
		else
			cout<<"Age of the car = driving experience";
	}
	void printAllData(int year)
	{
		worker::printWorker();
		worker::yearSinceDriving(year);
		car::printCar();
		car::averageCarMileage(year);
		cout<<"year of start use car: "<<yearOfStartUseCar<<endl;
		if(fine)
			cout<<"driver has fine "<<endl;
		else
			cout<<"driver has no fine "<<endl;
		ageCarOrDrivingExperience(year);	
	}
};
int main()
{
	int year;
	cout<<"enter year ";
	cin>>year;
	vector<string> errors;
	driver Oleg(errors);
	Oleg.setAllData("Oleg",47,25,170000,"BMW","CE9876BX",2011,2015,false,year,errors);
	Oleg.printAllData(year);
	if(!errors.empty())
	{
		cout<<"Errors:"<<endl;
		for(auto &c:errors)
		{
			cout<<c<<endl;
		}
	}
	return 0;
}