#include "stdafx.h"
#include "Parallelepiped.h"

CParallelepiped::CParallelepiped(double width, double height, double depth, double density)
    : CBody("Parallelepiped", density)
{
	if (width < 0 || height < 0 || depth < 0)
	{
		throw std::invalid_argument("Width, height or depth should not be negative");
	}
	m_width = width;
	m_height = height;
	m_depth = depth;
}

double CParallelepiped::GetWidth()const
{
    return m_width;
}

double CParallelepiped::GetHeight()const
{
    return m_height;
}

double CParallelepiped::getDepth()const
{
    return m_depth;
}

double CParallelepiped::GetVolume()const
{
    return m_width * m_height * m_depth;
}

void CParallelepiped::AppendProperties(std::ostream &strm)const
{
    strm << "\twidth = " << GetWidth() << std::endl
        << "\theight = " << GetHeight() << std::endl
        << "\tdepth = " << getDepth() << std::endl;
}

