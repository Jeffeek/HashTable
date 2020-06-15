#pragma once
#include "Item.h"
#include <iostream>
#include "Referate.h"

class HashTable
{
private:

	int _size;
	vector<Item<Referate>*> items;

public:

	HashTable(int size)
	{
		for (int i = 0; i < size; i++)
		{
			auto S = new Item<Referate>(i);
			items.push_back(S);
		}
		_size = size;
	}

	int GetSize()
	{
		return _size;
	}

	void Add(Referate item)
	{
		int key = GetHash(item.GetAuthor());
		items[key]->Nodes.push_back(item);
	}

	void Remove(string key)
	{
		int index = GetHash(key);
		items[index]->Nodes.erase(items[index]->Nodes.begin());
	}

	int GetHash(string key)
	{	
		return key[0] % 10 % _size;
	}

	vector<Item<Referate>*> GetList()
	{
		return items;
	}

	void ShowTable()
	{
		for (int i = 0; i < _size; i++)
		{
			if (items[i]->Nodes.size() > 0)
			{
				std::cout << "\n" << i;
				for (int j = 0; j < items[i]->Nodes.size(); j++)
				{
					std::cout << "\n\t" << items[i]->Nodes[j].ToString();
				}
			}
		}
	}
};

