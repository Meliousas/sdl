#ifndef PLAY_H_INCLUDED
#define PLAY_H_INCLUDED

#include "SDL_rect.h"
#include "SDL.h"
#include "SDL_events.h"
#include "variables.h"
#include "game_functions.h"
#include "loader.h"
#include "obstacles.h"
#include "heli.h"


void wall3_coord()                                  
{
	wall3[0].x = 0;  wall3[0].w = 30;  wall3[0].h = 234;
	wall3[0].y = 0;
	wall3[1].x = 0;  wall3[1].w = 30;  wall3[1].h = 234;
	wall3[1].y = 400;
	wall3[2].x = 650;  wall3[2].w = 30;  wall3[2].h = 234;
	wall3[2].y = 50;
	wall3[3].x = 950;  wall3[3].w = 30;  wall3[3].h = 234;
	wall3[3].y = 450;
	wall3[4].x = 1200;  wall3[4].w = 30;  wall3[4].h = 234;
	wall3[4].y = 90;
	wall3[5].x = 1500;  wall3[5].w = 30;  wall3[5].h = 234;
	wall3[5].y = 303;
	wall3[6].x = 1700;  wall3[6].w = 30;  wall3[6].h = 234;
	wall3[6].y = 502;
}
int play()
{
	wall2.x = 0;
	wall2.y = 1024;
	wall2.w = 768;
	wall2.h = 0;

	wall3_coord();
	int bgX = 0, bgY = 0;
	bool quit = false;


	
	Heli myheli;             
	obstacle obs;
	if (load_files() == false)
	{
		return 1;
	}


	while (quit == false)
	{
		while (SDL_PollEvent(&event))
		{			
			myheli.handle_input();

			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
					quit = true;
				}
				else if (event.type == SDL_QUIT)
				{
					quit = true;
				}

			}
		}

			bgX -= 10;
			for (int i = 0; i < 7; ++i)
			{
				wall3[i].x -= 10;
			}


		if (bgX <= -background->w)
		{
			bgX = 0;

			wall3[0].x = 0;
			wall3[0].y = 0;
			wall3[1].x = 0;
			wall3[1].y = 400;
			wall3[2].x = 650;
			wall3[2].y = 50;
			wall3[3].x = 950;
			wall3[3].y = 450;
			wall3[4].x = 1200;
			wall3[4].y = 90;
			wall3[5].x = 1500;
			wall3[5].y = 303;
			wall3[6].x = 1700;
			wall3[6].y = 502;

		}

		apply_surface(bgX, bgY, background, screen);
		apply_surface(bgX + background->w, bgY, background, screen);


		myheli.move();

		if (myheli.dead) {
			quit = true;
			break;
		}
		
		myheli.show();
		obs.show();         

		if (SDL_UpdateWindowSurface(window) == -1)
		{
			return 1;
		}

		myheli.set_camera();

		apply_surface(0, 0, background, screen, &camera);

		SDL_Delay(70);
	}

	return 0;
}


#endif // PLAY_H_INCLUDED
