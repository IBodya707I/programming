#include <iostream>
using namespace std;
class flat
{
	private:
		int rooms =2;
		int floor;
		string address;
		float area=55;
	public:
	flat()
	{
		
	}
	flat(int a,string b)
	{
		floor=a;
		address=b;
	}
	void showflat()
	{
		cout<<"rooms "<<rooms<<", ";
		cout<<"floor "<<floor<<", ";
		cout<<"address "<<address<<", ";
		cout<<"area "<<area<<endl;
	}
	void addFlat()
	{
		cout<<"enter rooms ";
		cin>>rooms;
		cout<<"enter floor ";
		cin>>floor;
		cout<<"enter addres ";
		cin>>address;
		cout<<"enter area ";
		cin>>area;
	}
	int area1()
	{
		return area;	
	}	
	int room1()
	{
		return rooms;
	}
	int floor1()
	{
		return floor;
	}
	void function(flat flat[],int n,int a)
	{
		int i;
		for(i=0;i<n;i++)
		{
			if(flat[i].room1()==a)
			{
				flat[i].showflat();
			}
		}
	}
	void function1(flat flat[],int n, int a, int b)
	{
		int i;
		for(i=0;i<n;i++)
		{
		if(flat[i].area1()<40&&flat[i].floor1()>=a&&flat[i].floor1()<=b)
		{
			flat[i].showflat();
		}
		}
	}
	~flat()
	{
		cout<<"delete"<<endl;
	}
};
int main()
{
	flat flat2;
	flat2.showflat();
	int a,i,n;
	string b;
	cout<<"enter floor ";
	cin>>a;
	cout<<"enter address ";
	cin>>b;
	flat flat1(a,b);
	flat1.showflat();
	flat flat3;
	flat3.addFlat();
	flat3.showflat();
	cout<<"enter n ";
	cin>>n;
	flat flats[n];

	for(i=0;i<n;i++)
	{
		flats[i].addFlat();
	}
	int f;
	cout<<"enter a ";
	cin>>f;
	flat1.function(flats,n,f);
	int s,d;
	cout<<"enter a,b ";
	cin>>s>>d;
	flat1.function1(flats,n,s,d);
	return 0;
}
