#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>
#include "Cas.h"
#include "TabulkaPretekarov.h"
#include <time.h>
#include <stdlib.h> 
#include <locale>
/*
Miroslav Potocar 5ZY02A
*/
void vypisMenu()
{
	std::cout << "1. Zorad podla priezviska a vypis \n";
	std::cout << "2. Zorad podla mena a vypis \n";
	std::cout << "3. Zorad podla startovacieho cisla a vypis \n";
	std::cout << "4. Zorad podla casu a vypis \n";
	std::cout << "5. Zorad oddelene zeny a muzov podla casu a vypis \n";
	std::cout << "6. Pridaj pretekara z klavesnice\n";
	std::cout << "0. Koniec\n";
}
unsigned int TabulkaPretekarov::pocetPretekarov = 1;
int main(int argc, char* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //testovanie memory leakov
	srand(time(NULL));
	TabulkaPretekarov tempTab = TabulkaPretekarov();
	if (argc == 2)
	{
		//"vystup.txt"
		tempTab.nacitaj(argv[1]);
	}
	vypisMenu();
	int vyber = -1;
	while (vyber)
	{
		std::string parameter;
		std::cout << "Zadajte prikaz!\n";
		std::cin >> parameter;
		bool test = true;
		for (int i = 0; i < parameter.length(); ++i)
		{
			std::locale loc;
			if (!std::isdigit(parameter[i], loc))
			{
				std::cout << "Nezadali ste spravny parameter!\n";
				test = false;
				break;
			}
		}
		if (test)
		{
			vyber = std::stoi(parameter);
		}
		else
		{
			continue;
		}
		if ((0 < vyber) && vyber < 6)
		{
			tempTab.usporiadanyVypisPodla((typVypisu)vyber);
		}
		else if (vyber == 6)
		{
			tempTab.vlozPretekara();
		}
		else if (vyber == 0)
			std::cout << "Dovidenia!\n";
		else
			std::cout << "Nespravny parameter!\n";
	}
	tempTab.vypisVysledkyDoSub();
	//_CrtDumpMemoryLeaks();
	return 0;
}