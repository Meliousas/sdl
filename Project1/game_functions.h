//
// Created by Mela on 2019-01-27.
//

#ifndef UNTITLED_GAME_FUNCTIONS_H
#define UNTITLED_GAME_FUNCTIONS_H

#include <sstream>
#include "variables.h"
#include "window.h"

void clean_menu_surfaces();
//void update_screen(Timer& time, int score);

void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL)
{
	///Holds offsets
	SDL_Rect offset;

	///Get offsets
	offset.x = x;
	offset.y = y;

	///Blit
	SDL_BlitSurface(source, clip, destination, &offset);
}

int game_menu()
{
	int choice;
	int x, y;

	menu = load_image("images/menu/main.png");
	play_menu = load_image("images/menu/play.png");
	quit_menu = load_image("images/menu/quit.png");

	bool session = true;

	apply_surface(0, 0, menu, screen);

	while (session)
		while (SDL_PollEvent(&mouse_event))
		{
			if (mouse_event.type == SDL_MOUSEMOTION)       /// mouse move catch
			{
				x = mouse_event.motion.x;           /// mouse coords
				y = mouse_event.motion.y;

				if ((x > 630) && (x < 1010) && (y > 120) && (y < 180))     /// start
				{
					std::string myString("start move");

					apply_surface(0, 0, play_menu, screen);
				}

				else if ((x > 630) && (x < 1010) && (y > 150) && (y < 280))       /// quit
				{
					std::string myString("quit move");
				

					apply_surface(0, 0, quit_menu, screen);

				}
				else
				{
					apply_surface(0, 0, menu, screen);
				}

				SDL_UpdateWindowSurface(window);
			}

			if (mouse_event.type == SDL_MOUSEBUTTONDOWN)             /// mouse press
			{
				x = mouse_event.motion.x;                       /// mouse coords
				y = mouse_event.motion.y;
				std::string myString("event clicked");


				if ((x > 630) && (x < 1010) && (y > 120) && (y < 180))
				{
					std::string myString("start clicked");

					choice = 1;                             /// start
					session = false;
				}
				else if ((x > 630) && (x < 1010) && (y > 150) && (y < 280))
				{
					std::string myString("quit clicked");

					choice = 2;                 /// quit
					session = false;
				}
			}

			switch (mouse_event.type)
			{
			case SDL_KEYDOWN:
				if (mouse_event.key.keysym.sym == SDLK_ESCAPE)
				{
					choice = 2;             /// escape clicked
					session = false;
				}
				break;

			case SDL_QUIT:
				choice = 2;
				session = false;
				break;
			}
		}
	clean_menu_surfaces();
	return choice;
}
//void update_screen(Timer& TimE,int score)       ///UPDATES THE SCREEN
//{
//    std::stringstream samaya;
//    int a=TimE.get_ticks();
//    if(a<60000)
//    {
//        samaya<< "SCORE: "<<score
//              <<"  TIME: " << a/60000<<" : "<<a / 1000;            ///DISPLAYS SCORE AND TIME
//    }
//    else
//    {
//        int sec=a/1000;
//        int min=0;
//        min=sec/60;
//        sec-=min*60;
//        samaya<< "SCORE:  "<<score
//              << "    TIME: " << min<<" : "<<sec;
//
//    }
//   // message = TTF_RenderText_Solid( font , samaya.str().c_str() , textColor ) ;
//    apply_surface((1366-points->w)/2,0,points,screen);
//    SDL_FreeSurface(points);
//
//}

void clean_menu_surfaces()
{
	SDL_FreeSurface(menu);
	SDL_FreeSurface(play_menu);
	SDL_FreeSurface(quit_menu);
}

#endif //UNTITLED_GAME_FUNCTIONS_H
