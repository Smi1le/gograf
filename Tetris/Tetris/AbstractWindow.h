#pragma once

#include <memory>
#include <boost/noncopyable.hpp>
#include <glm/fwd.hpp>
#include <SDL2/SDL_events.h>

class CChronometer
{
public:
	CChronometer();
	float GrabDeltaTime();

	void WaitNextFrameTime(const std::chrono::milliseconds &framePeriod);

private:
	std::chrono::system_clock::time_point m_lastTime;
};

class CAbstractWindow : private boost::noncopyable
{
public:
    CAbstractWindow();
    virtual ~CAbstractWindow();

    void Show(glm::ivec2 const& size);
    void DoGameLoop();

protected:
    void SetBackgroundColor(glm::vec4 const& color);

    virtual void OnWindowEvent(const SDL_Event &event) = 0;
    virtual void OnUpdateWindow(float deltaSeconds) = 0;
    virtual void OnDrawWindow(glm::ivec2 const& size) = 0;
	virtual void OnDispatchEvent(SDL_Event const &event) = 0;

private:
    class Impl;
    std::unique_ptr<Impl> m_pImpl;
};
