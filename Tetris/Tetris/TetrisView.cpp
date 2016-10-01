#include "stdafx.h"
#include "TetrisView.h"

namespace
{
	const glm::fvec2 FIRST_POSITION = { 100.f, SHAPE_SIZE.height * 1 };
}

CTetrisView::CTetrisView(SSize const & size)
	:m_sizePlayground(size)
{
	m_positionPlayground = glm::fvec2(100.f, 0.f);
	m_playground.resize(20);
	for (auto &cell : m_playground)
	{
		cell.resize(10);
	}
	for (size_t i = 0; i != m_playground.size(); ++i)
	{
		glm::fvec2 position(100.f, SHAPE_SIZE.height * (m_playground.size() - i - 1));
		for (size_t j = 0; j != m_playground[i].size(); ++j)
		{
			m_playground[i][j] = SCellView(position);
			position.x += SHAPE_SIZE.width;
		}
	}
}

void CTetrisView::Draw()
{
	this->DrawPlayground();
	m_shape->Draw();
	m_nextShape->Draw();

}

void CTetrisView::CreateShape(SHAPE_TYPE const & type)
{
	m_shape = !m_nextShape ? std::make_unique<CShape>(type) : std::move(m_nextShape);
	m_shape->SetPosition(FIRST_POSITION);
}

void CTetrisView::CreateNextShape(SHAPE_TYPE const & type)
{
	m_nextShape = std::make_unique<CShape>(type);
	m_nextShape->SetPosition({ 100.f + SHAPE_SIZE.width * 10 + 40.f, 200.f });
	m_shape->SetPosition(FIRST_POSITION);
}

void CTetrisView::LowerShape()
{
	auto position = m_shape->GetPosition();
	m_shape->SetPosition({ position.x, position.y + SHAPE_SIZE.height });
}

void CTetrisView::UpperShape()
{
	auto position = m_shape->GetPosition();
	m_shape->SetPosition({ position.x, position.y - SHAPE_SIZE.height });

}

void CTetrisView::AddShapeToPlayground()
{
	for (auto const &pos : m_shape->GetPositionsComponents())
	{
		bool flag = false;
		for (auto &row : m_playground)
		{
			for (auto &cell : row)
			{
				if (cell.position == pos)
				{
					flag = true;
					cell.color = m_shape->GetColor();
					break;
				}
			}
			if (flag)
			{
				break;
			}
		}
	}
	m_shape = std::move(m_nextShape);
}

std::vector<glm::fvec2> CTetrisView::GetPositionsComponentsShape() const
{
	return m_shape->GetPositionsComponents();
}

void CTetrisView::DrawPlayground() const
{
	glColor3f(BLUE.x, BLUE.y, BLUE.z);
	glRectf(m_positionPlayground.x - 20.f, m_positionPlayground.y, m_positionPlayground.x + m_sizePlayground.width + 20.f,
		m_positionPlayground.y + m_sizePlayground.height + 20.f);
	
	float border = SHAPE_SIZE.width / 10;
	for (auto const &row : m_playground)
	{
		for (auto const &cell : row)
		{
			glColor3f(0.f, 0.f, 0.f);
			glRectf(cell.position.x, cell.position.y, cell.position.x + SHAPE_SIZE.width,
				cell.position.y + SHAPE_SIZE.height);
			
			glColor3f(cell.color.x, cell.color.y, cell.color.z);
			glRectf(cell.position.x, cell.position.y, cell.position.x + SHAPE_SIZE.width - border,
				cell.position.y + SHAPE_SIZE.height - border);
		}
	}
}
