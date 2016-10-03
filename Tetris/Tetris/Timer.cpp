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
	return m_time > excess;
}

void CTimer::SetToZero()
{
	m_time = 0.f;
}
