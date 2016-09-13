// lab1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <cctype> 
#include "Triangle.h"



bool IsCorrectValue(std::string const& value)
{
	for (size_t i = 0; i < value.length(); i++)
	{
		if ((value[i] == ',') && (i != 0) && (i != value.length() - 1))
		{
			continue;
		}
		if (!isdigit(value[i]))
		{
			return false;
		}
	}
	return true;
}

bool AreCorrectArguments(std::vector <std::string> const& arguments)
{
	if (arguments.size() == 0)
	{
		std::cout << "Укажите длины сторон в качестве параметров.Формат ввода : triangle.exe a b c" << std::endl;
		return false;
	}
	else if (arguments.size() < 3)
	{
		std::cout << "Недостаточно аргументов. Формат ввода : triangle.exe a b c" << std::endl;
		return false;
	}
	else if (arguments.size() > 3)
	{
		std::cout << "Лишние агрументы. Формат ввода : triangle.exe a b c" << std::endl;
		return false;
	}
	for (size_t i = 0; i < arguments.size(); i++)
	{
		if (!IsCorrectValue(arguments[i]))
		{
			std::cout << "Значение агрумента " << arguments[i] <<" является некорректным." << std::endl;
			return false;
		}
	}
	return true;
}

void ConvertToCorrectType(std::vector <std::string> & input)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		for (size_t j = 0; j < input[i].size(); j++)
		{
			if (input[i][j] == '.')
			{
				input[i][j] = ',';
			}
		}
	}
}

int main(int argc, char * argv[])
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	std::vector <std::string> arguments;
	std::vector <double> lengthsOfSides;
	
	for (int i = 1; i < argc; i++)
	{
		arguments.push_back(argv[i]);
	}

	ConvertToCorrectType(arguments);

	if (AreCorrectArguments(arguments))
	{
		for (size_t i = 0; i < arguments.size(); i++)
		{
			double value = std::strtof(arguments[i].c_str(), nullptr);
			lengthsOfSides.push_back(value);
		}

		CTriangle triangle(lengthsOfSides);
		std::cout << triangle.GetAnswer() << std::endl;
	}
    return 0;
}

