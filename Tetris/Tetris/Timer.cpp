#include "stdafx.h"
#include "Timer.h"



void CTimer::SetDeltaTime(float time)
{
	m_time += time;
}


float CTimer::GetTime() const
{
	return m_time;
}

bool CTimer::CheckForExcess(float excess)
{
	if (!m_isStart)
	{
		m_isStart = m_time > 1.5f;
	}
	return m_isStart && m_time > excess;
}

void CTimer::SetToZero()
{
	m_time = 0.f;
}
