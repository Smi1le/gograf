#include "stdafx.h"
#include "Shape.h"

CShape::CShape(SHAPE_TYPE const & type)
	:m_type(type)
{
	for (size_t i = 0; i != 4; ++i)
	{
		m_components.push_back(CRectangle());
	}
	Create();
}

void CShape::SetType(SHAPE_TYPE const & type)
{
	m_type = type;
}

void CShape::SetPosition(glm::fvec2 const & position)
{
	m_position = position;
	Create();
}

glm::fvec2 CShape::GetPosition() const
{
	return m_position;
}

glm::fvec3 CShape::GetColor() const
{
	return m_components[0].GetColor();
}

std::vector<glm::fvec2> CShape::GetPositionsComponents() const
{
	std::vector<glm::fvec2> positions;
	for (auto const&rect : m_components)
	{
		positions.push_back(rect.GetPosition());
	}
	return positions;
}

void CShape::Draw() const
{
	for (auto const &component : m_components)
	{
		component.Draw();
	}
}

void CShape::Create()
{
	

	switch (m_type)
	{
	case SHAPE_TYPE::first:
		CreateFirstType();
		break;
	case SHAPE_TYPE::second:
		CreateSecondType();
		break;
	case SHAPE_TYPE::third:
		CreateThirdType();
		break;
	case SHAPE_TYPE::fourth:
		CreateFourthType();
		break;
	case SHAPE_TYPE::fifth:
		CreateFifthType();
		break;
	case SHAPE_TYPE::sixth:
		CreateSixthType();
		break;
	case SHAPE_TYPE::seventh:
		CreateSeventhType();
		break;
	}
}

void CShape::CreateFirstType()
{
	m_components[0].Tune({ m_position.x, m_position.y}, SHAPE_SIZE, FIRST_SHAPE_COLOR);
	m_components[1].Tune({ m_position.x + SHAPE_SIZE.width, m_position.y }, SHAPE_SIZE, FIRST_SHAPE_COLOR);
	m_components[2].Tune({ m_position.x + SHAPE_SIZE.width * 2, m_position.y }, SHAPE_SIZE, FIRST_SHAPE_COLOR);
	m_components[3].Tune({ m_position.x + SHAPE_SIZE.width * 3, m_position.y }, SHAPE_SIZE, FIRST_SHAPE_COLOR);
}

void CShape::CreateSecondType()
{
	m_components[0].Tune({ m_position.x, m_position.y }, SHAPE_SIZE, SECOND_SHAPE_COLOR);
	m_components[1].Tune({ m_position.x, m_position.y + SHAPE_SIZE.height}, SHAPE_SIZE, SECOND_SHAPE_COLOR);
	m_components[2].Tune({ m_position.x + SHAPE_SIZE.width, m_position.y + SHAPE_SIZE.height}, SHAPE_SIZE, SECOND_SHAPE_COLOR);
	m_components[3].Tune({ m_position.x + SHAPE_SIZE.width * 2, m_position.y + SHAPE_SIZE.height}, SHAPE_SIZE, SECOND_SHAPE_COLOR);

}

void CShape::CreateThirdType()
{
	m_components[0].Tune({ m_position.x, m_position.y + SHAPE_SIZE.height}, SHAPE_SIZE, THIRD_SHAPE_COLOR);
	m_components[1].Tune({ m_position.x + SHAPE_SIZE.width, m_position.y + SHAPE_SIZE.height}, SHAPE_SIZE, THIRD_SHAPE_COLOR);
	m_components[2].Tune({ m_position.x + SHAPE_SIZE.width * 2, m_position.y + SHAPE_SIZE.height}, SHAPE_SIZE, THIRD_SHAPE_COLOR);
	m_components[3].Tune({ m_position.x + SHAPE_SIZE.width * 2, m_position.y + SHAPE_SIZE.height }, SHAPE_SIZE, THIRD_SHAPE_COLOR);
}

void CShape::CreateFourthType()
{
	m_components[0].Tune({ m_position.x , m_position.y}, SHAPE_SIZE, FOURTH_SHAPE_COLOR);
	m_components[1].Tune({ m_position.x + SHAPE_SIZE.width, m_position.y}, SHAPE_SIZE, FOURTH_SHAPE_COLOR);
	m_components[2].Tune({ m_position.x + SHAPE_SIZE.width, m_position.y + SHAPE_SIZE.height}, SHAPE_SIZE, FOURTH_SHAPE_COLOR);
	m_components[3].Tune({ m_position.x , m_position.y + SHAPE_SIZE.height }, SHAPE_SIZE, FOURTH_SHAPE_COLOR);
}

void CShape::CreateFifthType()
{
	m_components[0].Tune({ m_position.x , m_position.y + SHAPE_SIZE.height }, SHAPE_SIZE, FIFTH_SHAPE_COLOR);
	m_components[1].Tune({ m_position.x + SHAPE_SIZE.width, m_position.y + SHAPE_SIZE.height }, SHAPE_SIZE, FIFTH_SHAPE_COLOR);
	m_components[2].Tune({ m_position.x + SHAPE_SIZE.width, m_position.y }, SHAPE_SIZE, FIFTH_SHAPE_COLOR);
	m_components[3].Tune({ m_position.x + SHAPE_SIZE.width * 2, m_position.y}, SHAPE_SIZE, FIFTH_SHAPE_COLOR);
}

void CShape::CreateSixthType()
{
	m_components[0].Tune({ m_position.x , m_position.y + SHAPE_SIZE.height }, SHAPE_SIZE, SIXTH_SHAPE_COLOR);
	m_components[1].Tune({ m_position.x + SHAPE_SIZE.width, m_position.y + SHAPE_SIZE.height }, SHAPE_SIZE, SIXTH_SHAPE_COLOR);
	m_components[2].Tune({ m_position.x + SHAPE_SIZE.width, m_position.y }, SHAPE_SIZE, SIXTH_SHAPE_COLOR);
	m_components[3].Tune({ m_position.x + SHAPE_SIZE.width * 2, m_position.y + SHAPE_SIZE.height }, SHAPE_SIZE, SIXTH_SHAPE_COLOR);
}

void CShape::CreateSeventhType()
{
	m_components[0].Tune({ m_position.x , m_position.y }, SHAPE_SIZE, SEVENTH_SHAPE_COLOR);
	m_components[1].Tune({ m_position.x + SHAPE_SIZE.width, m_position.y }, SHAPE_SIZE, SEVENTH_SHAPE_COLOR);
	m_components[2].Tune({ m_position.x + SHAPE_SIZE.width, m_position.y + SHAPE_SIZE.height}, SHAPE_SIZE, SEVENTH_SHAPE_COLOR);
	m_components[3].Tune({ m_position.x + SHAPE_SIZE.width * 2, m_position.y + SHAPE_SIZE.height}, SHAPE_SIZE, SEVENTH_SHAPE_COLOR);
}
