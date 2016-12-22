#include "stdafx.h"
#include "UserCommand.h"

using namespace std;

CUserCommand::CUserCommand(CTVSet tvSet):m_tvSet(tvSet)
{
}

CUserCommand::~CUserCommand()
{
}

bool CUserCommand::TurnOn()
{
	m_tvSet.TurnOn();
	return true;
}

bool CUserCommand::TurnOff()
{
	m_tvSet.TurnOff();
	return true;
}

void CUserCommand::Info()const
{
	cout << "TVSet is " <<((m_tvSet.IsTurnedOn()) ? "turned on" : "turned off") << endl;
	cout << "Channel number: " << m_tvSet.GetSelectedChannelNumber() << endl;
}

bool CUserCommand::SelectChannel(int channelNumber)
{
	if (!m_tvSet.SelectChannel(channelNumber))
	{
		cout << "Invalid channel number." << endl;
	}
	
	return true;
}

bool CUserCommand::SelectPreviousChannel()
{
	if (!m_tvSet.SelectPreviousChannel())
	{
		cout << "Cant switch to previous channel" << endl;
	}
	return true;
}

void CUserCommand::RunCommand(string & commandString)
{
	boost::to_lower(commandString);
	vector<string> command;
	boost::split(command, commandString, boost::is_any_of(" "));

	if (command[0] == "turnon")
	{
		TurnOn();
	}
	else if (command[0] == "turnoff")
	{
		TurnOff();
	}
	else if (command[0] == "info")
	{
		Info();
	}
	else if (command[0] == "selectchannel" && command.size() == 2)
	{
		SelectChannel(stoi(command[1]));
	}
	else if (command[0] == "selectpreviouschannel")
	{
		SelectPreviousChannel();
	}
	else
	{
		cout << "Invalid command." << endl;
	}
}