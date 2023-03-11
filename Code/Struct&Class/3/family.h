#pragma once
#include "human.h"
#include <vector>

class family
{
public:
	explicit family();
	explicit family(human a_human);

	void add_member(human a_human);

	const human& longest_name_member() const;

	bool has_member_with_name(const std::string& a_string) const;

	void print();

private:
	std::vector<human> m_member;

};

