#include "CoordinateSystem.h"
#include "Rectangle.h"
#include <GL/glew.h>
#include <GL/gl.h>

void CCoordinateSystem::Init(SSize const &size)
{
	m_size = size;
	m_divisions.push_back(std::make_unique<CRectangle>(m_size.width / 2.f - 5.f, 0.f, 5.f, m_size.height));
	m_divisions.push_back(std::make_unique<CRectangle>(0.f, m_size.height / 2.f - 5.f, m_size.width, 5.f));
	glm::fvec2 pos = { 382.5f, 45 };
	glm::fvec2 rectSize = { 30.0f, 5.0f };
	for (size_t i = 0; i != 11; ++i)
	{
		m_divisions.push_back(std::make_unique<CRectangle>(pos.x, pos.y, rectSize.x, rectSize.y));
		pos.y += 50.f;
	}
	pos = { 45.f, 282.5f };
	for (size_t i = 0; i != 15; ++i)
	{
		m_divisions.push_back(std::make_unique<CRectangle>(pos.x, pos.y, rectSize.y, rectSize.x));
		pos.x += 50.f;
	}
	//this->Redraw();
}

void CCoordinateSystem::Redraw() const
{
	for (size_t i = 0; i != m_divisions.size(); ++i)
	{
		m_divisions[i]->Draw();
	}
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(m_size.width / 2 - 2.5f, -2.5f);
	glVertex2f(m_size.width / 2 + 17.5f, 20.f);
	glVertex2f(m_size.width / 2 - 22.5f, 20.f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(m_size.width + 2.5f, m_size.height / 2 - 2.5f);
	glVertex2f(m_size.width - 20.f, m_size.height / 2 + 17.5f);
	glVertex2f(m_size.width - 20.f, m_size.height / 2 - 22.5f);
	glEnd();
}