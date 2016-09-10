#include "stdafx.h"
#include "Arms.h"


void CArms::SetupArms(SSize const &sizeArms)
{
	m_arms.push_back(CEllipse(sizeArms.height, sizeArms.width));
	m_arms.push_back(CEllipse(sizeArms.height, sizeArms.width));
}

void CArms::SetPetalColor(glm::fvec3 const &color)
{
	m_arms[0].SetPetalColor(color);
	m_arms[1].SetPetalColor(color);
}

void CArms::SetCenterColor(glm::fvec3 const &color)
{
	m_arms[0].SetCenterColor(color);
	m_arms[1].SetCenterColor(color);
}

void CArms::SetPositionFirstArm(glm::fvec2 const &position)
{
	m_arms[0].SetPosition(position);
}

void CArms::SetPositionSecondArm(glm::fvec2 const &position)
{
	m_arms[1].SetPosition(position);
}


void CArms::Draw()
{
	m_arms[0].Draw();
	m_arms[1].Draw();
}