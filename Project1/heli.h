#ifndef HELI_H_INCLUDED
#define HELI_H_INCLUDED

#include "loader.h"
#include "obstacles.h"
#include "timer.h"

SDL_Rect wall2;
SDL_Rect wall3[7];

class Heli
{
private:
	int xVel, yVel;
	static int score;    

public:
	SDL_Rect box;
	bool dead = false;
	Heli();                 

	void handle_input();
	void move();
	void show();

	void set_camera();

	static int get_score();
};
int Heli::score = 0;        
Heli::Heli()
{
	box.x = 350;                               
	box.y = 350;
	
	box.w = 100;
	box.h = 100;

	xVel = 0;
	yVel = 5;
}

int Heli::get_score()
{
	return score;
}

void Heli::handle_input()
{
	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_UP: yVel -= 100/ 2;
			break;
		case SDLK_DOWN: yVel += 100 / 5; 
			break;
		default:
			break;

		}


		score += 2;
	}

	else if (event.type == SDL_KEYUP)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_UP: yVel += 100 / 2; 
			break;
		case SDLK_DOWN: yVel -= 100 / 5; 
			break;

		default:
			break;
		}


		score += 1;
	}
}

void Heli::move()
{

	box.y += yVel;

	for (int i = 0; i < 7; ++i)                {
		if ((box.y < 0) || (box.y + 100 > 768) || (check_collision(box, wall2) || check_collision(box, wall3[i])))
		{
			box.y -= yVel;
			heli = NULL;
			dead = true;

			game_over = load_image("images/game_over.png");
			apply_surface(0, 0, game_over, screen);

			SDL_UpdateWindowSurface(window);

			SDL_Delay(500);
		}
	}
}

void Heli::show()
{
	apply_surface(box.x - camera.x, box.y - camera.y, heli, screen);
}

void Heli::set_camera()
{
	camera.x = (box.x + 100 / 2) - 1024 / 2;
	camera.y = (box.y + 100 / 2) - 768 / 2;

	if (camera.x < 0)
	{
		camera.x = 0;
	}
	if (camera.y < 0)
	{
		camera.y = 0;
	}
	if (camera.x > 1024 - camera.w)
	{
		camera.x = 1024 - camera.w;
	}
	if (camera.y > 768 - camera.h)
	{
		camera.y = 768 - camera.h;
	}
}

#endif // HELI_H_INCLUDED
