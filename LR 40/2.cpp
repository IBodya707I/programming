#include <iostream>
#include <vector>
using namespace std;
class goods
{
	protected:
	string name;
	float price;
	public:
	goods(string n,float p)
	{
		name=n;
		price=p;
	}
	virtual float getPrice()
	{
		return price;
	}
		
};
class goodsWithDiscount:public goods
{
	private:
	float priceWithDiscount;
	public:
	goodsWithDiscount(string n,float p):goods(n,p)
	{
		priceWithDiscount=p;
	}
	void applyDiscount(float percent)
	{
		auto discount=[percent](float p){
		return p-p*(percent/100);
		};	
		priceWithDiscount=discount(price);
	}
	float getPrice() override
	{
		return priceWithDiscount;
	}
	void print()
	{
		cout<<"Goods: "<<name<<", price - "<<price<<", price with discount - "<<priceWithDiscount<<endl;	
	}	
};
int main()
{
	vector<goodsWithDiscount> Goods={
		{"notebook",20000},
		{"phone",10000},
		{"keyboard",800}
	};
	int i;
	vector<float> percents={10,15,7};
	for(i=0;i<3;i++)
	{
		Goods[i].applyDiscount(percents[i]);
		Goods[i].print();
	}
	
	return 0;
}