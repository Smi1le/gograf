#pragma once
#include "Ellipse.h"


class CEye : public IDrawable
{
public:
	void Setup(float firstRadius, float secondRadius);
	void SetPetalColor(glm::fvec3 const &color) override;
	void SetCenterColor(glm::fvec3 const &color) override;
	void SetPosition(glm::fvec2 const &position) override;
	void SetPositionPupil(glm::fvec2 const &position);
	void SetSizePupil(SSize const &size);
	void SetColorPupil(glm::fvec3 const &color);
	void const Draw() override;

private:
	CEllipse m_eye;
	CEllipse m_pupil;
};
