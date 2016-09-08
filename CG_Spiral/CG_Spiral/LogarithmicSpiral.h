#pragma once
#include <boost/noncopyable.hpp>
#include <glm/vec2.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Drawable.h"

class CLogarithmicSpiral : public IDrawable, private boost::noncopyable
{
public:
	void Init(glm::fvec2 const &center, float a, float b, float scale = 0.1f);
	void Draw() override;
private:
	


private:
	glm::fvec2 m_center;
	float m_coefficientA;
	float m_coefficientB;
	float m_scale;
};