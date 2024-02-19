#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Item.h"
#include <ctime>

using namespace std;

vector<Item> items;
string fileName = "product_data.txt";
ifstream productData(fileName);

//gets number of lines in product txt file
int getNumLines()
{
	int numLines = 0;
	string line;

	ifstream file(fileName);
	while (getline(file, line))
	{
		numLines++;
	}

	return numLines;
}

//adds item to database with specified details in parameters
void insert(int id, string name, float price, Item::category cat)
{
	Item newItem = Item(id, name, price, cat);
	items.push_back(newItem);
}

//update functon that can update item id, name, price, or category
void update(Item item, int id)
{
	items[item.index]._id = id;
}
void update(Item item, string name)
{
	items[item.index]._name = name;
}
void update(Item item, float price)
{
	items[item.index]._price = price;
}
void update(Item item, Item::category cat)
{
	items[item.index]._category = cat;
}

//deletes item at index
void del(vector<Item> items, int index)
{
	items.erase(items.begin() + index);
}

//finds and returns item with specified id or name
Item search(int id)
{
	for (Item item : items)
	{
		if (item._id == id)
		{
			return item;
		}
	}

	return Item();
}
Item search(string name)
{
	for (Item item : items)
	{
		if (item._name == name)
		{
			return item;
		}
	}

	return Item();
}


void bubbleSortPrice(vector<Item> &items)
{
	for (int i = 0; i < items.size() - 1; i++)
	{
		for (int j = 0; j < items.size() - 1 - i; j++)
		{
			if (items[j]._price > items[j + 1]._price)
			{
				//swap positions
				Item temp = items[j + 1];
				items[j + 1] = items[j];
				items[j] = temp;
			}
		}
	}
}

void printDatabase(vector<Item> _items)
{
	for (int i = 0; i < _items.size(); i++)
	{
		cout << _items[i]._id << ", " << _items[i]._name << ", " << _items[i]._price << ", ";

		if (_items[i]._category == Item::Electronics)
		{
			cout << "Electronics\n";
		}
		else if (_items[i]._category == Item::Books)
		{
			cout << "Books\n";
		}
		else if (_items[i]._category == Item::Clothing)
		{
			cout << "Clothing\n";
		}
		else if (_items[i]._category == Item::HomeKitchen)
		{
			cout << "Home & Kitchen\n";
		}
	}
}

void initializeDatabase()
{
	productData.seekg(0);

	//adds products from txt file to database
	for (int i = 0; i < getNumLines(); i++)
	{
		Item item = Item();
		items.push_back(item);

		items[i].index = i;

		string line;
		getline(productData, line);

		stringstream ss(line);
		string str;

		if (getline(ss, str, ','))
		{
			stringstream(str) >> items[i]._id;
		}
		if (getline(ss, str, ','))
		{
			stringstream(str) >> items[i]._name;
		}
		if (getline(ss, str, ','))
		{
			stringstream(str) >> items[i]._price;
		}
		if (getline(ss, str, ','))
		{
			if (str == " Electronics")
			{
				items[i]._category = Item::Electronics;
			}
			else if (str == " Books")
			{
				items[i]._category = Item::Books;
			}
			else if (str == " Clothing")
			{
				items[i]._category = Item::Clothing;
			}
			else if (str == " Home & Kitchen")
			{
				items[i]._category = Item::HomeKitchen;
			}
		}
	}
}

int main()
{
	//build database from txt file
	initializeDatabase();

	


	return 0;
}



