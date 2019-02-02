#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED

#include <SDL_surface.h>

///window
SDL_Window *window = NULL;

/// game
SDL_Surface *game_over = NULL;
SDL_Surface *background = NULL;
SDL_Surface *screen = NULL;
SDL_Surface *OBSTACLES = NULL;
SDL_Surface *heli = NULL;
SDL_Surface *points = NULL;


/// menu
SDL_Surface* menu = NULL;
SDL_Surface* play_menu = NULL;
SDL_Surface* quit_menu = NULL;

SDL_Color textColor = { 255, 0, 0 };

SDL_Event event;
SDL_Event mouse_event;

#endif // VARIABLES_H_INCLUDED
