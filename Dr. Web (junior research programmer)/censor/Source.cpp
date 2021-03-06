#include <iostream>

#include "CensorString.h"

int main()
{
	CensorString test("asd asd asd"); //????

	string notW("asdasdasdasdasd");
	CensorString Web("DR.web");

	test.swap(notW);
	test.swap(Web);

	return 0;
}