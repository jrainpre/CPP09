#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <stdlib.h>
#include "BitcoinExchange.hpp"


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./a.out <filename>" << std::endl;
		exit(1);
	}
	BitcoinExchange b;
	b.fill_db("data.csv");
	b.fill_input(argv[1]);
	b.convert();
}


