#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include "Pretekar.h"
enum typVypisu { MENO = 1, PRIEZVISKO, PORADOVE_C, CAS, M_Z };
class TabulkaPretekarov
{
public:
	static unsigned int pocetPretekarov;
	TabulkaPretekarov();
	void vlozPretekara();
	void usporiadanyVypisPodla(typVypisu par);
	void uloz();
	void nacitaj(std::string fileName);
	void vypisVysledkyDoSub();
	~TabulkaPretekarov();
private:
	std::map<unsigned int, Pretekar*>* m_ucastnici;
};

