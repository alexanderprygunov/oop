#include "stdafx.h"
#include "Compound.h"

CCompound::CCompound()
	: CBody("Compound")
{
}

bool CCompound::AddChildBody(std::shared_ptr<CBody> const &element)
{
	bool isAdded = true;
	if (this == &(*element))
	{
		isAdded = false;
	}

	if (isAdded)
	{
		m_elements.push_back(element);
		SetDensity();
	}
	return isAdded;
}

double CCompound::GetMass() const
{
	auto Mass = [](double &a, std::shared_ptr<CBody> b)
	{
		return a + b->GetMass();

	};
	return std::accumulate(m_elements.begin(), m_elements.end(), 0.0, Mass);
}

double CCompound::GetVolume() const
{
	auto Volume = [](double &a, std::shared_ptr<CBody> b)
	{
		return a + b->GetVolume();

	};
	return std::accumulate(m_elements.begin(), m_elements.end(), 0.0, Volume);
	
}

size_t CCompound::GetCountOfElements() const
{
	return m_elements.size();
}

void CCompound::AppendProperties(std::ostream & strm) const
{
	strm << "compound body have " << std::to_string(GetCountOfElements()) << " elements\n";
	for (auto element : m_elements)
	{
		strm << "\t" << element->ToString();
	}
	strm << "end of compound body\n";
}

void CCompound::SetDensity()
{
	m_density = GetMass() / GetVolume();
}
