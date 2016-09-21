#pragma once



class IDrawable
{
public:
	virtual const void Draw() = 0;
	virtual void SetPetalColor(glm::fvec3 const &color) = 0;
	virtual void SetCenterColor(glm::fvec3 const &color) = 0;
	virtual void SetPosition(glm::fvec2 const &position) = 0;
};

class IEllipseDrawable : public IDrawable
{
public:
	virtual void SetFirstRadius(float radius) = 0;
	virtual void SetSecondRadius(float radius) = 0;
};