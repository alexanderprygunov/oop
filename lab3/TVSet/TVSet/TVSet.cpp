// TVSet.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TVSet.h"

using namespace std;

CTVSet::CTVSet():m_selectedChannelNumber(ChannelRange::min), m_previousChannel(ChannelRange::min)
{
}

CTVSet::~CTVSet()
{
}

void CTVSet::TurnOn()
{
	m_isTurnedOn = true;
}

void CTVSet::TurnOff()
{
	m_isTurnedOn = false;
}

bool CTVSet::IsTurnedOn()const
{
	return m_isTurnedOn;
}

bool CTVSet::SelectChannel(int channelNumber)
{
	if (!IsTurnedOn())
	{
		return false;
	}

	if (channelNumber < ChannelRange::min || channelNumber > ChannelRange::max)
	{
		return false;
	}

	m_previousChannel = m_selectedChannelNumber;
	m_selectedChannelNumber = channelNumber;
	
	return true;
}

int CTVSet::GetSelectedChannelNumber()const
{
	if (!IsTurnedOn())
	{
		return 0;
	}

	return m_selectedChannelNumber;
}

bool CTVSet::SelectPreviousChannel()
{
	if (!IsTurnedOn())
	{
		return false;
	}

	swap(m_previousChannel, m_selectedChannelNumber);
	
	return true;
}