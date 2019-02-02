#ifndef COLLISION_H_INCLUDED
#define COLLISION_H_INCLUDED
#include "variables.h"

SDL_Rect camera = { 0, 0, 1024, 768 };
bool check_collision(SDL_Rect A, SDL_Rect B)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = A.x;
	rightA = A.x + A.w;
	topA = A.y;
	bottomA = A.y + A.h;

	leftB = B.x;
	rightB = B.x + B.w;
	topB = B.y;
	bottomB = B.y + B.h;

	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}

	return true;
}

class obstacle
{
public:
	SDL_Rect box[7];

	obstacle();

	void show();

};
obstacle::obstacle()
{
	box[0].x = 0;
	box[0].y = 0;
	box[1].x = 0;
	box[1].y = 400;
	box[2].x = 650;
	box[2].y = 50;
	box[3].x = 950;
	box[3].y = 450;
	box[4].x = 1200;
	box[4].y = 90;
	box[5].x = 1500;
	box[5].y = 303;
	box[6].x = 1700;
	box[6].y = 502;

	for (int i = 0; i < 7; ++i)
	{
		box[i].w = 35;
		box[i].h = 240;
	}

}
void obstacle::show()
{
	for (int i = 0; i < 7; ++i)
		apply_surface(box[i].x, box[i].y, OBSTACLES, background);

}

#endif // COLLISION_H_INCLUDED
