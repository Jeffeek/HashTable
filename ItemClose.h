#pragma once
#include <vector>
using namespace std;
template <class T>
class ItemClose
{
private:
public:
	int Key;
	T *node = nullptr;

	ItemClose(int key)
	{
		Key = key;
	}

	int GetKey()
	{
		return Key;
	}

};

