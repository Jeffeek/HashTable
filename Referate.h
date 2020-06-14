#pragma once
#include <string>

class Referate
{
private:
	int _year;
	std::string _name;
public:

	Referate(int year, std::string name)
	{
		_year = year;
		_name = name;
	}

	std::string GetName()
	{
		return _name;
	}

	int GetHashCode()
	{
		return _name[0] % 10;
	}

	bool operator==(Referate pus) const
	{
		return _year == pus._year && _name == pus._name;
	}

	std::string ToString()
	{
		return _name + " " + std::to_string(_year);
	}


};

