#include "stdafx.h"
#include "Rectangle.h"

CRectangle::CRectangle(glm::fvec2 const & position, SSize const & size, glm::fvec3 const & color)
	: m_position(position)
	, m_size(size)
	, m_color(color)
{}

void CRectangle::SetPosition(glm::fvec2 const & position)
{
	m_position = position;
}

void CRectangle::SetSize(SSize const & size)
{
	m_size = size;
}

void CRectangle::SetColor(glm::fvec3 const & color)
{
	m_color = color;
}

glm::fvec2 CRectangle::GetPosition() const
{
	return m_position;
}

SSize CRectangle::GetSize() const
{
	return m_size;
}

void CRectangle::Draw() const
{
	glColor3f(0.f, 0.f, 0.f);
	glRectf(m_position.x, m_position.y, m_position.x + m_size.width, m_position.y + m_size.height);
	glColor3f(m_color.x, m_color.y, m_color.z);
	glRectf(m_position.x + 5.f, m_position.y + 5.f, m_position.x + m_size.width - 5.f, m_position.y + m_size.height -5.f);
}
