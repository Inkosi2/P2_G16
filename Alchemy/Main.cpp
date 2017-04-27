#include <istream>
#include <iostream>
#include <fstream>
#include <map>
#include <string>

void main()
{
	struct suma
	{
		std::string sum1;
		std::string sum2;
	};
	std::map <std::string, suma> element;
	
	std::ifstream fentrada("elements.dat");

	char line[250];
	while (fentrada.getline(line, 250))
	{
		std::cout << line << std::endl;
	}
}