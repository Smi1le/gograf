#include "Rectangle.h"
#include <GL/glew.h>
#include <GL/gl.h>

CRectangle::CRectangle(SSize const &size, glm::fvec2 const &position)
	: m_size(size)
	, m_position(position)
{
	m_isMinSideWidth = m_size.width < m_size.height;
	m_minSide = m_isMinSideWidth ? m_size.width : m_size.height;
}

CRectangle::CRectangle(float x, float y, float width, float height)
	:CRectangle({ width, height }, {x, y})
{}

void CRectangle::Draw()
{
	glColor3f(0.f, 0.f, 1.f);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i <= int(m_minSide) * 2; ++i)
	{
		glm::fvec2 position;
		position = i % 2 == 0 ? (m_isMinSideWidth ? glm::fvec2(m_position.x + i / 2, m_position.y) : glm::fvec2(m_position.x, m_position.y + i / 2)) :
			(m_isMinSideWidth ? glm::fvec2(m_position.x + i / 2, m_position.y + m_size.height) : glm::fvec2(m_position.x + m_size.width, m_position.y + i / 2));
		glVertex2f(position.x, position.y);
	}
	glEnd();
}