#include "stdafx.h"
#include "Cone.h"

CCone::CCone(double density, double radius, double height)
	: CBody("Cone", density)
{
	if (radius < 0 || height < 0)
	{
		throw std::invalid_argument("Radius or height should not be negative");
	}
	m_radius = radius;
	m_height = height;
}

double CCone::GetRadius() const
{
	return m_radius;
}

double CCone::GetHeight() const
{
	return m_height;
}

double CCone::GetVolume() const
{
	return pow(m_radius, 2) * M_PI * m_height / 3;
}

void CCone::AppendProperties(std::ostream &strm) const
{
	strm << "\tradius = " << GetRadius() << std::endl
		<< "\theight = " << GetHeight() << std::endl;
}

