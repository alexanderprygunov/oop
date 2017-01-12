#include "stdafx.h"
#include "Body.h"

CBody::CBody(const std::string &type)
	: m_density(0)
	, m_type(type)
{
}

CBody::CBody(const std::string &type, double density)
	: m_type(type)
{
	if (density < 0)
	{
		throw std::invalid_argument("Density should not be negative");
	}
	m_density = density;
}

double CBody::GetDensity()const
{
	return m_density;
}

double CBody::GetMass()const
{
	return GetVolume() * GetDensity();
}

std::string CBody::ToString()const
{
	std::ostringstream strm;
	strm << m_type << ":" << std::endl << std::setprecision(10)
		<< "\tdensity = " << GetDensity() << std::endl
		<< "\tvolume = " << GetVolume() << std::endl
		<< "\tmass = " << GetMass() << std::endl;
	AppendProperties(strm);
	return strm.str();
}
