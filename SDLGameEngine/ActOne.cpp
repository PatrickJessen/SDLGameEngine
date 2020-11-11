#include "ActOne.h"

ActOne::ActOne(MainWindow* window)
{
	this->window = window;
	map = new Map(window, "Assets/Map/newMap.map", 59, 50);
	map->texture = map->loadTexture(window->GetRender(), "Assets/Map/newtest.bmp");
	sprite = new Sprite("Assets/Heroes/StallFront.png", window);
	sorc = new Sorceress(window, sprite);
	selectScreen = new CharacterSelection(window);
	player = new Player();

}

void ActOne::Update(MainWindow* window)
{
	player->SpriteMovement();
}

void ActOne::Draw(MainWindow* window)
{
	if (selectScreen->characterScreen == true)
	{
		selectScreen->Draw(window);

	}
	else 
	{

		map->DrawMap(window, 24, 1);
		sorc->DrawPlayer(sprite, window, player->posX, player->posY);
	}
}
