#pragma once
#include <string>
#include <stdexcept>
#include <algorithm>

using std::string;

class CensorString : public string
{	
public:
	using string::string;

	void swap(string&);
};

