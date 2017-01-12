#pragma once
#include "Body.h"

class CParallelepiped final :
	public CBody
{
public:
	CParallelepiped(double width, double height, double depth, double density);

	double GetWidth() const;
	double GetHeight() const;
	double getDepth() const;
	double GetVolume() const override;

	~CParallelepiped() = default;
protected:
	void AppendProperties(std::ostream &strm) const override;
private:
	double m_width;
	double m_height;
	double m_depth;
};

