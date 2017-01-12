#pragma once
#include "stdafx.h"
#include "Body.h"

class CCompound final :
	public CBody
{
public:
	CCompound();
	bool AddChildBody(std::shared_ptr<CBody> const &element);
	double GetMass() const override;
	double GetVolume() const override;
	size_t GetCountOfElements() const;
	~CCompound() = default;
protected:
	void AppendProperties(std::ostream &strm) const override;
private:
	std::vector<std::shared_ptr<CBody>> m_elements;
	void SetDensity(); //не работает при вложенности
};

