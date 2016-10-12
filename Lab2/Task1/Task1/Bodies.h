#pragma once

#include <glm/vec3.hpp>
#include <glm/fwd.hpp>
#include <boost/noncopyable.hpp>

enum class ShapeFace
{
	pentagon = 0,
	triangle,

	NumFaces
};


class CIdentityCube
{
public:
	CIdentityCube();
	void Update(float deltaTime);
	void Draw()const;

	void SetScale(float scale);
	void SetFaceColor(ShapeFace face, const glm::vec4 &color);
protected:
	float m_scale;

private:
	static const size_t COLORS_COUNT = static_cast<size_t>(ShapeFace::NumFaces);
	glm::vec4 m_colors[COLORS_COUNT];
};

class CAnimatedCube : public CIdentityCube
{
public:
    void Update(float deltaTime);
    void Draw()const;

private:
    enum Animation
    {
        Rotating,
        Pulse,
        Bounce,
    };

    glm::mat4 GetAnimationTransform()const;

    static const float ANIMATION_STEP_SECONDS;
    Animation m_animation = Rotating;
    float m_animationPhase = 0;
	
};
