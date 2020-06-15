#pragma once
#include "Item.h"
#include <iostream>
#include "ItemClose.h"
#include "Student.h"

class HashTableClose
{
private:
	int _size;
	vector<ItemClose<Student>*> items;

public:

	HashTableClose(int size)
	{
		for (int i = 0; i < size; i++)
		{
			auto S = new ItemClose<Student>(i);
			items.push_back(S);
		}
		_size = size;
	}

	void Add(Student *item)
	{
		int index = GetHash(to_string(item->GetNumber()));
		if (items[index]->node == nullptr)
		{
			items[index]->node = item;
			items[index]->Key = index;
		}
		else
		{
			if (CheckFullFilled())
			{
				cout << "\nТаблица заполнена\n";
			}
			else
			{
				bool added = false;
				for (int i = index; i < items.size(); i++)
				{
					if (items[i]->node == nullptr)
					{
						items[i]->node = item;
						items[i]->Key = i;
						added = true;
						break;
					}
				}
				if (!added)
				{
					for (int i = 0; i < index; i++)
					{
						if (items[i]->node == nullptr)
						{
							items[i]->node = item;
							items[i]->Key = i;
							break;
						}
					}
				}
			}
		}
	}

	bool CheckFullFilled()
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

	void Remove(string key)
	{
		int index = GetHash(key);
		if (items[index]->node != nullptr && items[index]->node->GetNumber() == atoi(key.c_str()))
		{
			delete items[index]->node;
			items[index]->node = nullptr;
		}
		else if (items[index]->node != nullptr && items[index]->node->GetNumber() != atoi(key.c_str()))
		{
			bool deleted = false;
			while (!deleted)
			{
				index++;
				if (items[index]->node->GetNumber() == atoi(key.c_str()))
				{
					delete items[index]->node;
					items[index]->node = nullptr;
					deleted = true;
				}
				if (index == items.size() - 1)
				{
					index = 0;
					while (!deleted)
					{					
						if (items[index]->node->GetNumber() == atoi(key.c_str()))
						{
							delete items[index]->node;
							items[index]->node = nullptr;
							deleted = true;
						}
						index++;
					}
				}
			}
		}
	}

	int GetHash(string key)
	{
		return int(pow(key[0], 2)) % items.size();
	}

	vector<ItemClose<Student>*> GetList()
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

