#pragma once
class CBody
{
public:
	CBody(const std::string &type);
	CBody(const std::string &type, double density);

	double GetDensity() const;
	virtual double GetVolume() const = 0;
	virtual double GetMass() const;
	std::string ToString() const;

	virtual ~CBody() = default;
protected:
	double m_density;
	virtual void AppendProperties(std::ostream &strm) const = 0;
private:
	std::string m_type;
};
