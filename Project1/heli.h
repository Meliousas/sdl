#ifndef HELI_H_INCLUDED
#define HELI_H_INCLUDED

#include "loader.h"
#include "obstacles.h"
#include "timer.h"

SDL_Rect wall2;
SDL_Rect wall3[7];

class Heli :public Timer         ///CLASS OF THE HELICOPTER
{
private:
	///The velocity of the helicopter
	int xVel, yVel;
	static int score;       ///SCORE

public:
	///The collision box of the helicopter
	SDL_Rect box;
	Heli();                 ///CONSTRUCTOR

	///Takes key presses and adjusts the helicopter's velocity
	void handle_input();

	///Moves the helicopter
	void move();

	///Shows the helicopter on the screen
	void show();

	///Sets the camera over the helicopter
	void set_camera();

	static int get_score();
};
int Heli::score = 0;          ///INITIALIZES THE STATIC VARIABLE TO 0
Heli::Heli()
{
	///Initialize the offsets
	box.x = 350;                               ///SETS THE INITIAL POSITION OF THE HELICOPTER
	box.y = 350;
	///Set the helicopter's dimentions
	box.w = 100;
	box.h = 100;

	///Initialize the velocity
	xVel = 0;
	yVel = 5;
}

int Heli::get_score()
{
	return score;
}

void Heli::handle_input()
{
	///If a key was pressed
	if (event.type == SDL_KEYDOWN)
	{
		///Adjust the velocity
		switch (event.key.keysym.sym)
		{
		case SDLK_UP: yVel -= 100/ 2;
			break;
		case SDLK_DOWN: yVel += 100 / 5; break;
		default:
			break;

		}
		score += 2;
	}
	///If a key was released
	else if (event.type == SDL_KEYUP)
	{
		///Adjust the velocity
		switch (event.key.keysym.sym)
		{
		case SDLK_UP: yVel += 100 / 2; break;
		case SDLK_DOWN: yVel -= 100 / 5; break;

		default:
			break;
		}
		score += 1;
	}
}

void Heli::move()
{

	///Move the helicopter up or down
	box.y += yVel;

	for (int i = 0; i < 7; ++i)                ///COLLISION LOOP OF THE HELICOPTER
	{
		///If the helicopter went too far up or down or has collided with the OBSTACLES
		if ((box.y < 0) || (box.y + 100 > 768) || (check_collision(box, wall2) || check_collision(box, wall3[i])))
		{
			///Move back
			box.y -= yVel;
			heli = NULL;
			heli = load_image("images/heli.png", 1);      ///LOADS THE CRASH IMAGE
			game_over = load_image("images/game_over.png");

			apply_surface(box.x, box.y, heli, screen);
			SDL_UpdateWindowSurface(window);


			///LOADS THE GAME OVER IMAGE
			apply_surface(0, 0, game_over, screen);

			SDL_Delay(2000);
			SDL_UpdateWindowSurface(window);


		}
	}
}

void Heli::show()
{
	///Show the helicopter
	apply_surface(box.x - camera.x, box.y - camera.y, heli, screen);
}

void Heli::set_camera()
{
	///Center the camera over the HELICOPTER
	camera.x = (box.x + 144 / 2) - 1024 / 2;
	camera.y = (box.y + 53 / 2) - 768 / 2;

	///Keep the camera in bounds
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
