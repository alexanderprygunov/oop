#include "stdafx.h"
#include "Controller.h"

using namespace std;
using namespace std::placeholders;

CController::CController(vector<shared_ptr<CBody>> &bodies, istream &input, ostream &output)
	: m_bodies(bodies)
	, m_input(input)
	, m_output(output)
	, m_actionMap({
		{ "Info", bind(&CController::Info, this) },
		{ "Sphere", bind(&CController::CreateSphere, this, _1) },
		{ "Parallelepiped", bind(&CController::CreateParallelepiped, this, _1) },
		{ "Cone", bind(&CController::CreateCone, this, _1) },
		{ "Cylinder", bind(&CController::CreateCylinder, this, _1) },
		{ "Compound", bind(&CController::CreateCompoundBody, this, _1) },
})
{
}

bool CController::HandleCommand()
{
	bool isHandeled = true;
	string commandLine;
	if (!getline(m_input, commandLine) || (commandLine == "..."))
	{
		isHandeled = false;
	}
	if (isHandeled)
	{
		istringstream strm(commandLine);
		string action;
		strm >> action;

		auto it = m_actionMap.find(action);
		if (it != m_actionMap.end())
		{
			isHandeled = it->second(strm);
		}
	}
	return isHandeled;
}

bool CController::Info()
{
	m_output << "available commands:\n"
		<< "1) Sphere <density> <radius>\n"
		<< "2) Parallelepiped <width> <height> <depth> <density>\n"
		<< "3) Cone <density> <radius> <height>\n"
		<< "4) Cylinder <density> <radius> <height>\n"
		<< "5) Compound - Begining of the input elements of compound body\n"
		<< "Any elements\n"
		<< "... - to finish entering elements of compound body or exit\n";
	return true;
}

bool CController::CreateSphere(istream &args)
{
	bool isAdded = true;
	double density;
	double radius;
	if (!(args >> density) || !(args >> radius))
	{
		m_output << "Invalid count of arguments\n"
			<< "Usage: Sphere <density> <radius>\n";
		isAdded = false;
	}

	if (isAdded)
	{
		try
		{
			shared_ptr<CBody> sphere = make_shared<CSphere>(density, radius);
			m_bodies.push_back(sphere);
		}
		catch (invalid_argument const &e)
		{
			m_output << e.what();
		}
	}
	return isAdded;
}

bool CController::CreateParallelepiped(istream &args)
{
	bool isAdded = true;
	double width;
	double height;
	double depth;
	double density;

	if (!(args >> width) || !(args >> height) || !(args >> depth) || !(args >> density))
	{
		m_output << "Invalid count of arguments\n"
			<< "Usage: Parallelepiped <width> <height> <depth> <density>\n";
		isAdded = false;
	}
	if (isAdded)
	{
		try
		{
			shared_ptr<CBody> parallelepiped = make_shared<CParallelepiped>(width, height, depth, density);
			m_bodies.push_back(parallelepiped);
		}
		catch (invalid_argument const &e)
		{
			m_output << e.what();
		}
	}
	
	return isAdded;
}

bool CController::CreateCone(istream &args)
{
	bool isAdded = true;;
	double density;
	double radius;
	double height;

	if (!(args >> density) || !(args >> radius) || !(args >> height))
	{
		m_output << "Invalid count of arguments\n"
			<< "Usage: Cone <density> <radius> <height>\n";
		isAdded = false;
	}
	if (isAdded)
	{
		try
		{
			shared_ptr<CBody> cone = make_shared<CCone>(density, radius, height);
			m_bodies.push_back(cone);
		}
		catch (invalid_argument const &e)
		{
			m_output << e.what();
		}
	}

	return isAdded;
}

bool CController::CreateCylinder(istream &args)
{
	bool isAdded = true;
	double density;
	double radius;
	double height;

	if (!(args >> density) || !(args >> radius) || !(args >> height))
	{
		m_output << "Invalid count of arguments\n"
			<< "Usage: Cylinder <density> <radius> <height>\n";
		isAdded = false;
	}
	if (isAdded)
	{
		try
		{
			shared_ptr<CBody> cylinder = make_shared<CCylinder>(density, radius, height);
			m_bodies.push_back(cylinder);
		}
		catch (invalid_argument const &e)
		{
			m_output << e.what();
		}
	}

	return isAdded;
}

bool CController::CreateCompoundBody(istream &args)
{
	bool isAdded = true;
	shared_ptr<CCompound> compound = make_shared<CCompound>();
	vector<shared_ptr<CBody>> elementsOfCompoundBody;
	CController compoundController(elementsOfCompoundBody, m_input, m_output);
	bool gettingCompound = true;
	while (gettingCompound)
	{
		m_output << "> ";
		gettingCompound = compoundController.HandleCommand();
	}

	for (auto element : elementsOfCompoundBody)
	{
		if (!compound->AddChildBody(element))
		{
			m_output << "Selfadditional expected\n";
		}
	}
	m_bodies.push_back(compound);
	return isAdded;
}

void CController::PrintAllBodies(vector<shared_ptr<CBody>> const &bodies, ostream &output)
{
	if (!bodies.empty())
	{
		for (auto &body : bodies)
		{
			output << body->ToString();
		}
	}
	else
	{
		output << "You have not entered figures\n";
	}
}

void CController::FindBodyWithMaxMass(vector<shared_ptr<CBody>> const &bodies)
{
	if (!bodies.empty())
	{
		auto IsMassLarger = [](shared_ptr<CBody> const &a, shared_ptr<CBody> const &b)
		{
			return a->GetMass() < b->GetMass();
		};
		cout << "Body with max mass is " << (*max_element(bodies.begin(), bodies.end(), IsMassLarger))->ToString();
	}
}

void CController::FindBodyWithSmallestWeight(vector<shared_ptr<CBody>> const &bodies)
{
	if (!bodies.empty())
	{
		static const double WATER_DENSITY = 1000;
		static const double GRAVITY_CONST = 9.8f;

		auto IsWeightLess = [](shared_ptr<CBody> const &a, shared_ptr<CBody> const &b)
		{
			return ((a->GetDensity() - WATER_DENSITY) * GRAVITY_CONST * a->GetVolume()) >
				((b->GetDensity() - WATER_DENSITY) * GRAVITY_CONST * b->GetVolume());
		};

		cout << "Body with smallest weight is " << (*min_element(bodies.begin(), bodies.end(), IsWeightLess))->ToString();
	}
}

