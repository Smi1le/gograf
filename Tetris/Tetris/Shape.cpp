#include "stdafx.h"
#include "Shape.h"

CShape::CShape(SHAPE_TYPE const & type)
	:m_type(type)
{
	Create();
}

void CShape::SetType(SHAPE_TYPE const & type)
{
	m_type = type;
}

void CShape::SetPosition(glm::fvec2 const & position)
{
	m_position = position;
}

glm::fvec2 CShape::GetPosition() const
{
	return m_position;
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
	m_components.push_back(CRectangle({ m_position.x, m_position.y}, SHAPE_SIZE, FIRST_SHAPE_COLOR));
	m_components.push_back(CRectangle({ m_position.x + SHAPE_SIZE.width, m_position.y }, SHAPE_SIZE, FIRST_SHAPE_COLOR));
	m_components.push_back(CRectangle({ m_position.x + SHAPE_SIZE.width * 2, m_position.y }, SHAPE_SIZE, FIRST_SHAPE_COLOR));
	m_components.push_back(CRectangle({ m_position.x + SHAPE_SIZE.width * 3, m_position.y }, SHAPE_SIZE, FIRST_SHAPE_COLOR));
}

void CShape::CreateSecondType()
{
	m_components.push_back(CRectangle({ 100.f, 100.f }, SHAPE_SIZE, SECOND_SHAPE_COLOR));
	m_components.push_back(CRectangle({ 100.f, 150.f }, SHAPE_SIZE, SECOND_SHAPE_COLOR));
	m_components.push_back(CRectangle({ 150.f, 150.f }, SHAPE_SIZE, SECOND_SHAPE_COLOR));
	m_components.push_back(CRectangle({ 200.f, 150.f }, SHAPE_SIZE, SECOND_SHAPE_COLOR));

}

void CShape::CreateThirdType()
{
	m_components.push_back(CRectangle({ 100.f, 150.f }, SHAPE_SIZE, THIRD_SHAPE_COLOR));
	m_components.push_back(CRectangle({ 150.f, 150.f }, SHAPE_SIZE, THIRD_SHAPE_COLOR));
	m_components.push_back(CRectangle({ 200.f, 150.f }, SHAPE_SIZE, THIRD_SHAPE_COLOR));
	m_components.push_back(CRectangle({ 200.f, 100.f }, SHAPE_SIZE, THIRD_SHAPE_COLOR));
}

void CShape::CreateFourthType()
{
	m_components.push_back(CRectangle({ 100.f, 100.f }, SHAPE_SIZE, FOURTH_SHAPE_COLOR));
	m_components.push_back(CRectangle({ 150.f, 100.f }, SHAPE_SIZE, FOURTH_SHAPE_COLOR));
	m_components.push_back(CRectangle({ 150.f, 150.f }, SHAPE_SIZE, FOURTH_SHAPE_COLOR));
	m_components.push_back(CRectangle({ 100.f, 150.f }, SHAPE_SIZE, FOURTH_SHAPE_COLOR));
}

void CShape::CreateFifthType()
{
	m_components.push_back(CRectangle({ 100.f, 150.f }, SHAPE_SIZE, FIFTH_SHAPE_COLOR));
	m_components.push_back(CRectangle({ 150.f, 150.f }, SHAPE_SIZE, FIFTH_SHAPE_COLOR));
	m_components.push_back(CRectangle({ 150.f, 100.f }, SHAPE_SIZE, FIFTH_SHAPE_COLOR));
	m_components.push_back(CRectangle({ 200.f, 100.f }, SHAPE_SIZE, FIFTH_SHAPE_COLOR));
}

void CShape::CreateSixthType()
{
	m_components.push_back(CRectangle({ 100.f, 150.f }, SHAPE_SIZE, SIXTH_SHAPE_COLOR));
	m_components.push_back(CRectangle({ 150.f, 150.f }, SHAPE_SIZE, SIXTH_SHAPE_COLOR));
	m_components.push_back(CRectangle({ 150.f, 100.f }, SHAPE_SIZE, SIXTH_SHAPE_COLOR));
	m_components.push_back(CRectangle({ 200.f, 150.f }, SHAPE_SIZE, SIXTH_SHAPE_COLOR));
}

void CShape::CreateSeventhType()
{
	m_components.push_back(CRectangle({ 100.f, 100.f }, SHAPE_SIZE, SEVENTH_SHAPE_COLOR));
	m_components.push_back(CRectangle({ 150.f, 100.f }, SHAPE_SIZE, SEVENTH_SHAPE_COLOR));
	m_components.push_back(CRectangle({ 150.f, 150.f }, SHAPE_SIZE, SEVENTH_SHAPE_COLOR));
	m_components.push_back(CRectangle({ 200.f, 150.f }, SHAPE_SIZE, SEVENTH_SHAPE_COLOR));
}
