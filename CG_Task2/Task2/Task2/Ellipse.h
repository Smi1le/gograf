#pragma once
#include "Drawable.h"

class CEllipse : public IDrawable
{
public:
	CEllipse() = default;
	void Setup(float firstRadius = 0, float secondRadius = 0, int x = 0, int y = 0);
	void const Draw() override;
	void SetSize(float firstRadius, float secondRadius);
	void SetPetalColor(glm::fvec3 const &color) override;
	void SetCenterColor(glm::fvec3 const &color) override;
	void SetColor(glm::fvec3 const &color);
	void SetPosition(glm::fvec2 const &position) override;
private:
	SSize m_size;
	glm::fvec3 m_centerColor;
	glm::fvec3 m_petalColor;
	glm::fvec2 m_position;
	int m_petalCount;
};