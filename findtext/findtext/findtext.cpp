#include <stdio.h>
#include <windows.h>
#include <iostream> 
#include <fstream> 
#include <string>

/*FINDTEXT*/

int get_number_founded(std::string&const str_find, std::istream& file, std::ostream& output)
{
	int number_of_string = 0;
	while (!file.eof())
	{
		std::string str_read; //string to read
		number_of_string++;
		std::getline(file, str_read);

		if (str_read.find(str_find) != std::string::npos)
		{
			output << "Founded in " << number_of_string << std::endl;
			output << str_read << std::endl;
		}
	}
	return number_of_string;
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		return 1;
	}

	std::string file_name = argv[1];
	std::string str_find = argv[2];; //string to find
	std::ifstream input_file(file_name);

	if (!input_file.is_open())
	{
		std::cout << "There is a problem with opening file!" << std::endl;
		return 1;
	}

	if (get_number_founded(str_find, input_file, std::cout) == 0)
	{
		std::cout << "not founded" << std::endl;
	}

	return 0;
}