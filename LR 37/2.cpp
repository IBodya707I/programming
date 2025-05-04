#include <iostream>
using namespace std;
class engine
{
	protected:
	int power;
	string numberEngine;
	public:
	engine()
	{
		power=150;
		numberEngine="VBJ235N24";	
	}
	engine(int p,string n)
	{
		power=p;
		numberEngine=n;	
	}	
	void setNumberEngine(string n)
	{
		numberEngine=n;
	}
	void setPower(int p)
	{
		power=p;
	}
	~engine()
	{
		cout<<numberEngine<<" delete"<<endl;
	}
	void printEngine()
	{
		cout<<"Number engine "<<numberEngine<<"\npower "<<power<<endl;
	}
};
class car: protected engine
{
	protected:
	string brand;
	int price;
	public:
	car()
	{
		brand="N/A";
		price=0;
	}
	car(string b, int p)
	{
		brand=b;
		price=p;
	}
	void setNumberEngine(string n)
	{
		numberEngine=n;
	}
	void setPower(int p)
	{
		power=p;
	}
	void setBrand(string b)
	{
		brand=b;
	}
	void setPrice(int p)
	{
		price=p;
	}
	void setAllDataAboutCar(string n,int hp,string b,int p)
	{
		numberEngine=n;
		power=hp;
		price=p;
		brand=b;		
	}
	void printAllDataAboutCar()
	{
		cout<<"brand "<<brand<<"\nprice "<<price<<"\nnumber engine "<<numberEngine<<"\npower "<<power<<" hp"<<endl;
	}
	~car()
	{
		cout<<brand<<" ";
	}
};
class truck:protected car
{
	private:
	int loadCapacity;
	public:
	truck()
	{
		loadCapacity=0;
	}
	truck(int l)
	{
		loadCapacity=l;
	}
	void setNumberEngine(string n)
	{
		numberEngine=n;
	}
	void setPower(int p)
	{
		power=p;
	}
	void setBrand(string b)
	{
		brand=b;
	}
	void setPrice(int p)
	{
		price=p;
	}
	void setLoadCapacity(int l)
	{
		loadCapacity=l;
	}
	void setAllDataAboutTruck(string n,int hp,string b,int p,int l)
	{
		numberEngine=n;
		power=hp;
		price=p;
		brand=b;
		loadCapacity=l;		
	}
	void printAllDataAboutTruck()
	{
		cout<<"brand "<<brand<<"\nprice "<<price<<"\nnumber engine "<<numberEngine<<"\npower "<<power<<" hp"<<"\nload capacity "<<loadCapacity<<" kg"<<endl;
	}
	~truck()
	{
		cout<<"truck ";
	}
};
int main()
{
	int i;
	string n,b;
	int hp,p,l;
	engine engines[3];
	for(i=0;i<3;i++)
	{
		cout<<"power: ";
		cin>>hp;
		cout<<"Number engine: ";
		cin>>n;
		engines[i]=engine(hp,n);
	}
	car cars[3];
	for(i=0;i<3;i++)
	{
		cout<<"power: ";
		cin>>hp;
		cout<<"Number engine: ";
		cin>>n;
		cout<<"brand: ";
		cin>>b;
		cout<<"price: ";
		cin>>p;
		cars[i].setAllDataAboutCar(n,hp,b,p);
	}
	truck trucks[3];
	for(i=0;i<3;i++)
	{
		cout<<"power: ";
		cin>>hp;
		cout<<"Number engine: ";
		cin>>n;
		cout<<"brand: ";
		cin>>b;
		cout<<"price: ";
		cin>>p;
		cout<<"load capacity: ";
		cin>>l;
		trucks[i].setAllDataAboutTruck(n,hp,b,p,l);
	}
	cout<<"--------------------------"<<endl;
	cout<<"engines:"<<endl;
	for(i=0;i<3;i++)
	{
		engines[i].printEngine();
	}
	cout<<"--------------------------"<<endl;
	cout<<"cars:"<<endl;
	for(i=0;i<3;i++)
	{
		cars[i].printAllDataAboutCar();
	}
	cout<<"--------------------------"<<endl;
	cout<<"trucks:"<<endl;
	for(i=0;i<3;i++)
	{
		trucks[i].printAllDataAboutTruck();
	}
	cout<<"--------------------------"<<endl;
	return 0;
}