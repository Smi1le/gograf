#include "stdafx.h"
#include "Ellipse.h"


void CEllipse::Setup(float firstRadius, float secondRadius, int x, int y)
{
	SetSize(firstRadius, secondRadius);
	m_position = { x, y };
	m_petalCount = 20;
}

void CEllipse::SetSize(float firstRadius, float secondRadius)
{
	m_size = { firstRadius, secondRadius };
}

void CEllipse::SetColor(glm::fvec3 const &color)
{
	SetCenterColor(color);
	SetPetalColor(color);
}

void CEllipse::SetCenterColor(glm::fvec3 const &color)
{
	m_centerColor = color;
}

void CEllipse::SetPetalColor(glm::fvec3 const &color)
{
	m_petalColor = color;
}

void CEllipse::SetPosition(glm::fvec2 const &position)
{
	m_position = position;
}

void const CEllipse::Draw() 
{
	const float step = float(2 * M_PI) / float(m_petalCount * 20);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(m_centerColor.x, m_centerColor.y, m_centerColor.z);
	glVertex2f(m_position.x, m_position.y);

	glColor3f(m_petalColor.x, m_petalColor.y, m_petalColor.z);
	for (float angle = 0; angle <= float(2 * M_PI) + 0.5f * step; angle += step)
	{
		float fixedAngle = (fabsf(angle - float(2 * M_PI)) < 1e-4f) ? 0 : angle;
		float x = m_size.width * cosf(fixedAngle);
		float y = m_size.height * sinf(fixedAngle);
		glVertex2f(x + m_position.x, y + m_position.y);
	}
	glEnd();
}