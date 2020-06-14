#pragma once
#include <vector>
using namespace std;
template <class T>
class Item
{
private:
	int Key;
public:
	vector<T> Nodes;

	Item(int key)
	{
		Key = key;
	}

	int GetKey()
	{
		return Key;
	}

};

