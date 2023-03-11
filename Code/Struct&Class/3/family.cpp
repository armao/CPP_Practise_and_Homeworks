#include <iostream>
#include <iomanip>
#include "family.h"
#include "human.h"
#include <utility>
#include <iterator>

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
	m_member.push_back(std::move(a_human));
}

const human& family::longest_name_member() const
{
	auto longer_one = m_member.cbegin();
	for (auto ibegin = longer_one +1, iend = m_member.cend();
		ibegin != iend; ++ibegin)
	{
		if (ibegin->name().length() > longer_one->name().length())
		{
			longer_one = ibegin;
		}
	}

	return *longer_one;
}

bool family::has_member_with_name(const std::string& a_string) const
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
