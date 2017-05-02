#include <istream>
#include <ostream>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <stdio.h>
#include <windows.h>
#include <algorithm>
#include <utility>

//enum funciones { add, add_basics, del, info, sort, clean, help};

struct pair_hash {
	template <class T1, class T2>
	std::size_t operator () (const std::pair<T1, T2> &p) const {
		auto h1 = std::hash<T1>{}(p.first);
		auto h2 = std::hash<T2>{}(p.second);
		return h1 ^ h2;
	}
};

std::vector<std::string> list({"Air", "Earth", "Fire", "Water"});
std::vector<std::string> basics({ "Air", "Earth", "Fire", "Water" });

using suma = std::pair<std::string, std::string>;

std::unordered_map <suma, std::string, pair_hash> elementos;




//enum funciones { add, add_basics, del, info, sort, clean, help};

void add(int elem) // Y
{
	list.insert(list.end(), list[elem - 1]);
}

void add_basics() //Y
{
	list.insert(list.end(), basics[0]);
	list.insert(list.end(), basics[1]);
	list.insert(list.end(), basics[2]);
	list.insert(list.end(), basics[3]);
}

void del(int aux) //Y
{
	list.erase(list.begin() + aux - 1);
}

void info(int elem) //Y
{
	std::string url = "https://en.wikipedia.org/wiki/" + list[elem - 1];
	ShellExecuteA(nullptr, "open", url.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
}

void sort() //Y
{
	std::sort(list.begin(), list.end());
}

void clean() //Y
{
	sort();
	for (int i = 0; i < list.size(); i++)
	{
		for (int j = i + 1; j < list.size(); j++)
		{
			if (list[i] == list[j])
			{
				del(j);
			}
		}
	}
}

void help() //Y
{
	//---------------------------------
	//------ COUT de la interfaz ------
	//---------------------------------

	std::cout << "Alchemy" << std::endl << std::endl;

}

void combine(int elem1, int elem2)
{
	suma resultado;
	std::string sum;

	resultado.first = list[elem1 - 1];
	resultado.second = list[elem2 - 1];
	
	sum = elem1 + elem2;

	list.insert(list.end(), sum);

	del(elem2);
	del(elem1);
}

void config() //Y
{
	std::string line;
	
	std::ifstream fentrada;

	fentrada.open("elements.dat");

	std::string getResult;

	while (getline(fentrada, line))
	{
		
		suma key;

		getResult = line.substr(0, line.find("="));
		key.first = line.substr(line.find("=") + 2, line.find("+") - line.find("=") - 3);
		key.second = line.substr(line.find("+") + 2, line.find("\n") - line.find("+"));

		elementos[key] = getResult;
	}

	fentrada.close();
}

void print() //Y
{
	for (int i = 0; i < list.size(); i++)
	{
		std::cout << i + 1 << "   " << list[i] << std::endl;
	}
}

int main()
{
	// Variable para almacenar la entrada del jugador
	std::string func;

	// Uso en funciones
	int aux;
	int sum1, sum2;

	config();
	help();
	//combine(3, 4);
	print();

	while (true)
	{
		std::cin >> func;
		std::cout << std::endl;

		system("cls");

		if (func == "add") 
		{
			std::string num;
			int num2;
			std::cin >> num;
			num2 = std::stoi(num);

			if (num2 <= list.size())
			{
				add(num2);
			}
			else
			{
				std::cout << "Entra otro elemento, el anterior es demasiado grande" << std::endl;
			}

		}
		
		else if (func == "addbasics")
		{
			add_basics();
		}
		
		else if (func == "del")
		{
			std::string num;
			int num2;
			std::cin >> num;
			num2 = std::stoi(num);

			del(num2);
		}

		else if (func == "info")
		{
			std::string num;
			int num2;
			std::cin >> num;
			num2 = std::stoi(num);

			info(num2);
		}
		
		else if (func == "sort")
		{
			sort();
		}
		
		else if (func == "clean")
		{
			clean();
		}
		
		else if (func == "help")
		{
			help();
		}
		
		else if (func == "%d %d")
		{
			std::string snum1, snum2;
			int num1, num2;
			snum1 = func.substr(0, func.size() - func.find(" "));
			num1 = std::stoi(snum1);
			
			snum2 = func.substr(func.size() - func.find(" "), func.size());
			num2 = std::stoi(snum2);
		}

		print();
	}

	return 0;

}