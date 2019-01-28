//
// Created by Mela on 2019-01-27.
//

#ifndef UNTITLED_LOADER_H
#define UNTITLED_LOADER_H

#include <SDL.h>
#include "variables.h"

bool init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		return false;
	}
	window = SDL_CreateWindow("My Game Window",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		1024, 768,
		0);

	screen = SDL_GetWindowSurface(window);
	SDL_UpdateWindowSurface(window);

	/// catch screen error
	return screen != NULL;

}
void clean_up()
{
	SDL_FreeSurface(heli);
	//   SDL_FreeSurface( OBSTACLES );
	SDL_FreeSurface(background);
	SDL_FreeSurface(welcome);
	SDL_FreeSurface(transparent);

	SDL_Quit();
}

SDL_Surface *load_image(std::string filename, int n = 0)         ///FUNCTION FOR LOADING IMAGE
{
	///The image that's loaded
	SDL_Surface* loadedImage = NULL;

	///The optimized surface that will be used
	SDL_Surface* optimizedImage = NULL;

	///Load the image
	loadedImage = IMG_Load(filename.c_str());

	///If the image loaded
	if (loadedImage != NULL)
	{
	
	        ///Create an optimized surface
	        optimizedImage = SDL_ConvertSurfaceFormat( loadedImage, SDL_GetWindowPixelFormat(window), 0);
	
	        ///Free the old surface
	        SDL_FreeSurface( loadedImage );
	
	        ///If the surface was optimized
	        if( optimizedImage != NULL )
	        {
	            if(n==0)
	            {
	
	                ///Map the color key
	                Uint32 colorkey = SDL_MapRGB( optimizedImage->format, 73, 203, 58 );
	
	                ///Set all pixels of color R 0, G 0xFF, B 0xFF to be transparent
	                SDL_SetColorKey( optimizedImage, SDL_TRUE, colorkey );
	            }
	            else if(n==1)
	            {
	                ///Map the color key
	                Uint32 colorkey = SDL_MapRGB( optimizedImage->format, 255, 255, 128 );
	
	                ///Set all pixels of color R 0, G 0xFF, B 0xFF to be transparent
	                SDL_SetColorKey( optimizedImage, SDL_TRUE, colorkey );
	            }
	
	        }
	    }

		///Return the optimized surface
	return optimizedImage;
}

#endif //UNTITLED_LOADER_H
