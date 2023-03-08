#include <iostream>
#include <iomanip>
#include "family.h"
#include "human.h"
#include <utility>

using namespace std;

family::family()
{
}

family::family(human a_human)
{
	m_member.push_back(a_human);
}

void family::add_member(human a_human)
{
	m_member.push_back(a_human);
}

human& family::longest_name_member()
{
	size_t longer_one = 0;
	for (size_t i = 1; i < m_member.size(); ++i)
	{
		if(m_member.at(longer_one).name_length() < m_member.at(i).name_length())
		{
			longer_one = i;
		}
	}

	return m_member.at(longer_one);
}

bool family::has_member_with_name(std::string a_string)
{
	for (size_t i = 0; i < m_member.size(); ++i)
	{
		if (m_member.at(i).name() == a_string) 
		{
			return true;
		}
	}
	
	return false;
}

void family::print() 
{
	for (size_t i = 0; i < m_member.size(); ++i)
	{
		cout << m_member.at(i) << endl;
	}
	
}
