#include "CensorString.h"

void CensorString::swap(string& str)
{
	if (this != &str)
	{
		std::string temp;

		temp.assign("", str.size());
		std::transform(str.begin(), str.end(), temp.begin(), tolower);

		if (temp.find("dr.web") == string::npos)
			this->string::swap(str);
		else
			throw std::invalid_argument("There's a dr.web!");
	}

}
