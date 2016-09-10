#include "stdafx.h"
#include "Window.h"
#include <SDL2/SDL.h>

// ��������� ������������ main �� SDL_main,
// �.�. ���������� ���������� c SUBSYSTEM:CONSOLE
#ifdef _WIN32
#undef main
#endif

int main(int, char *[])
{
    glewInit();

    CWindow window;
    window.Show({800, 600});
    window.DoGameLoop();

    return 0;
}
