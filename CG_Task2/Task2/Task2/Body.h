#pragma once
#include <boost\noncopyable.hpp>
#include "Ellipse.h"

class CBody : public IDrawable , private boost::noncopyable
{
public:
	void SetPosition(glm::fvec2 const &position);
	void SetRadius(float radius);
	void SetPetalColor(glm::fvec3 const &color) override;
	void SetCenterColor(glm::fvec3 const &color) override;
	void const Draw() override;
private:
	CEllipse m_body;
};