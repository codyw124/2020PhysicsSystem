#pragma once
#include <SDL.h>

class EventHandler
{
public:
	virtual void handleEvent(SDL_Event* event, SDL_Renderer* renderer) = 0;
};