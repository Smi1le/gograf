#pragma once
#include "Shape.h"


class CTetrisView
{
public:
	CTetrisView(SSize const &size);
	void Draw();
	void CreateShape(SHAPE_TYPE const &type);
	void CreateNextShape(SHAPE_TYPE const &type);
	void LowerShape();
	void UpperShape();
	void AddShapeToPlayground();
	std::vector<glm::fvec2> GetPositionsComponentsShape()const;
private:
	void DrawPlayground() const;


private:
	SSize m_sizePlayground;
	glm::fvec2 m_positionPlayground;
	std::unique_ptr<CShape> m_shape;
	std::unique_ptr<CShape> m_nextShape;
	SHAPE_TYPE m_typeNextShape;
	std::vector<std::vector<SCellView>> m_playground;
};