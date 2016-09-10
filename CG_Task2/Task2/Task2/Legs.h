#pragma once
#include "Ellipse.h"


class CLegs : public IDrawable
{
public:
	void Setup(float firstRadius, float secondRadius);
	void SetPetalColor(glm::fvec3 const &color) override;
	void SetCenterColor(glm::fvec3 const &color) override;
	void const Draw() override;
	void SetFirstRadiusFirstLeg(float radius);
	void SetFirstRadiusSecondLeg(float radius);
	void SetSecondRadiusFirstLeg(float radius);
	void SetSecondRadiusSecondLeg(float radius);
	void SetPositionFirstLeg(glm::fvec2 const &position);
	void SetPositionSecondLeg(glm::fvec2 const &position);
	void SetFirstRadius(float radius);
	void SetSecondRadius(float radius);

private:
	std::vector<CEllipse> m_legs;
};