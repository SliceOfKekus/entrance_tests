#include <iostream>

void toBin(int num)
{
	size_t size = 8 * sizeof(int);

	for (int bit = 1; bit <= size; ++bit)
	{
		if (num < 0)
			std::cout << "1";
		else
			std::cout << "0";

		if (bit % 4 == 0)
			std::cout << " ";
		
		num = num << 1;
	}

}

int main()
{
	toBin(-1);
	std::cout << std::endl;
	toBin(0);
	std::cout << std::endl;
	toBin(INT_MAX);
	std::cout << std::endl;
	toBin(1024);
	return 0;
}