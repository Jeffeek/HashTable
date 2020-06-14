#pragma once
#include <string>

class Referate
{
private:
	std::string Theme;
	int Year;
	int CountOfSheets;
	std::string Author = "";
public:

	Referate() {  }
	
	std::string GetTheme()
	{
		return Theme;
	}

	std::string GetAuthor()
	{
		return Author;
	}

	int GetYear()
	{
		return Year;
	}

	int GetCountOfSheets()
	{
		return Year;
	}

	int GetHashCode()
	{
		return Author[0] % 10;
	}

	bool operator==(Referate pus) const
	{
		return Year == pus.GetYear() && Author == pus.GetAuthor() && Theme == pus.GetTheme() && CountOfSheets == pus.GetCountOfSheets();
	}

	Referate(std::string theme, int year, int countOfSheets, std::string author)
	{
		Theme = theme;
		Year = year;
		CountOfSheets = countOfSheets;
		Author = author;
	}

	std::string ToString()
	{
		return "Тема: " + Theme + ", Год: " + std::to_string(Year) + ", Количество страниц: " + std::
			to_string(CountOfSheets) + ", Автор: " + Author;
	}
};

