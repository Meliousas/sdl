//
// Created by Mela on 2019-01-27.
//

#ifndef UNTITLED_WINDOW_H
#define UNTITLED_WINDOW_H

#include "SDL.h"
#include "variables.h"

class Window
{
private:
	bool windowed;
	bool windowOK;

public:
	Window();
};

Window::Window()
{
	///Set up window and renderer
	
	screen = SDL_GetWindowSurface(window);
	SDL_UpdateWindowSurface(window);

	/// window errors check
	if (screen == NULL)
	{
		windowOK = false; return;
	}
	else { windowOK = true; }

	windowed = true;
}

#endif //UNTITLED_WINDOW_H
