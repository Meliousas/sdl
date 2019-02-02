#include "timer.h"
#include <SDL.h>
Timer::Timer()
{
	startTicks = 0;
	started = false;
}
void Timer::start()
{
	started = true;
	startTicks = SDL_GetTicks();
}

void Timer::stop()
{
	started = false;
}

int Timer::get_ticks()
{
	if (started == true)
	{
			return SDL_GetTicks() - startTicks;

	}
	return 0;
}

bool Timer::is_started()
{
	return started;
}

