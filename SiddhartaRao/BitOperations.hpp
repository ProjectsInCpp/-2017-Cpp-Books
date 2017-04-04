#include <iostream>

constexpr const char EOL = '\n';

namespace shifting
{

int multiplyBy(int inVal, int shift)
{
	return inVal << shift;
}

int devideBy(int inVal, int shift)
{
	return inVal >> shift;
}

void start()
{
	std::cout << "*************** SHIFTING ***************" << EOL;
	std::cout << "4 * 2^3 = " << multiplyBy(4, 3) << EOL;
	std::cout << "***************" << EOL << EOL;

	std::cout << "16 / 2^2 = " << devideBy(16, 2) << EOL;
	std::cout << "***************" << EOL;

	std::cout << "16 / 2^(-2) = " << multiplyBy(16, -1) << EOL;
	std::cout << "***************" << EOL;
}

}
