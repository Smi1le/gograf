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
	void MoveShapeToLeft();
	void MoveShapeToRight();
	void AddShapeToPlayground();
	void ShapeMove();
	void SetTime(float dt);
	void OnKeyDown();
	void RotateShape(ROTATE const &rotate);
	void CleanPlayground(std::vector<size_t> const &listForDelete);
	std::vector<glm::fvec2> GetPositionsComponentsShape()const;
	void SetLevel(int level);
	void SetScore(int score);
	void TextDraw(std::string const &text, glm::fvec2 const &pos);
private:
	void DrawPlayground() const;
	void RestructurePlayground();
	//void TextDraw(std::string const &phrase);
	//GLvoid glPrint(const char *fmt, ...);
	//GLvoid BuildFont(GLvoid);
private:
	SSize m_sizePlayground;
	glm::fvec2 m_positionPlayground;
	std::unique_ptr<CShape> m_shape;
	std::unique_ptr<CShape> m_nextShape;
	SHAPE_TYPE m_typeNextShape;
	std::vector<std::vector<SCellView>> m_playground;
	CTimer m_timer;
	int m_level;
	int m_score;
};