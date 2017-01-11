#include "stdafx.h"
#include "WindowClient.h"
#include <SDL2/SDL.h>

int main(int, char *[])
{
	try
	{
		CWindow window(ContextProfile::RobustOpenGL_3_2, ContextMode::Debug);
		window.Show("Interior room", { 800, 600 });
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

