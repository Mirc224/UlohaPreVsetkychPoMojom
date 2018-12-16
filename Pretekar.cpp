#include "Pretekar.h"


Pretekar::Pretekar(std::string meno, std::string priezvisko, char pohlavie, unsigned int poradoveC, int casVsek): m_meno(meno), m_priezvisko(priezvisko), m_pohlavie(pohlavie), m_startovacieC(poradoveC),m_cas(casVsek)
{
}

void Pretekar::nacitaj(std::istream & is)
{
	is >> m_priezvisko >> m_pohlavie >> m_pohlavie;
}

void Pretekar::vypis(std::ostream & os)
{
	os << m_priezvisko << " " << m_meno << " " << m_pohlavie << std::endl;;
}

Pretekar::~Pretekar()
{
}
