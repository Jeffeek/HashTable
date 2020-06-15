#pragma once
#include <string>

class Student
{
private:
	std::string Surname = "";
	std::string Group;
	int Mark;
	int Number;
public:

	Student() {  }

	Student(std::string _surname, std::string _group, int _mark, int _number)
	{
		Surname = _surname;
		Group = _group;
		Mark = _mark;
		Number = _number;
	}

	std::string GetSurname()
	{
		return Surname;
	}

	std::string GetGroup()
	{
		return Group;
	}

	int GetMark()
	{
		return Mark;
	}

	int GetNumber()
	{
		return Number;
	}

	int GetHashCode()
	{
		return static_cast<int>(pow(Number, 2)) % 5;
	}

	std::string ToString()
	{
		return "Фамилия: " + Surname + ", Группа: " + Group + ", Оценка: " + std::
			to_string(Mark) + ", Номер договора: " + std::to_string(Number);
	}

	bool operator==(Student pus) const
	{
		return Surname == pus.GetSurname() && Group == pus.GetGroup() && Mark == pus.GetMark() && Number == pus.GetNumber();
	}
};

