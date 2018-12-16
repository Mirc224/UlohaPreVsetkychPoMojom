#include "Cas.h"



Cas::Cas(int casVsekundach)
{
	int tempSekundy = 0;
	int tempMinuty = 0;
	int tempHodiny = 0;
	m_sekundy = 0;
	m_minuty = 59;
	m_hodiny = 1;
	tempSekundy = casVsekundach % 60;
	casVsekundach -= tempSekundy;
	tempMinuty = (casVsekundach/60) % 60;
	casVsekundach -= tempMinuty * 60;
	tempHodiny = (casVsekundach / 3600) % 24;
	m_sekundy += tempSekundy;
	if ((m_minuty + tempMinuty) / 60 != 0)
	{
		m_minuty = (m_minuty + tempMinuty) % 60;
		++m_hodiny;
	}

}


std::string Cas::toString()
{
	std::string casVoFormate=std::to_string(m_hodiny) + ":";
	if (m_minuty < 10)
		casVoFormate += "0";
	casVoFormate += std::to_string(m_minuty) + ":";
	if (m_sekundy < 10)
		casVoFormate += "0";
	casVoFormate += std::to_string(m_sekundy);
	return casVoFormate;
}

Cas::~Cas()
{
}
