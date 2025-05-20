#include <iostream>
using namespace std;
class notification
{
	protected:
	string title;
	string text;
	public:
	notification(string t1,string t2)
	{
		title=t1;
		text=t2;
	}
	void printNotification()
	{
		cout<<title<<endl<<text<<endl;
	}
};
class importantNotification:public notification
{
	private:
	string importance;
	public:
	importantNotification(string t1,string t2,string i):notification(t1,t2)
	{
		importance=i;
	}
	void printImportantNotification(void (*additionalAction)())
	{
		notification::printNotification();
		if(importance=="low")
		{
			cout<<"importance: "<<importance<<endl;
		}
		else if(importance=="medium")
		{
			cout<<"importance: "<<importance<<endl;
		}
		else if(importance=="high")
		{
			cout<<"importance: "<<importance<<endl;
			additionalAction();
		}
		else
		{
			cout<<"importance: unknown"<<endl;
		}
	}
};
int main()
{
	importantNotification notification1("Warning","There is a threat","high");
	auto additionalAction=[](){
		cout<<"Confirmation is required\n";
	};
	notification1.printImportantNotification(additionalAction);
}