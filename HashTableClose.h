#pragma once
#include "Item.h"
#include <iostream>
#include "ItemClose.h"
#include "Student.h"

template <class T>
class HashTableClose
{
private:
	int _size;
	vector<ItemClose<T>*> items;

public:
	HashTableClose(int size)
	{
		items.reserve(size);
		for (int i = 0; i < size; i++)
		{
			auto S = new ItemClose<T>(i);
			items.push_back(S);
		}
		_size = size;
	}

	void Add(T *item)
	{
		int key = GetHash(*item);
		if (items[key]->node == nullptr)
		{
			items[key]->node = item;
		}
		else
		{
			if (CheckFullFIlled())
			{
				cout << "\nТаблица заполнена\n";
			}
			else
			{
				bool added = false;
				for (int i = key; i < items.size(); i++)
				{
					if (items[i]->node == nullptr)
					{
						items[i]->node = item;
						added = true;
						break;
					}
				}
				if (!added)
				{
					for (int i = 0; i < key; i++)
					{
						if (items[i]->node == nullptr)
						{
							items[i]->node = item;
							break;
						}
					}
				}
			}
		}
	}

	bool CheckFullFIlled()
	{
		for (int i = 0; i < items.size(); i++)
		{
			if (items[i]->node == nullptr)
			{
				return false;
			}
		}
		return true;
	}

	void Remove()
	{
		int key = GetHash(item);
		items[key]->node = nullptr;
	}

	bool Search(T item)
	{
		return find(items.begin(), items.end(), item) != items.end();
	}

	int GetHash(T item)
	{
		int hash = item.GetHashCode();
		return hash % _size;
	}

	vector<ItemClose<T>*> GetList()
	{
		return items;
	}

	void ShowTable()
	{
		for (int i = 0; i < items.size(); i++)
		{
			if (items[i]->node != nullptr)
			{
				cout << "\n" << items[i]->GetKey();
				cout << "\n\t" << items[i]->node->ToString();
			}
		}
	}
};

