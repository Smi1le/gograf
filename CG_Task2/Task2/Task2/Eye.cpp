#include "stdafx.h"
#include "Eye.h"

static const glm::fvec3 BLACK_COLOR = { 0.f, 0.f, 0.f };

void CEye::Setup(float firstRadius, float secondRadius)
{
	m_eye = CEllipse();
	m_pupil = CEllipse();
	m_eye.Setup(firstRadius, secondRadius);
	m_pupil.Setup(5.f, 5.f);
	m_pupil.SetColor(BLACK_COLOR);
}

void CEye::SetCenterColor(glm::fvec3 const &color)
{
	m_eye.SetCenterColor(color);
}

void CEye::SetPetalColor(glm::fvec3 const &color)
{
	m_eye.SetPetalColor(color);
}

void CEye::SetPosition(glm::fvec2 const &position)
{
	m_eye.SetPosition(position);
	m_pupil.SetPosition(position);
}

void CEye::SetPositionPupil(glm::fvec2 const & position)
{
	m_pupil.SetPosition(position);	
}

void const CEye::Draw()
{
	m_eye.Draw();
	m_pupil.Draw();
}

void CEye::SetSizePupil(SSize const &size)
{
	m_pupil.SetSize(size.width, size.height);
}

void CEye::SetColorPupil(glm::fvec3 const & color)
{
	m_pupil.SetColor(color);
}
