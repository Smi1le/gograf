#pragma once

#include "AbstractWindow.h"

class IInputEventAcceptor;
namespace sdl
{
// Совершает диспетчеризацию событий SDL по категориям.
void DispatchEvent(const SDL_Event & event, IInputEventAcceptor &acceptor);
}

// Принимает события SDL, разделённые по категориям.
// Деление условное и может быть изменено.
class IInputEventAcceptor
{
public:
    virtual ~IInputEventAcceptor() = default;

    virtual void OnKeyDown() {}
    virtual void OnKeyUp() {}
	virtual void OnKeyLeft() {}
	virtual void OnKeyRight() {}
	virtual void OnKeyP() {}
	virtual void OnKeySpace() {}
};

// Окно, совершающее диспетчеризацию событий SDL
class CAbstractInputControlWindow
        : public CAbstractWindow
        , public IInputEventAcceptor
{
protected:
    void OnWindowEvent(const SDL_Event &event) final
    {
        sdl::DispatchEvent(event, *this);
    }
};
