#pragma once

#include <glm/fwd.hpp>
#include <glm/vec3.hpp>
#include <SDL2/SDL_events.h>
#include <boost/noncopyable.hpp>
#include "DispatchEvent.h"
#include <set>

class CCamera : private boost::noncopyable
{
public:
    explicit CCamera(float rotationRadians, float distance);

    void Update(float deltaSec);
    bool OnKeyDown(const SDL_KeyboardEvent &event);
    bool OnKeyUp(const SDL_KeyboardEvent &event);
	void OnDragBegin(const glm::vec2 &pos);
	void OnDragMotion(const glm::vec2 &pos);
	void OnDragEnd(const glm::vec2 &pos);
    void SetDirection(const glm::vec3 &direction);

    glm::mat4 GetViewTransform() const;

private:
	float m_rotationRadiansX = 0;
	float m_rotationRadiansY = 0;

    glm::vec3 m_direction;
    float m_distance = 1;
    std::set<unsigned> m_keysPressed;

	bool isRotating = false;
	glm::vec2 m_dragBeginPos;
	glm::vec2 xPos;
};
