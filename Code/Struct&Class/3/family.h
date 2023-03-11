#pragma once
#include "human.h"
#include <vector>

class family
{
public:
	explicit family();
	explicit family(human a_human);

	void add_member(human a_human);

	human& longest_name_member() const;

	bool has_member_with_name(std::string a_string);

	void print();

private:
	std::vector<human> m_member;

};

