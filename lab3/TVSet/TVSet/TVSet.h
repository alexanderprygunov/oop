#pragma once
#include "stdafx.h"

class CTVSet
{
public:
	CTVSet();
	~CTVSet();

	void TurnOn();
	void TurnOff();
	bool IsTurnedOn()const;

	bool SelectChannel(int channelNumber);
	bool SelectPreviousChannel();
	int GetSelectedChannelNumber()const;

private:
	enum ChannelRange
	{
		min = 1,
		max = 99
	};
	bool m_isTurnedOn = false;
	int m_selectedChannelNumber;
	int m_previousChannel;
};