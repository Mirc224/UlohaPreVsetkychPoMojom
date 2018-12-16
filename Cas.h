#pragma once
#include <string>
class Cas
{
public:
	Cas(int casVsekundach);
	int getHodiny() { return m_hodiny; }
	int getMinuty() { return m_minuty; }
	int getSekundy() { return m_sekundy;  }
	int getCasVSekundach() { return m_hodiny * 3600 + m_minuty * 60 + m_sekundy; }
	std::string toString();
	virtual ~Cas();
private:
	int m_hodiny;
	int m_minuty;
	int m_sekundy;
};

