#include "stdafx.h"
#include "Shape.h"

CShape::CShape(SHAPE_TYPE const & type)
	:m_type(type)
{
	for (size_t i = 0; i != 4; ++i)
	{
		m_components.push_back(CRectangle());
	}
	TuneShape();
}

void CShape::SetType(SHAPE_TYPE const & type)
{
	m_type = type;
}

void CShape::SetPosition(glm::fvec2 const & position)
{
	m_position = position;
	TuneShape();
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

void CShape::TuneShape()
{
	

	switch (m_type)
	{
	case SHAPE_TYPE::first:
		TuneFirstType();
		break;
	case SHAPE_TYPE::second:
		TuneSecondType();
		break;
	case SHAPE_TYPE::third:
		TuneThirdType();
		break;
	case SHAPE_TYPE::fourth:
		TuneFourthType();
		break;
	case SHAPE_TYPE::fifth:
		TuneFifthType();
		break;
	case SHAPE_TYPE::sixth:
		TuneSixthType();
		break;
	case SHAPE_TYPE::seventh:
		TuneSeventhType();
		break;
	}
}

void CShape::Moves()
{
	m_isMoves = true;
}

void CShape::ChangeSide()
{
	switch (m_side)
	{
	case first:
		m_side = second;
		break;
	case second:
		m_side = third;
		break;
	case third:
		m_side = fourth;
		break;
	case fourth:
		m_side = first;
		break;
	}
	TuneShape();
}
	
void CShape::TuneFirstType()
{
	if (m_side == first || m_side == third) {
		m_components[0].Tune({ m_position.x, m_position.y }, SHAPE_SIZE, FIRST_SHAPE_COLOR);
		m_components[1].Tune({ m_position.x + SHAPE_SIZE.width, m_position.y }, SHAPE_SIZE, FIRST_SHAPE_COLOR);
		m_components[2].Tune({ m_position.x + SHAPE_SIZE.width * 2, m_position.y }, SHAPE_SIZE, FIRST_SHAPE_COLOR);
		m_components[3].Tune({ m_position.x + SHAPE_SIZE.width * 3, m_position.y }, SHAPE_SIZE, FIRST_SHAPE_COLOR);
	}
	else 
	{
		m_components[0].Tune({ m_position.x, m_position.y }, SHAPE_SIZE, FIRST_SHAPE_COLOR);
		m_components[1].Tune({ m_position.x, m_position.y + SHAPE_SIZE.height }, SHAPE_SIZE, FIRST_SHAPE_COLOR);
		m_components[2].Tune({ m_position.x, m_position.y + SHAPE_SIZE.height * 2 }, SHAPE_SIZE, FIRST_SHAPE_COLOR);
		m_components[3].Tune({ m_position.x, m_position.y + SHAPE_SIZE.height * 3 }, SHAPE_SIZE, FIRST_SHAPE_COLOR);
	}
	
}

void CShape::TuneSecondType()
{
	switch(m_side)
	{
	case first:
		m_components[0].Tune({ m_position.x, m_position.y }, SHAPE_SIZE, SECOND_SHAPE_COLOR);
		m_components[1].Tune({ m_position.x, m_position.y + SHAPE_SIZE.height }, SHAPE_SIZE, SECOND_SHAPE_COLOR);
		m_components[2].Tune({ m_position.x + SHAPE_SIZE.width, m_position.y + SHAPE_SIZE.height }, SHAPE_SIZE, SECOND_SHAPE_COLOR);
		m_components[3].Tune({ m_position.x + SHAPE_SIZE.width * 2, m_position.y + SHAPE_SIZE.height }, SHAPE_SIZE, SECOND_SHAPE_COLOR);
		break;
	case second:
		m_components[0].Tune({ m_position.x + SHAPE_SIZE.width, m_position.y }, SHAPE_SIZE, SECOND_SHAPE_COLOR);
		m_components[1].Tune({ m_position.x , m_position.y }, SHAPE_SIZE, SECOND_SHAPE_COLOR);
		m_components[2].Tune({ m_position.x , m_position.y + SHAPE_SIZE.height }, SHAPE_SIZE, SECOND_SHAPE_COLOR);
		m_components[3].Tune({ m_position.x , m_position.y + SHAPE_SIZE.height * 2}, SHAPE_SIZE, SECOND_SHAPE_COLOR);
		break;
	case third:
		m_components[0].Tune({ m_position.x, m_position.y }, SHAPE_SIZE, SECOND_SHAPE_COLOR);
		m_components[1].Tune({ m_position.x + SHAPE_SIZE.width , m_position.y }, SHAPE_SIZE, SECOND_SHAPE_COLOR);
		m_components[2].Tune({ m_position.x + SHAPE_SIZE.width * 2, m_position.y }, SHAPE_SIZE, SECOND_SHAPE_COLOR);
		m_components[3].Tune({ m_position.x + SHAPE_SIZE.width * 2, m_position.y + SHAPE_SIZE.height  }, SHAPE_SIZE, SECOND_SHAPE_COLOR);
		break;
	case fourth:
		m_components[0].Tune({ m_position.x + SHAPE_SIZE.width, m_position.y }, SHAPE_SIZE, SECOND_SHAPE_COLOR);
		m_components[1].Tune({ m_position.x + SHAPE_SIZE.width , m_position.y + SHAPE_SIZE.height}, SHAPE_SIZE, SECOND_SHAPE_COLOR);
		m_components[2].Tune({ m_position.x + SHAPE_SIZE.width , m_position.y + SHAPE_SIZE.height * 2}, SHAPE_SIZE, SECOND_SHAPE_COLOR);
		m_components[3].Tune({ m_position.x , m_position.y + SHAPE_SIZE.height * 2}, SHAPE_SIZE, SECOND_SHAPE_COLOR);
		break;
	}

}

void CShape::TuneThirdType()
{
	switch (m_side)
	{
	case first:
		m_components[0].Tune({ m_position.x, m_position.y + SHAPE_SIZE.height }, SHAPE_SIZE, THIRD_SHAPE_COLOR);
		m_components[1].Tune({ m_position.x + SHAPE_SIZE.width, m_position.y + SHAPE_SIZE.height }, SHAPE_SIZE, THIRD_SHAPE_COLOR);
		m_components[2].Tune({ m_position.x + SHAPE_SIZE.width * 2, m_position.y + SHAPE_SIZE.height }, SHAPE_SIZE, THIRD_SHAPE_COLOR);
		m_components[3].Tune({ m_position.x + SHAPE_SIZE.width * 2, m_position.y }, SHAPE_SIZE, THIRD_SHAPE_COLOR);
		break;
	case second:
		m_components[0].Tune({ m_position.x, m_position.y }, SHAPE_SIZE, THIRD_SHAPE_COLOR);
		m_components[1].Tune({ m_position.x , m_position.y + SHAPE_SIZE.height }, SHAPE_SIZE, THIRD_SHAPE_COLOR);
		m_components[2].Tune({ m_position.x , m_position.y + SHAPE_SIZE.height * 2}, SHAPE_SIZE, THIRD_SHAPE_COLOR);
		m_components[3].Tune({ m_position.x + SHAPE_SIZE.width, m_position.y + SHAPE_SIZE.height * 2 }, SHAPE_SIZE, THIRD_SHAPE_COLOR);
		break;
	case third:
		m_components[0].Tune({ m_position.x, m_position.y + SHAPE_SIZE.height }, SHAPE_SIZE, THIRD_SHAPE_COLOR);
		m_components[1].Tune({ m_position.x, m_position.y }, SHAPE_SIZE, THIRD_SHAPE_COLOR);
		m_components[2].Tune({ m_position.x + SHAPE_SIZE.width , m_position.y }, SHAPE_SIZE, THIRD_SHAPE_COLOR);
		m_components[3].Tune({ m_position.x + SHAPE_SIZE.width * 2, m_position.y }, SHAPE_SIZE, THIRD_SHAPE_COLOR);
		break;
	case fourth:
		m_components[0].Tune({ m_position.x, m_position.y }, SHAPE_SIZE, THIRD_SHAPE_COLOR);
		m_components[1].Tune({ m_position.x + SHAPE_SIZE.width, m_position.y }, SHAPE_SIZE, THIRD_SHAPE_COLOR);
		m_components[2].Tune({ m_position.x + SHAPE_SIZE.width , m_position.y + SHAPE_SIZE.height }, SHAPE_SIZE, THIRD_SHAPE_COLOR);
		m_components[3].Tune({ m_position.x + SHAPE_SIZE.width , m_position.y + SHAPE_SIZE.height * 2}, SHAPE_SIZE, THIRD_SHAPE_COLOR);
		break;
	}
}

void CShape::TuneFourthType()
{
	m_components[0].Tune({ m_position.x , m_position.y }, SHAPE_SIZE, FOURTH_SHAPE_COLOR);
	m_components[1].Tune({ m_position.x + SHAPE_SIZE.width, m_position.y }, SHAPE_SIZE, FOURTH_SHAPE_COLOR);
	m_components[2].Tune({ m_position.x + SHAPE_SIZE.width, m_position.y + SHAPE_SIZE.height }, SHAPE_SIZE, FOURTH_SHAPE_COLOR);
	m_components[3].Tune({ m_position.x , m_position.y + SHAPE_SIZE.height }, SHAPE_SIZE, FOURTH_SHAPE_COLOR);
}

void CShape::TuneFifthType()
{
	if (m_side == first || m_side == third)
	{
		m_components[0].Tune({ m_position.x , m_position.y + SHAPE_SIZE.height }, SHAPE_SIZE, FIFTH_SHAPE_COLOR);
		m_components[1].Tune({ m_position.x + SHAPE_SIZE.width, m_position.y + SHAPE_SIZE.height }, SHAPE_SIZE, FIFTH_SHAPE_COLOR);
		m_components[2].Tune({ m_position.x + SHAPE_SIZE.width, m_position.y }, SHAPE_SIZE, FIFTH_SHAPE_COLOR);
		m_components[3].Tune({ m_position.x + SHAPE_SIZE.width * 2, m_position.y }, SHAPE_SIZE, FIFTH_SHAPE_COLOR);
	}
	else
	{
		m_components[0].Tune({ m_position.x , m_position.y }, SHAPE_SIZE, FIFTH_SHAPE_COLOR);
		m_components[1].Tune({ m_position.x , m_position.y + SHAPE_SIZE.height }, SHAPE_SIZE, FIFTH_SHAPE_COLOR);
		m_components[2].Tune({ m_position.x + SHAPE_SIZE.width, m_position.y + SHAPE_SIZE.height}, SHAPE_SIZE, FIFTH_SHAPE_COLOR);
		m_components[3].Tune({ m_position.x + SHAPE_SIZE.width , m_position.y + SHAPE_SIZE.height * 2}, SHAPE_SIZE, FIFTH_SHAPE_COLOR);
	}
}

void CShape::TuneSixthType()
{
	switch(m_side)
	{
	case first:
		m_components[0].Tune({ m_position.x , m_position.y + SHAPE_SIZE.height }, SHAPE_SIZE, SIXTH_SHAPE_COLOR);
		m_components[1].Tune({ m_position.x + SHAPE_SIZE.width, m_position.y + SHAPE_SIZE.height }, SHAPE_SIZE, SIXTH_SHAPE_COLOR);
		m_components[2].Tune({ m_position.x + SHAPE_SIZE.width, m_position.y }, SHAPE_SIZE, SIXTH_SHAPE_COLOR);
		m_components[3].Tune({ m_position.x + SHAPE_SIZE.width * 2, m_position.y + SHAPE_SIZE.height }, SHAPE_SIZE, SIXTH_SHAPE_COLOR);
		break;
	case second:
		m_components[0].Tune({ m_position.x , m_position.y }, SHAPE_SIZE, SIXTH_SHAPE_COLOR);
		m_components[1].Tune({ m_position.x , m_position.y + SHAPE_SIZE.height }, SHAPE_SIZE, SIXTH_SHAPE_COLOR);
		m_components[2].Tune({ m_position.x + SHAPE_SIZE.width, m_position.y + SHAPE_SIZE.height}, SHAPE_SIZE, SIXTH_SHAPE_COLOR);
		m_components[3].Tune({ m_position.x , m_position.y + SHAPE_SIZE.height * 2 }, SHAPE_SIZE, SIXTH_SHAPE_COLOR);
		break;
	case third:
		m_components[0].Tune({ m_position.x , m_position.y }, SHAPE_SIZE, SIXTH_SHAPE_COLOR);
		m_components[1].Tune({ m_position.x + SHAPE_SIZE.width, m_position.y }, SHAPE_SIZE, SIXTH_SHAPE_COLOR);
		m_components[2].Tune({ m_position.x + SHAPE_SIZE.width, m_position.y + SHAPE_SIZE.height}, SHAPE_SIZE, SIXTH_SHAPE_COLOR);
		m_components[3].Tune({ m_position.x + SHAPE_SIZE.width * 2, m_position.y }, SHAPE_SIZE, SIXTH_SHAPE_COLOR);
		break;
	case fourth:
		m_components[0].Tune({ m_position.x + SHAPE_SIZE.width, m_position.y }, SHAPE_SIZE, SIXTH_SHAPE_COLOR);
		m_components[1].Tune({ m_position.x + SHAPE_SIZE.width, m_position.y + SHAPE_SIZE.height }, SHAPE_SIZE, SIXTH_SHAPE_COLOR);
		m_components[2].Tune({ m_position.x , m_position.y + SHAPE_SIZE.height}, SHAPE_SIZE, SIXTH_SHAPE_COLOR);
		m_components[3].Tune({ m_position.x + SHAPE_SIZE.width, m_position.y + SHAPE_SIZE.height * 2}, SHAPE_SIZE, SIXTH_SHAPE_COLOR);
		break;
	}	
}

void CShape::TuneSeventhType()
{
	if (m_side == first || m_side == third)
	{
		m_components[0].Tune({ m_position.x , m_position.y }, SHAPE_SIZE, SEVENTH_SHAPE_COLOR);
		m_components[1].Tune({ m_position.x + SHAPE_SIZE.width, m_position.y }, SHAPE_SIZE, SEVENTH_SHAPE_COLOR);
		m_components[2].Tune({ m_position.x + SHAPE_SIZE.width, m_position.y + SHAPE_SIZE.height }, SHAPE_SIZE, SEVENTH_SHAPE_COLOR);
		m_components[3].Tune({ m_position.x + SHAPE_SIZE.width * 2, m_position.y + SHAPE_SIZE.height }, SHAPE_SIZE, SEVENTH_SHAPE_COLOR);
	}
	else
	{
		m_components[0].Tune({ m_position.x + SHAPE_SIZE.width, m_position.y }, SHAPE_SIZE, SEVENTH_SHAPE_COLOR);
		m_components[1].Tune({ m_position.x + SHAPE_SIZE.width, m_position.y + SHAPE_SIZE.height }, SHAPE_SIZE, SEVENTH_SHAPE_COLOR);
		m_components[2].Tune({ m_position.x, m_position.y + SHAPE_SIZE.height }, SHAPE_SIZE, SEVENTH_SHAPE_COLOR);
		m_components[3].Tune({ m_position.x, m_position.y + SHAPE_SIZE.height * 2}, SHAPE_SIZE, SEVENTH_SHAPE_COLOR);
	}
}
