#include "stdafx.h"
#include "SolidBody.h"


CSolidBody::CSolidBody(const std::string & type, double density)
    : CBody(type, density)
{
}

double CSolidBody::GetRadius() const
{
    return m_radius;
}

CSolidBody::~CSolidBody()
{
}