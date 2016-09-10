#pragma once
#include "Ellipse.h"



class CEars : public IDrawable
{
public:
	CEars() = default;
	void Setup(float firstRadius, float secondRadius);
	void SetPositionFirstEar(glm::fvec2 const &position);
	void SetPositionSecondEar(glm::fvec2 const &position);
	void SetPetalColor(glm::fvec3 const &color) override;
	void SetCenterColor(glm::fvec3 const &color) override;
	void SetFirstRadius(float radius);
	void SetSecondRadius(float radius);
	void const Draw() override;

private:
	std::vector<CEllipse> m_ears;
};