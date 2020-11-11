#pragma once
#include "Player.h"
#include "Sorceress.h"
#include "Barbarian.h"
#include "Sprite.h"
#include "MainWindow.h"
#include "Paladin.h"

class CharacterSelection
{
public:
	MainWindow* window;
	Sprite* sprite;


	CharacterSelection(MainWindow* window);

	void Draw(MainWindow* window);
	void Update();
	bool XYInRect(const SDL_Rect& rect, int x, int y);

	enum CharPick
	{
		sorc,
		pala,
		barb,
		none
	};

	CharPick pick = none;

	bool menu = true;

private:
	SDL_Rect destRect = { 0, 0, 0, 0 };
	SDL_Rect srcRect = { 0, 0, 900, 700 };

	SDL_Rect sorcRect = { 700, 280, 72, 220 };
	SDL_Rect palaRect = { 590, 260, 80, 220 };
	SDL_Rect barbRect = { 440, 240, 90, 220 };
};

