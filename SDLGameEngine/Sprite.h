#pragma once
#include "SDL_image.h"
#include "MainWindow.h"

class Sprite
{
public:
	MainWindow* window;

public:
	Sprite(const char* path, MainWindow* window);
	~Sprite();

	void ChangeSprite(const char* path);

private:
	const char* path;

public:
	SDL_Surface* surface;
	SDL_Texture* tex;
};

