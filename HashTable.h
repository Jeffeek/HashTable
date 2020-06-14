#pragma once
#include "Item.h"
#include <iostream>

template <class T>
class HashTable
{
private:
	int _size;
	Item<T>** items;

public:
	HashTable(int size)
	{
		items = new Item<T>*[size];
		for (int i = 0; i < size; i++)
		{
			items[i] = new Item<T>(i);
		}
		_size = size;
	}

	void Add(T item)
	{
		int key = GetHash(item);
		items[key]->Nodes.push_back(item);
	}

	void Remove(T item)
	{
		int key = GetHash(item);
		auto itemIt = find(items[key]->Nodes.begin(), items[key]->Nodes.end(), item);
		if (itemIt != items[key]->Nodes.end())
		{
			items[key]->Nodes.erase(itemIt);
		}
	}

	bool Search(T item)
	{
		return find(items[GetHash(item)]->Nodes.begin(), items[GetHash(item)]->Nodes.end(), item) != items[GetHash(item)]->Nodes.end();
	}

	int GetHash(T item)
	{
		auto key = item.GetHashCode();
		return key % _size;
	}

	void ShowTable()
	{
		for (int i = 0; i < _size; i++)
		{
			if (items[i]->Nodes.size() > 0)
			{
				std::cout << i;
				for (int j = 0; j < items[i]->Nodes.size(); j++)
				{
					std::cout << "\n\t" << items[i]->Nodes[j].ToString();
				}
			}
		}
	}

};

