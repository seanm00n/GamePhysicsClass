#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

class Walker
{
	int _x, _y;
public:
	Walker(int x, int y);
	void draw(SDL_Renderer* renderer);
	void update();
};