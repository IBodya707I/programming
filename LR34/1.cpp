#include <iostream>
using namespace std;
class time{
private:
	int hours,minutes,seconds;
public:
	time()
	{
		seconds=minutes=hours=0;
	}
	time(int h,int m,int s)
	{
		seconds=s;
		minutes=m;
		hours=h;
	}
	~time()
	{
		cout<<"delete "<<endl;
	}
	void input()
	{
		cout<<"hours ";
		cin>>hours;
		cout<<"minutes ";
		cin>>minutes;
		cout<<"seconds ";
		cin>>seconds;
	}
	void check(int m)
	{
		if(m<10)
			cout<<"0"<<m;
		else
			cout<<m;
	}
	void print()
	{
		check(hours);
		cout<<":";
		check(minutes);
		cout<<":";
		check(seconds);
		cout<<endl;
	}
	time operator+(time &t)
	{
		int s=seconds+t.seconds;
		int m=minutes+t.minutes+s/60;
		int h=hours+t.hours+m/60;
		return time(h,m&60,s%60);
	}
	time operator-(time &t)
	{
		int s1,s2,h,m,s;
		s1=hours*3600+minutes*60+seconds;
		s2=t.hours*3600+t.minutes*60+t.seconds;
		int diff=abs(s1-s2);
		h=diff/3600;
		m=(diff%3600)/60;
		s=diff%60;
		return time(h,m,s);
	}
	bool operator>(time &t)
	{
		if((hours*3600+minutes*60+seconds)>(t.hours*3600+t.minutes*60+t.seconds))
			return true;
		else
			return false;
	}
	bool operator<(time &t)
	{
		if((hours*3600+minutes*60+seconds)<(t.hours*3600+t.minutes*60+t.seconds))
			return true;
		else
			return false;
	}
	bool operator==(time &t)
	{
		if(seconds==t.seconds&&minutes==t.minutes&&hours==t.hours)
			return true;
		else
			return false;
	}
};
int main()
{
	time t1,t2;
	t1.input();
	t2.input();
	t1.print();
	t2.print();
	time sum;
	sum=t1+t2;
	sum.print();
	time diff;
	diff=t1-t2;
	diff.print();
	if(t1>t2)
		cout<<"t1>t2"<<endl;
	else
		cout<<"t1<t2"<<endl;
	if(t1<t2)
		cout<<"t1<t2"<<endl;
	else
		cout<<"t1>t2"<<endl;
	if(t1==t2)
		cout<<"t1==t2"<<endl;
	else
		cout<<"t1!=t2"<<endl;	
	
}