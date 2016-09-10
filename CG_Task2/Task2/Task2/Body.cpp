#include "stdafx.h"
#include "Body.h"


void CBody::SetPosition(glm::fvec2 const &position)
{
	m_body.SetPosition(position);
}

void CBody::SetRadius(float radius)
{
	m_body.SetFirstRadius(radius);
	m_body.SetSecondRadius(radius);
}

void CBody::SetPetalColor(glm::fvec3 const &color)
{
	m_body.SetPetalColor(color);
}

void CBody::SetCenterColor(glm::fvec3 const &color)
{
	m_body.SetCenterColor(color);
}


void const CBody::Draw()
{
	m_body.Draw();
}
