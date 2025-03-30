#include<iostream>
using namespace std;
class people
{
	int year=2006,age=2025-year;
	string surname, country="Ukraine", education,gender;
	public:
	people()
	{
		year=2006;
		age=2025-year;
		country="Ukraine";
		education="";
		gender="";
		surname="";
	}
	void addPeople()
	{
		cout<<"year ";
		cin>>year;
		age=2025-year;
		cout<<"surname ";
		cin>>surname;
		cout<<"country ";
		cin>>country;
		int x=0;
		string a="average",b="high";
		while(x!=1&&x!=2)
		{
			cout<<"1. average 2. high ";
			cin>>x;
			if(x==1)
			{
				education=a;
			}
			if(x==2)
			{
				education=b;
			}
		}
		int s=0;
		string f="women",c="men";
		while(s!=1&&s!=2)
		{
			cout<<"1. women 2. men ";
			cin>>s;
			if(s==1)
			{
				gender=f;
			}
			if(s==2)
			{
				gender=c;
			}
		}
	}
	string education1()
	{
		return education;
	}
	int age1()
	{
		return age;
	}
	string gender1()
	{
		return gender;
	}
	void showPeople()
	{
		cout<<"year "<<year<<", age "<<age<<", surname "<<surname<<", country "<<country<<", education "<<education<<", gender "<<gender<<endl;	
	}
	void function(people people[],int n,int a)
	{
		string b="high";
		int i;
		for(i=0;i<n;i++)
		{
			if(people[i].education1()==b&&people[i].age1()>a)
			{
				people[i].showPeople();
			}
		}
	}
	people(people &x)
	{
		surname=x.surname;
		country=x.country;
		gender=x.gender;
		education=x.education;
		year=x.year;
		age=x.age;
	}
	void function1(people peoples[],int &n)
	{
		int i;
		people people2(peoples[0]);
		for(i=n;i>0;i--)
		{
			peoples[i]=peoples[i-1];
		}
		peoples[0]=people2;
		n++;
	}
	~people()
	{
		cout<<"delete"<<endl;
	}
};
void deleteGender(people people[],int &n,string v)
{
	int i,k=0,m=0;
	for(i=0;i<n;i++)
	{
		if(people[i].gender1()!=v)
		{
			k++;
		}
	}
	for(i=0;i<n;i++)
	{
		if(people[i].gender1()!=v)
		{
			people[m]=people[i];
		}
	}
	n=k;
}
int main()
{
	int n,i,a;
	cout<<"enter n ";
	cin>>n;
	people people1;
	people peoples[10];
	for(i=0;i<n;i++)
	{
		peoples[i].addPeople();
	}
	cout<<"enter a ";
	cin>>a;
	people1.function(peoples,n,a);
	people1.function1(peoples,n);
	for(i=0;i<n;i++)
	{
		peoples[i].showPeople();
	}
	string v;
	int s=0;
		string f="women",c="men";
		while(s!=1&&s!=2)
		{
			cout<<"1. women 2. men ";
			cin>>s;
			if(s==1)
			{
				v=f;
			}
			if(s==2)
			{
				v=c;
			}
		}
	deleteGender(peoples,n,v);
	for(i=0;i<n;i++)
	{
		peoples[i].showPeople();
	}
	return 0;
}
