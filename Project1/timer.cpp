#include "timer.h"
#include <SDL.h>
Timer::Timer()
{
	//Initialize the variables
	startTicks = 0;
	started = false;
}
void Timer::start()
{
	//Start the timer
	started = true;

	//Get the current clock time
	startTicks = SDL_GetTicks();
}

void Timer::stop()
{
	//Stop the timer
	started = false;
}

int Timer::get_ticks()
{
	//If the timer is running
	if (started == true)
	{
			//Return the current time minus the start time
			return SDL_GetTicks() - startTicks;

	}

	//If the timer isn't running
	return 0;
}

bool Timer::is_started()
{
	return started;
}

