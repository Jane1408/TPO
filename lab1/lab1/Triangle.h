#pragma once


class CTriangle
{
public:
	CTriangle(std::vector<double> const& input);
	~CTriangle();

	void FindAnswer();
	std::string GetAnswer();


	std::vector <double> m_lengthOfSides;
	std::string m_answer;
};

