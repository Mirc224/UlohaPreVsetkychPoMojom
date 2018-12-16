#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include "TabulkaPretekarov.h"
#include <time.h>
#include <stdlib.h> 
#include <algorithm>
#include <vector>
#include <set>
#include <locale>
#include <sstream>
bool compare_by_string(const std::string& lhs, const std::string& rhs) {
	return lhs < rhs;
}
TabulkaPretekarov::TabulkaPretekarov() : m_ucastnici(new std::map<unsigned int, Pretekar*>())
{
}

void TabulkaPretekarov::vlozPretekara()
{
	std::string meno;
	std::string priezvisko;
	std::string parameter;
	char pohlavie;
	std::cin.get();
	std::cout << "Meno: ";
	std::getline(std::cin, meno);
	std::cout << "Priezvisko: ";
	std::getline(std::cin, priezvisko);
	std::cout << "Pohlavie(m/z): ";
	std::getline(std::cin, parameter);
	pohlavie = parameter[0];
	if (pohlavie != 'm' && pohlavie != 'z')
	{
		std::cout << "Zadali ste nespravny parameter!\n";
		return;
	}
	srand(time(NULL));
	int casVSekundach = rand() % 1956;
	m_ucastnici->insert(std::make_pair(TabulkaPretekarov::pocetPretekarov, new Pretekar(meno, priezvisko, pohlavie, TabulkaPretekarov::pocetPretekarov, casVSekundach)));
	++TabulkaPretekarov::pocetPretekarov;
}

void TabulkaPretekarov::usporiadanyVypisPodla(typVypisu par)
{
	std::vector<unsigned int> vektorPorCisel;
	std::set<std::string> pozadovanyParameter;
	std::set<int> tempIntov;
	std::set<int> tempZeny;
	switch (par)
	{
	case MENO:
		for (auto &pretekar : *m_ucastnici)
		{
			pozadovanyParameter.insert(pretekar.second->getMeno());
		}
		for (auto &p : pozadovanyParameter)
		{
			for (auto &pretekar : *m_ucastnici)
				if (p.compare(pretekar.second->getMeno()) == 0)
				{
					vektorPorCisel.push_back(pretekar.second->getPoradoveCislo());
				}
		}
		break;
	case PRIEZVISKO:
		for (auto &pretekar : *m_ucastnici)
		{
			pozadovanyParameter.insert(pretekar.second->getPriezvisko());
		}
		for (auto &p : pozadovanyParameter)
		{
			for (auto &pretekar : *m_ucastnici)
				if (p.compare(pretekar.second->getPriezvisko()) == 0)
				{
					vektorPorCisel.push_back(pretekar.second->getPoradoveCislo());
				}
		}
		break;
	case PORADOVE_C:
		for (auto &pretekar : *m_ucastnici)
		{
			tempIntov.insert(pretekar.second->getPoradoveCislo());
		}
		for (auto &p : tempIntov)
		{
			vektorPorCisel.push_back(p);
		}
		break;
	case CAS:
		for (auto &pretekar : *m_ucastnici)
		{
			tempIntov.insert(pretekar.second->getCas().getCasVSekundach());
		}
		for (auto &p : tempIntov)
		{
			for (auto &pretekar : *m_ucastnici)
				if (pretekar.second->getCas().getCasVSekundach() == p)
				{
					vektorPorCisel.push_back(pretekar.second->getPoradoveCislo());
				}
		}

		break;
	case M_Z:

		for (auto &pretekar : *m_ucastnici)
		{
			if (pretekar.second->getPohlavie() == 'm')
			{
				tempIntov.insert(pretekar.second->getCas().getCasVSekundach());
			}
			else
			{
				tempZeny.insert(pretekar.second->getCas().getCasVSekundach());
			}
		}
		for (auto &p : tempZeny)
		{
			for (auto &pretekar : *m_ucastnici)
				if (pretekar.second->getCas().getCasVSekundach() == p && pretekar.second->getPohlavie() == 'z')
				{
					vektorPorCisel.push_back(pretekar.second->getPoradoveCislo());
				}
		}
		for (auto &p : tempIntov)
		{
			for (auto &pretekar : *m_ucastnici)
				if (pretekar.second->getCas().getCasVSekundach() == p && pretekar.second->getPohlavie() == 'm')
				{
					vektorPorCisel.push_back(pretekar.second->getPoradoveCislo());
				}
		}

			break;
	default :
		std::cout << "Zadali ste nespravny typ!\n";
		break;
	}
	for (unsigned int &poradie : vektorPorCisel)
	{
		std::cout << m_ucastnici->at(poradie)->toString() << std::endl;
	}
}

void TabulkaPretekarov::uloz()
{
	std::ofstream outputFile("vystup.txt");
	for (auto &pretekar : *m_ucastnici)
	{
		outputFile << pretekar.second;
	}
	std::cout << "Ukladanie ukoncene!\n";
}

void TabulkaPretekarov::nacitaj(std::string fileName)
{
	std::ifstream inputFile(fileName);
	if (inputFile.peek() == std::ifstream::traits_type::eof())
	{
		std::cout << "Subor je prazdny!\n";
	}
	else
	{
		std::string parameter;
		while (std::getline(inputFile, parameter))
		{
			std::istringstream istring(parameter);
			std::string meno;
			std::string priezvisko;
			char pohlavie;
			istring >> priezvisko;
			istring >> meno;
			istring >> pohlavie;
			int casVSekundach = rand() % 1955;
			m_ucastnici->insert(std::make_pair(TabulkaPretekarov::pocetPretekarov, new Pretekar(meno, priezvisko, pohlavie, TabulkaPretekarov::pocetPretekarov, casVSekundach)));
			++TabulkaPretekarov::pocetPretekarov;
		}
	}
}

void TabulkaPretekarov::vypisVysledkyDoSub()
{
	std::ofstream outputFile("vysledky.txt");
	for (auto &pretekar : *m_ucastnici)
	{
		outputFile << pretekar.second->toString() << std::endl;
	}
	std::cout << "Vysledky ulozene!\n";
}


TabulkaPretekarov::~TabulkaPretekarov()
{
	for (auto &p : *m_ucastnici)
	{
		delete p.second;
	}
	delete m_ucastnici;
}
