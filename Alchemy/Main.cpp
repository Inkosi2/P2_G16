#include <istream>
#include <ostream>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>

int main()
{
	struct suma
	{
		std::string sum1;
		std::string sum2;
	};
	
	std::map <suma, std::string> element;
	
	std::string line;
	std::string getKey;
	std::string getSum1;
	std::string getSum2;


	// anterior código
	/*std::ifstream fentrada;
	fentrada.open("C:\\Users\Oscar\Desktop\elements.dat");

	std::ostream fsalida("elements2.dat");

	std::string line;

	while (std::getline(fentrada, line))
	{
		
		std::cout << line;
	}

	return 0;*/

	std::ifstream fentrada("elements.dat");


	while (!fentrada.eof)
	{
		std::getline(fentrada, line);
		
		std::getc(line);
	}

}

