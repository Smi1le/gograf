#pragma once
#include <glm/vec2.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Size.h"
#include "Drawable.h"



class CRectangle : public IDrawable
{
public:
	CRectangle(SSize const &size, glm::fvec2 const &position);
	CRectangle(float x, float y, float width, float height);
	void Draw() override;
private:
	bool m_isMinSideWidth;
	float m_minSide;
	SSize m_size;
	glm::fvec2 m_position;
};