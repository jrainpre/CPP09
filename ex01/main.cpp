#include "RPN.hpp"

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./RPN \"5 4 7 * + 1 -\"" << std::endl;
		return 1;
	}
	RPN rpn(argv[1]);
	return 0;
}