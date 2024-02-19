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
	int index;

	Item() {}
	Item(int id, string name, float price, Item::category cat)
	{
		_id = id;
		_name = name;
		_price = price;
		_category = cat;
	}

};

