#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(/* args */)
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src)
{
	*this = src;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs)
{
	if (this != &rhs)
	{
		_db = rhs._db;
		_convert = rhs._convert;
	}
	return *this;
}

void BitcoinExchange::fill_db(std::string filename)
{
    std::string line;
    std::string date;
	std::string temp;
	float value;


    std::ifstream file(filename.c_str());

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

    std::ifstream file(filename.c_str());
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
		date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
		std::getline(ss, temp);
		value = atof(temp.c_str());
		_convert.push_back(std::make_pair(date, value));
		line = "";
	}
}

int BitcoinExchange::check_date_valid(std::string date)
{
	std::string year;
	std::string month;
	int month_int;
	std::string day;
	int day_int;
	std::istringstream ss(date);
	std::getline(ss, year, '-');
	if (year.length() != 4)
		return 0;
	std::getline(ss, month, '-');
	if (month.length() != 2)
		return 0;
	if (atoi(month.c_str()) < 1 || atoi(month.c_str()) > 12)
		return 0;
	month_int = atoi(month.c_str());
	std::getline(ss, day, '-');
	if (day.length() != 2)
		return 0;
	day_int = atoi(day.c_str());
	if (day_int < 1 || day_int > 31)
		return 0;
	if (month_int == 2 && atoi(day.c_str()) > 28)
		return 0;
	if ((month_int == 4 || month_int == 6 || month_int == 9 || month_int == 11) && atoi(day.c_str()) > 30)
		return 0;
	return 1;
}

int BitcoinExchange::check_value_valid(float value)
{
	if (value < 0)
	{
		std::cout << "Error: Value too samall" <<  std::endl;
		return 0;
	}
	if (value > 1000)
	{
		std::cout << "Error: Value too big" << std::endl;
		return 0;
	}
	return 1;
}

int BitcoinExchange::convert_date_to_int(std::string date)
{
	date.erase(std::remove(date.begin(), date.end(), '-'), date.end());
	return atoi(date.c_str());
}

float BitcoinExchange::return_closest_rate(std::string date)
{
	int date_int = convert_date_to_int(date);
	int closest_date_int = 0;
	float closest_rate = 0;
	for (std::map<std::string, float>::iterator it = _db.begin(); it != _db.end(); it++)
	{
		if (closest_date_int == 0)
		{
			closest_date_int = convert_date_to_int(it->first);
			closest_rate = it->second;
		}
		else if (abs(date_int - convert_date_to_int(it->first)) < abs(date_int - closest_date_int))
		{
			closest_date_int = convert_date_to_int(it->first);
			closest_rate = it->second;
		}
	}
	return closest_rate;
}



void BitcoinExchange::convert()
{
	for (std::list<std::pair<std::string, float> >::iterator it = _convert.begin(); it != _convert.end(); it++)
	{
		if (check_date_valid(it->first) == 0)
		{
			std::cout << "Error: Invalid date: " << it->first << std::endl;
			continue;
		}
		if (check_value_valid(it->second) == 0)
			continue;
		float rate = return_closest_rate(it->first);
			std::cout << it->first << " => " << std::setprecision(2) << rate << " = " << std::setprecision(2) << it->second * rate << std::endl;
		}
}
