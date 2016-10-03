#include "stdafx.h"
#include "DispatchEvent.h"

namespace
{
glm::vec2 GetMousePosition(const SDL_MouseButtonEvent &event)
{
    return { event.x, event.y };
}

glm::vec2 GetMousePosition(const SDL_MouseMotionEvent &event)
{
    return { event.x, event.y };
}
}

void sdl::DispatchEvent(const SDL_Event &event, IInputEventAcceptor &acceptor)
{
    switch (event.type)
    {
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym)
		{
			case SDLK_DOWN:
				acceptor.OnKeyDown();
				break;
			case SDLK_UP:
				acceptor.OnKeyUp();
				break;
			case SDLK_LEFT:
				acceptor.OnKeyLeft();
				break;
			case SDLK_RIGHT:
				acceptor.OnKeyRight();
				break;
			case SDLK_HOME:
				acceptor.OnKeyP();
				break;
			case SDLK_RCTRL:
				acceptor.OnKeySpace();
				break;
		}
	break;
    }
}
