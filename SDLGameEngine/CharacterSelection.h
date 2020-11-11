#pragma once
#include "Player.h"
#include "Sorceress.h"
#include "Barbarian.h"
#include "Sprite.h"
#include "MainWindow.h"

class CharacterSelection
{
public:
	MainWindow* window;
	Sprite* sprite;
	/*Player* player;
	Player* sorc;
	Player* barb;*/

	CharacterSelection(MainWindow* window);

	void Draw(MainWindow* window);
	void Update();

	bool characterScreen = true;

private:
	SDL_Rect destRect;
	SDL_Rect srcRect = { 0, 0, 900, 700 };

	SDL_Rect sorcRect = { 0, 0, 100, 100 };
};

