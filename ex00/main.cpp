#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <stdlib.h>
#include "BitcoinExchange.hpp"


int main()
{
	BitcoinExchange b;
	b.fill_db("data.csv");
	b.fill_input("input.txt");
	b.convert();


}


