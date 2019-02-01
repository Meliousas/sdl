#ifndef COLLISION_H_INCLUDED
#define COLLISION_H_INCLUDED
#include "variables.h"

SDL_Rect camera = { 0, 0, 1024, 768 };
bool check_collision(SDL_Rect A, SDL_Rect B)
{
	///The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	///Calculate the sides of rect A
	leftA = A.x;
	rightA = A.x + A.w;
	topA = A.y;
	bottomA = A.y + A.h;

	///Calculate the sides of rect B
	leftB = B.x;
	rightB = B.x + B.w;
	topB = B.y;
	bottomB = B.y + B.h;

	///If any of the sides from A are outside of B
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

	///If none of the sides from A are outside B
	return true;
}

//void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL)
//{
//	///Holds offsets
//	SDL_Rect offset;
//
//	///Get offsets
//	offset.x = x;
//	offset.y = y;
//
//	///Blit
//	SDL_BlitSurface(source, clip, destination, &offset);
//}

class obstacle
{
public:
	///The collision box of the obstacle
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


	///Set the obstacle's dimentions
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
