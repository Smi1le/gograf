#include "stdafx.h"
#include "Legs.h"

void CLegs::Setup(float firstRadius, float secondRadius)
{
	m_legs.push_back(CEllipse(firstRadius, secondRadius));
	m_legs.push_back(CEllipse(firstRadius, secondRadius));
}

void CLegs::SetCenterColor(glm::fvec3 const &color)
{
	m_legs[0].SetCenterColor(color);
	m_legs[1].SetCenterColor(color);
}

void CLegs::SetPetalColor(glm::fvec3 const &color)
{
	m_legs[0].SetPetalColor(color);
	m_legs[0].SetPetalColor(color);
}

void CLegs::SetFirstRadius(float radius)
{
	SetFirstRadiusFirstLeg(radius);
	SetFirstRadiusSecondLeg(radius);
}

void CLegs::SetSecondRadius(float radius)
{
	SetSecondRadiusFirstLeg(radius);
	SetSecondRadiusSecondLeg(radius);
}

void CLegs::SetFirstRadiusFirstLeg(float radius)
{
	m_legs[0].SetFirstRadius(radius);
}

void CLegs::SetSecondRadiusFirstLeg(float radius)
{
	m_legs[0].SetSecondRadius(radius);
}

void CLegs::SetFirstRadiusSecondLeg(float radius)
{
	m_legs[1].SetFirstRadius(radius);
}

void CLegs::SetSecondRadiusSecondLeg(float radius)
{
	m_legs[1].SetSecondRadius(radius);
}

void const CLegs::Draw()
{
	m_legs[0].Draw();
	m_legs[1].Draw();
}

void CLegs::SetPositionFirstLeg(glm::fvec2 const &position)
{
	m_legs[0].SetPosition(position);
}

void CLegs::SetPositionSecondLeg(glm::fvec2 const &position)
{
	m_legs[1].SetPosition(position);
}