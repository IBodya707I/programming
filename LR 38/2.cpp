#include <iostream>
#include <time.h>
using namespace std;
template <typename T>
class vector
{
	private:
	T data[10];
	public:
	vector()
	{
		int i;
		for(i=0;i<10;i++)
			data[i]=0;
	}
	vector(T a[10])
	{
		int i;
		for(i=0;i<10;i++)
			data[i]=a[i];
	}
	void enterFromKeybord()
	{
		int i;
		for(i=0;i<10;i++)
			cin>>data[i];
	}
	void randomFill(T min,T max)
	{
		int i;
		for(i=0;i<10;i++)
		{
			data[i]=min+rand()%(max-min+1);
		}
	}
	void print()
	{
		int i;
		for(i=0;i<10;i++)
			cout<<data[i]<<" ";
		cout<<endl;
	}
	void formatingVector()
	{
		int i,j=0;
		T a[10];
		for(i=0;i<10;)
		{
			a[j]=data[i];
			j++;
			i=i+2;
		}
		for(i=1;i<10;)
		{
			a[j]=data[i];
			j++;
			i=i+2;
		}
		for(i=0;i<10;i++)
		data[i]=a[i];
	}
	void deleteElement(T x)
	{
		int i;
		bool found=false;
		for(i=0;i<10;i++)
			if(data[i]==x)
			{
				data[i]=0;
				found=true;
			}
		if(!found)
			cout<<"not found "<<x<<endl;
		else
			this->print();
	}
	vector operator+(vector t)
	{
		vector result;
		int i;
		for(i=0;i<10;i++)
			result.data[i]=data[i]+t.data[i];
		return result;
	}
	vector operator++()
	{
		int i;
		for(i=0;i<10;i++)
			data[i]+=10;
		return *this;
	}
	T sum()
	{
		int i;
		T sum=0;
		for(i=0;i<10;i++)
			sum+=data[i];
		return sum;
	}
	bool operator<(vector t)
	{
		if(this->sum()<t.sum())
			return true;
		else
			return false;
	}
	bool operator>(vector t)
	{
		if(this->sum()>t.sum())
			return true;
		else
			return false;
	}
	bool operator==(vector t)
	{
		if(this->sum()==t.sum())
			return true;
		else
			return false;
	}
};
int main()
{
	srand(time(NULL));
	vector<int> a;
	a.randomFill(-5,5);
	a.print();
	++a;
	a.print();
	a.formatingVector();
	a.print();
	a.deleteElement(3);
	char s[10]={'a','u','x','w','t','s','v','c','a','r'};
	vector<char> s1(s);
	s1.print();
	vector<int> b;
	b.randomFill(3,10);
	cout<<"a: ";
	a.print();
	cout<<"b: ";
	b.print();
	cout<<"sum a: "<<a.sum()<<" sum b: "<<b.sum()<<endl;
	if(a<b)
		cout<<"a<b\n";
	else
		cout<<"a>b\n";
	if(a>b)
		cout<<"a>b\n";
	else
		cout<<"a<b\n";
	if(a==b)
		cout<<"a==b\n";
	else
		cout<<"a!=b\n";
	return 0;
}