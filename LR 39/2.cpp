#include <iostream>
#include <vector>
using namespace std;
class worker
{
	protected:
	int id;
	string surname;
	public:
	worker(int i,string n)
	{
		id=i;
		surname=n;
	}
	virtual float calculateSalary()=0;
	bool operator==(worker &t)
	{
		if(this->id==t.id)
			return true;
		else
			return false;
	}
	int getId()
	{
		return id;	
	}
	string getSurname()
	{
		return surname;	
	}	
};
class manager:public worker
{
	private:
	int subordinates;
	int rate;
	public:
	manager(int i,string n,int s,int r):worker(i,n)
	{
		subordinates=s;
		rate=r;
	}
	float calculateSalary() override
	{
		if(subordinates>5)
			return rate+rate*0.1;
		else
			return rate;	
	}
};
class developer:public worker
{
	private:
	int hours;
	int rate;
	public:
	developer(int i,string n,int h,int r):worker(i,n)
	{
		hours=h;
		rate=r;
	}	
	float calculateSalary() override
	{
		return 	rate*hours;
	}
};
int main()
{
	vector<worker*> workers;
	workers.push_back(new manager(34,"dfgghj",7,12000));
	workers.push_back(new manager(31,"mnbbvv",3,10000));
	workers.push_back(new developer(17,"poiuyt",180,100));
	workers.push_back(new developer(8,"weryu",170,110));
	int i;
	for(i=0;i<workers.size();i++)
	{
		cout<<"worker: "<<workers[i]->getId()<<", surname "<<workers[i]->getSurname()<<", salary "<<workers[i]->calculateSalary()<<endl;
	}
	if(workers[0]==workers[2])
		cout<<"true\n";
	else
		cout<<"false\n";
	return 0;
}