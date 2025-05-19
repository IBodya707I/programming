#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
class figura
{
	public:
		virtual float area()=0;
		virtual float perimetr()=0;
		virtual void print()=0;
};	
class rectangle:public figura
{
	private:
	float a,b;
	public:
	rectangle(float x,float y)
	{
		a=x;
		b=y;
	}
	float area()override
	{
		return a*b;
	}	
	float perimetr()override
	{
		return 2*(a+b);
	}
	void print()
	{
		cout<<"rectangle ";
	}
};
class triangle: public figura
{
	private:
	float a,b,c;
	public:
	triangle(float x,float y,float z) 
	{
	    a=x;
    	b=y;
    	c=z;
	}
	float perimetr()override
	{
		return a+b+c;
	}
	float area()override
	{
		float p=perimetr()/2;
		return sqrt(p*(p-a)*(p-b)*(p-c));
	}
	void print()
	{
		cout<<"triangle ";
	}
};
class circle:public figura
{
	private:
	float radius;
	public:
	circle(float r)
	{
		radius=r;
	}
	float area()override
	{
		return 3.14*radius*radius;
	}	
	float perimetr()override
	{
		return 3.14*2*radius;
	}
	void print()
	{
		cout<<"circle ";
	}
};
int main()
{
	vector<figura*> figures;
	figures.push_back(new rectangle(3.5,5));
	figures.push_back(new triangle(3,4,5));
	figures.push_back(new circle(4.6));
	int i;
	for(i=0;i<figures.size();i++)
	{
		cout<<i+1<<": ";
		figures[i]->print();
		cout<<" area - "<<figures[i]->area()<<" perimetr - "<<figures[i]->perimetr()<<endl;
	}
	return 0;
}