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

void add(int elem) 
{
	list.insert(list.end(), list[elem]);
}

void add_basics()
{
	list.insert(list.end(), basics[1]);
	list.insert(list.end(), basics[21]);
	list.insert(list.end(), basics[3]);
	list.insert(list.end(), basics[4]);
}

void del(int aux)
{
	list.erase(list.begin() + aux - 1);
}

void info(int elem)
{
	std::string url = "https://en.wikipedia.org/wiki/" + list[elem - 1];
	ShellExecuteA(nullptr, "open", url.c_str(), nullptr, nullptr, SW_SHOWNORMAL);}

void sort()
{
	std::sort(list.begin(), list.end());
}

//void clean()
//{
//	for (int i = 0; i < list.size(); i++)
//	{
//		for (int j = i + 1; j < list.size; j++)
//		{
//
//		}
//	}
//}

void help()
{

}

void combine(int elem1, int elem2)
{

}

void config()
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

void print()
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
	print();


	//---------------------------------
	//------ COUT de la interfaz ------
	//---------------------------------

	//while (true)
	//{
	//	std::cin >> func;
	//	std::cout << std::endl;

	//	if (func == "add %d") 
	//	{
	//		
	//	}
	//	
	//	else if (func == "add basics")
	//	{

	//	}
	//	
	//	else if (func == "del")
	//	{

	//	}

	//	/*else if (func == "info " + aux)
	//	{

	//	}*/
	//	
	//	else if (func == "sort")
	//	{

	//	}
	//	
	//	else if (func == "clean")
	//	{

	//	}
	//	
	//	else if (func == "help")
	//	{

	//	}
	//	
	//	/*else if (func == sum1 + " " + sum2)
	//	{
	//		
	//	}*/
	//}

	return 0;

}