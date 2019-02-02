#include <iostream>
#include "SDL_image.h"
#include <string>
#include "SDL.h"
#include "window.h"
#include "loader.h"
#include "game_functions.h"
#include "play.h"

int main(int argc, char* args[])
{
	bool notQuited = true;

	if (!init()) { return 1; }

	int opt;
	SDL_Delay(2000);

	while (notQuited)
	{
		opt = game_menu();        
		switch (opt) {
		case 1:
			play();
			break;
		case 2:
			notQuited = false;
			break;
		default:
			break;
		}
	}

	clean_up(); 
	return 0;
}