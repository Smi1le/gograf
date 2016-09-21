#include "stdafx.h"
#include "Mouth.h"




void CMouth::Setup(int petalCount)
{
	m_petalCount = petalCount;
}

void CMouth::SetPosition(glm::fvec2 const & position)
{
	m_center = position;
}

void CMouth::SetSize(SSize const &size)
{
	m_size = size;
}

void CMouth::SetColor(glm::fvec3 const & color)
{
	m_color = color;
}

void CMouth::Draw()
{
	const float step = float(2 * M_PI) / float(m_petalCount * 20);
	glLineWidth(5.f);
	glColor3f(m_color.x, m_color.y, m_color.z);
	glBegin(GL_LINE_STRIP);
	for (float angle = 0; angle <= float(M_PI); angle += step)
	{
		float fixedAngle = (fabsf(angle - float(2 * M_PI)) < 1e-4f) ? 0 : angle;
		float x = m_size.width * cosf(fixedAngle);
		float y = m_size.height * sinf(fixedAngle);
		glVertex2f(x + m_center.x, y + m_center.y);
	}
	glEnd();
}