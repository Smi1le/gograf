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
	glm::fvec3 GetColor() const;
	std::vector<glm::fvec2> GetPositionsComponents() const;
	void Draw() const;
	void TuneShape();
	void Moves();
	void ChangeSide();
private:
	
	void TuneFirstType();
	void TuneSecondType();
	void TuneThirdType();
	void TuneFourthType();
	void TuneFifthType();
	void TuneSixthType();
	void TuneSeventhType();
private:
	SHAPE_TYPE m_type;
	glm::fvec2 m_position;
	std::vector<CRectangle> m_components;
	bool m_isMoves;
	SIDE m_side;
};