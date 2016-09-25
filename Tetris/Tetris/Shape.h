#pragma once
#include "Rectangle.h"




class CShape
{
public:
	CShape() = default;
	CShape(SHAPE_TYPE const &type);
	void SetType(SHAPE_TYPE const &type);
	void SetPosition(glm::fvec2 const &position);
	glm::fvec2 GetPosition() const;
	void Draw() const;
	void Create();
private:
	
	void CreateFirstType();
	void CreateSecondType();
	void CreateThirdType();
	void CreateFourthType();
	void CreateFifthType();
	void CreateSixthType();
	void CreateSeventhType();
private:
	SHAPE_TYPE m_type;
	glm::fvec2 m_position;
	std::vector<CRectangle> m_components;
};