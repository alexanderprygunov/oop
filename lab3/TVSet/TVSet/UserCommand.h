#pragma once
#include "TVSet.h"

class CUserCommand
{
public:
	CUserCommand(CTVSet tvSet);
	~CUserCommand();

	bool TurnOn();
	bool TurnOff();
	bool SelectChannel(int channelNumber);
	void Info()const;
	bool SelectPreviousChannel();
	void RunCommand(std::string & commandString);
private:
	CTVSet m_tvSet;
};