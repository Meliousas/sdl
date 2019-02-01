#ifndef PLAY_H_INCLUDED
#define PLAY_H_INCLUDED
//void wel_come()                                   ///WELCOME FUNCTION TO LOAD IMAGE AND SOUND
//{
//	welcome = load_image("images/welcome.png");
//	apply_surface(0, 0, welcome, screen);
//	loading = Mix_LoadWAV("sound/loading.wav");
//	Mix_PlayChannel(-1, loading, 0);
//	SDL_Flip(screen);
//	SDL_Delay(2000);
//}

#include "SDL_rect.h"
#include "SDL.h"
#include "SDL_events.h"
#include "variables.h"
#include "game_functions.h"
#include "loader.h"
#include "obstacles.h"
#include "heli.h"

//SDL_Rect wall2;
//SDL_Rect wall3[7];

void wall3_coord()                                  ///SETS COORDINATES OF THE OBSTACLES
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
	wall2.h = 20;

	wall3_coord();
	///Quit flag
	bool quit = false;
	///The offsets of the background
	int bgX = 0, bgY = 0;
	Heli myheli;                        ///CREATING OBJECT OF THE HELI CLASS

	///The frame rate regulator
	obstacle obs;                       ///CREATING OBJECT OF THE OBSTACLE CLASS

	///Create a window
	Window myWindow;

	if (myWindow.error() == true)
	{
		return 1;
	}

	 ///Load the files
	if (load_files() == false)
	{
		return 1;
	}

	///While the user hasn't quit
	while (quit == false)
	{
		///While there's events to handle
		while (SDL_PollEvent(&event))
		{			
			///Handle events for the heli
			myheli.handle_input();

			if (event.type == SDL_KEYDOWN)
			{
				///If escape was pressed
				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
					quit = true;
				}

				///If the user has Xed out the window
				else if (event.type == SDL_QUIT)
				{
					///Quit the program
					quit = true;
				}

			}
		}
			///Scroll background
			bgX -= 10;
			for (int i = 0; i < 7; ++i)
			{
				///Move the collision wall along with the background
				wall3[i].x -= 10;
			}
	//	If the background has gone too far
		if (bgX <= -background->w)
		{
		//	Reset the offset of background
			bgX = 0;

		//	RESET THE OFFSET OF THE COLLISION WALL
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

		///Show the background
		apply_surface(bgX, bgY, background, screen);
		apply_surface(bgX + background->w, bgY, background, screen);


		///move the helicopter
		myheli.move();

		if (myheli.dead) {
			quit = true;
			break;
		}
		
		///show the helicopter on the screen
		myheli.show();
		obs.show();         ///SHOWS THE OBSTACLES

		///Update the screen
		if (SDL_UpdateWindowSurface(window) == -1)
		{
			return 1;
		}
		///Set the camera
		myheli.set_camera();

		///Show the background
		apply_surface(0, 0, background, screen, &camera);

		SDL_Delay(100);
	}

	return 0;
}


#endif // PLAY_H_INCLUDED
