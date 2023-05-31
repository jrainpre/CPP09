#ifndef BITCOINEXCHNAGE_HPP
#define BITCOINEXCHNAGE_HPP
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <stdlib.h>




class BitcoinExchange
{
private:
	std::map<std::string, float> _db;
	std::map<std::string, float> _convert;


public:
	BitcoinExchange(/* args */);
	~BitcoinExchange();
	void fill_db(std::string filename);
	void fill_input(std::string filename);
	void convert();
};

BitcoinExchange::BitcoinExchange(/* args */)
{
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::fill_db(std::string filename)
{
    std::string line;
    std::string date;
	std::string temp;
	float value;


    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cout << "Could not open file\n";
		exit(1);
    }
	std::getline(file, line);
	line = "";
    while (std::getline(file, line))
    {
    	std::istringstream ss(line);
        std::getline(ss, date, ',');
		std::getline(ss, temp);
		value = atof(temp.c_str());
		_db[date] = value;
		line = "";
	}
}

void BitcoinExchange::fill_input(std::string filename)
{
	std::string line;
	std::string date;
	std::string temp;
	float value;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Could not open file\n";
		exit(1);
	}
	std::getline(file, line);
	line = "";
    while (std::getline(file, line))
    {
    	std::istringstream ss(line);
        std::getline(ss, date, '|');
		std::getline(ss, temp);
		value = atof(temp.c_str());
		_convert[date] = value;
		line = "";
	}
}

void BitcoinExchange::convert()
{
	for (std::map<std::string, float>::iterator it = _convert.begin(); it != _convert.end(); it++)
	{
		for (std::map<std::string, float, float>::iterator it2 = _db.begin(); it2 != _db.end(); it2++)
		{
			if (it->first == it2->first)
			{
				if (it->second < 0 || it->second > 1000)
					std::cout << "Invalid value: " << it->first << std::endl;
				else
					std::cout << it->first << " => " << it->second * it2->second << std::endl;
			}
		}
			if (it == _db.end())
				std::cout << "Invalid date: " << it->first << std::endl;
	}
}







#endif