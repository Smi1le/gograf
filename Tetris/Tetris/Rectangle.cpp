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

glm::fvec3 CRectangle::GetColor() const
{
	return m_color;
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
	float border = m_size.width / 10;
	glRectf(m_position.x + border, m_position.y + border, 
		m_position.x + m_size.width - border, m_position.y + m_size.height - border);
}

void CRectangle::Tune(glm::fvec2 const & position, SSize const & size, glm::fvec3 const & color)
{
	SetColor(color);
	SetPosition(position);
	SetSize(size);
}
