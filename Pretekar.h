#pragma once
#include <string>
#include "Cas.h"
class Pretekar
{
public:
	Pretekar(std::string meno, std::string priezvisko, char pohlavie, unsigned int poradoveC, int casVsek);
	std::string getMeno() { return m_meno; }
	void nacitaj(std::istream& is);
	void vypis(std::ostream& os);
	std::string getPriezvisko() { return m_priezvisko; }
	char getPohlavie() { return m_pohlavie;  }
	unsigned int getPoradoveCislo() { return m_startovacieC;  }
	Cas getCas() { return m_cas; }
	std::string toString() { return std::to_string(m_startovacieC) + " " + m_priezvisko + " " + m_meno + " " + m_pohlavie + " " + m_cas.toString(); }

	friend std::istream& operator >>(std::istream& is, Pretekar* b)
	{
		b->nacitaj(is); return is;
	}
	friend std::ostream& operator <<(std::ostream& os, Pretekar* b) //takyto zapis aby sa to dalo retazit
	{
		b->vypis(os); return os;
	}


	virtual ~Pretekar();

private:
	std::string m_priezvisko;
	std::string m_meno;
	char m_pohlavie;
	unsigned int m_startovacieC;
	Cas m_cas;
};

