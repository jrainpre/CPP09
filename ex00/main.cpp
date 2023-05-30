#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <stdlib.h>


int main()
{
	std::map<std::string, float> db;
    std::string line;
	std::string field;
    std::string date;
	std::string temp;
	float value;


    std::ifstream file("data.csv"); // replace with your file path

    if (!file.is_open()) {
        std::cout << "Could not open file\n";
        return 1;
    }
	std::getline(file, line);
	line = "";
    while (std::getline(file, line)) // read the file line by line
    {
    	std::istringstream ss(line);
        std::getline(ss, date, ',');
		std::getline(ss, temp);
		value = atof(temp.c_str());
		db[date] = value;
		line = "";
	}
	for (std::map<std::string, float>::iterator it = db.begin(); it != db.end(); it++)
	{
		std::cout << "date: " << it->first << std::endl << "value: " << it->second << std::endl;
	}
    file.close();


}


