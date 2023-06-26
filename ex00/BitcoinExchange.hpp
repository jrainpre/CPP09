#ifndef BITCOINEXCHNAGE_HPP
#define BITCOINEXCHNAGE_HPP
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <stdlib.h>
#include <list>
#include <algorithm>
#include <string>
#include <iomanip>




class BitcoinExchange
{
private:
	std::map<std::string, float> _db;
    std::list<std::pair<std::string, float> > _convert;
public:
	BitcoinExchange(/* args */);
	~BitcoinExchange();
	BitcoinExchange(BitcoinExchange const & src);
	BitcoinExchange & operator=(BitcoinExchange const & rhs);
	void fill_db(std::string filename);
	void fill_input(std::string filename);
	void convert();
	int check_date_valid(std::string date);
	int check_date_in_database(std::string date);
	int convert_date_to_int(std::string date);
	float return_closest_rate(std::string date);
	int check_value_valid(float value);
};






#endif