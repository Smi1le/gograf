#include "stdafx.h"
#include "WindowClient.h"
#include <SDL2/SDL.h>

// ��������� ������������ main �� SDL_main,
// �.�. ���������� ���������� c SUBSYSTEM:CONSOLE
#ifdef _WIN32
#undef main
#endif


int main(int, char *[])
{
	try
	{
		CWindow window;
		window.Show("Kannabola SPACE or RCTRL or RShift", { 800, 600 });
		CWindowClient client(window);
		window.DoMainLoop();
	}
	catch (const std::exception &ex)
	{
		const char *title = "Fatal Error";
		const char *message = ex.what();
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, title, message, nullptr);
	}

	return 0;
}

