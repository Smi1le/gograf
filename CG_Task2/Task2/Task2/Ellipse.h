#pragma once
#include "Drawable.h"

class CEllipse : public IEllipseDrawable
{
public:
	CEllipse(float firstRadius = 0, float secondRadius = 0, int x = 0, int y = 0);
	void const Draw() override;
	void SetFirstRadius(float radius) override;
	void SetSecondRadius(float radius) override;
	void SetPetalColor(glm::fvec3 const &color) override;
	void SetCenterColor(glm::fvec3 const &color) override;
	void SetPosition(glm::fvec2 const &position) override;
private:
	float m_firstRadius;
	float m_secondRadius;
	glm::fvec3 m_centerColor;
	glm::fvec3 m_petalColor;
	glm::fvec2 m_position;
	int m_petalCount;
};