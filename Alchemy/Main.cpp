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


void add(int elem) // Y
{
	if (elem - 1 < list.size())
	{
		list.insert(list.end(), list[elem - 1]);
	}
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
	if (aux - 1 < list.size())
	{
		list.erase(list.begin() + aux - 1);
	}
}

void info(int elem) //Y
{
	if (elem - 1 < list.size())
	{
		std::string url = "https://en.wikipedia.org/wiki/" + list[elem - 1];
		ShellExecuteA(nullptr, "open", url.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
	}
}

void sort() //Y
{
	std::sort(list.begin(), list.end());
}

void clean() //Y
{
	sort();
	/*for (int i = 0; i < list.size(); i++)
	{
		for (int j = i + 1; j < list.size(); j++)
		{
			if (list[i] == list[j])
			{
				del(j);
			}
		}
	}*/
	list.erase(unique(list.begin(), list.end()), list.end());
}

void help() //Y
{
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "------------------ FULLENTI ALCHEMIST ------------------" << std::endl;
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "- Enter two numbers of your elements list to combine them." << std::endl;
	std::cout << "- Enter the word 'add' and the number of an element to add a new instance of that element." << std::endl;
	std::cout << "- Enter 'add basics' to add new instances of the 4 basic elements." << std::endl;
	std::cout << "- Enter the word 'delete' and the number of an element to erase it from your list." << std::endl;
	std::cout << "- Enter the word 'info' and the number of an element to get information about it in the explorer." << std::endl;
	std::cout << "- Enter the word 'sort' to sort by alphabetical order the elements in the list." << std::endl;
	std::cout << "- Enter the word 'clean' to delete all the instances of repeated elements." << std::endl;
	std::cout << "- Enter the word 'help' to show this tutorial." << std::endl;
	std::cout << std::endl << std::endl;

}

/*void combine(int elem1, int elem2)
{
	suma resultado;
	std::string sum;

	resultado.first = list[elem1 - 1];
	resultado.second = list[elem2 - 1];
	
	sum = resultado.first + resultado.second;

	list.insert(list.end(), sum);

	del(elem2);
	del(elem1);
}*/

void combo(int e1, int e2)
{
	suma clave;
	if (e1 != e2 && e1 - 1 < list.size() && e2 - 1 < list.size())
	{
		clave.first = list[e1 - 1];
		clave.second = list[e2 - 1];

		auto pos = elementos.find({ clave.first, clave.second });

		if (pos == elementos.end())
		{
			pos = elementos.find({ clave.second, clave.first});
		}

		if (pos != elementos.end() && (pos == elementos.find({ clave.first, clave.second }) || pos == elementos.find({ clave.second, clave.first }))) {
			/*if (!elementos.count(clave))
			{
				clave.first = list[e2 - 1];
				clave.second = list[e1 - 1];
				pos = elementos.find({ clave.first, clave.second });
			}

			if (elementos.count(clave))
			{
				list.insert(list.end(), pos->second);
				del(e1);
				del(e2);
			}*/
			list.push_back(pos->second);
			if (e1 > e2)
			{
				del(e1);
				del(e2);
			}
			else 
			{
				del(e2);
				del(e1);
			}
		}
		else
		{
			
		}
	}
	else
	{

	}
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
	print();

	while (true)
	{
		std::cin >> func;
		std::cout << std::endl;

		system("cls");

		if (func == "add") 
		{
			std::string num;
			std::cin >> num;

			if (num == "basics")
			{
				add_basics();
			}
			
			else 
			{
				int num2;
				num2 = std::stoi(num);
				if (num2 <= list.size())
				{
					add(num2);
				}
			}
		}
				
		else if (func == "delete")
		{
			std::string num;
			int num2;
			std::cin >> num;
			num2 = std::stoi(num);
			if (num2 <= list.size())
			{
				del(num2);
			}
		}

		else if (func == "info")
		{
			std::string num;
			int num2;
			std::cin >> num;
			num2 = std::stoi(num);
			if (num2 <= list.size())
			{
				info(num2);
			}
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
		
		else if (func == "combine")
		{
			std::string n1;
			std::cin >> n1;
			if (std::stoi(n1) <= list.size())
			{
				std::string n2;
				std::cin >> n2;
				if (std::stoi(n2) <= list.size())
				{
					combo(std::stoi(n1), std::stoi(n2));
				}
			}
		}
		print();
	}
	return 0;
}