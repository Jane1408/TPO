#include "stdafx.h"
#include <algorithm>
#include "Triangle.h"


CTriangle::CTriangle(std::vector<double> const& input)
{
	m_lengthOfSides = input;
	std::sort(m_lengthOfSides.begin(), m_lengthOfSides.end());
	FindAnswer();
}



CTriangle::~CTriangle()
{
}

void CTriangle::FindAnswer()
{
	if (m_lengthOfSides[0] + m_lengthOfSides[1] > m_lengthOfSides[2])
	{
		if (m_lengthOfSides[2] == m_lengthOfSides[0])
		{
			m_answer = "��������������";
		}
		else if ((m_lengthOfSides[2] == m_lengthOfSides[1]) || (m_lengthOfSides[0] == m_lengthOfSides[1]))
		{
			m_answer = "��������������";
		}
		else
		{
			m_answer = "�������";
		}
	}
	else
	{
		m_answer = "�� �����������";
	}
}

std::string CTriangle::GetAnswer()
{
	return m_answer;
}
