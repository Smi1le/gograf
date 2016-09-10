#include "stdafx.h"
#include "Ears.h"

void CEars::Setup(float firstRadius, float secondRadius)
{
	m_ears.push_back(CEllipse(firstRadius, secondRadius));
	m_ears.push_back(CEllipse(firstRadius, secondRadius));
}

void CEars::SetCenterColor(glm::fvec3 const &color)
{
	m_ears[0].SetCenterColor(color);
	m_ears[1].SetCenterColor(color);
}

void CEars::SetPetalColor(glm::fvec3 const &color)
{
	m_ears[0].SetPetalColor(color);
	m_ears[1].SetPetalColor(color);
}

void CEars::SetPositionFirstEar(glm::fvec2 const &position)
{
	m_ears[0].SetPosition(position);
}

void CEars::SetPositionSecondEar(glm::fvec2 const &position)
{
	m_ears[1].SetPosition(position);
}

void CEars::SetFirstRadius(float radius)
{
	m_ears[0].SetFirstRadius(radius);
	m_ears[1].SetFirstRadius(radius);
}

void CEars::SetSecondRadius(float radius)
{
	m_ears[0].SetSecondRadius(radius);
	m_ears[1].SetSecondRadius(radius);
}

void const CEars::Draw()
{
	m_ears[0].Draw();
	m_ears[1].Draw();
}