#pragma once
using namespace std;
class Item
{
public:
	int _id;
	string _name;
	float _price;
	enum category { Electronics, Books, Clothing, HomeKitchen };
	category _category;
	int _index;

	void update(int);
	void update(string);
	void update(float);
	void update(category);


	Item() {}
	Item(int id, string name, float price, category cat)
	{
		_id = id;
		_name = name;
		_price = price;
		_category = cat;
	}

};
void Item::update(int id)
{
	_id = id;
}
void Item::update(string name)
{
	_name = name;
}
void Item::update(float price)
{
	_price = price;
}
void Item::update(category cat)
{
	_category = cat;

}
