// lab1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "Triangle.h"



bool IsCorrectValue(std::string const& value)
{
	if ((value == "0") || (value == "0.0"))
	{
		return true;
	}
	double num = std::atof(value.c_str());
	if (num <= 0)
	{
		return false;
	}
	return true;
}

bool AreCorrectArguments(std::vector <std::string> const& arguments)
{
	if (arguments.size() == 0)
	{
		std::cout << "������� ����� ������ � �������� ����������.������ ����� : triangle.exe a b c" << std::endl;
		return false;
	}
	else if (arguments.size() < 3)
	{
		std::cout << "������������ ����������. ������ ����� : triangle.exe a b c" << std::endl;
		return false;
	}
	else if (arguments.size() > 3)
	{
		std::cout << "������ ���������. ������ ����� : triangle.exe a b c" << std::endl;
		return false;
	}
	for (size_t i = 0; i < arguments.size(); i++)
	{
		if (!IsCorrectValue(arguments[i]))
		{
			std::cout << "�������� ��������� " << arguments[i] <<" �������� ������������." << std::endl;
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
			double value = std::atof(arguments[i].c_str());
			lengthsOfSides.push_back(value);
		}

		CTriangle triangle(lengthsOfSides);
		std::cout << triangle.GetAnswer() << std::endl;
	}
    return 0;
}

