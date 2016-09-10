#pragma once
#include "Ellipse.h"

class CArms
{
public:
	CArms() = default;
	void SetupArms(SSize const &sizeArms);
	void Draw();
	void SetPetalColor(glm::fvec3 const &color);
	void SetCenterColor(glm::fvec3 const &color);
	void SetPositionFirstArm(glm::fvec2 const &position);
	void SetPositionSecondArm(glm::fvec2 const &position);
private:
	mutable unsigned m_displayList = 0;
	std::vector<CEllipse> m_arms;
};