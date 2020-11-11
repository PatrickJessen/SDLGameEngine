#include "ActOne.h"

ActOne::ActOne(MainWindow* window)
{
	this->window = window;
	map = new Map(window, "Assets/Map/newMap.map", 59, 50);
	map->texture = map->loadTexture(window->GetRender(), "Assets/Map/newtest.bmp");
	spriteSorc = new Sprite("Assets/Heroes/StallFront.png", window);
	spritePala = new Sprite("Assets/Heroes/Paladin.png", window);
	spriteBarb = new Sprite("Assets/Heroes/Barbarian.png", window);
	sorc = new Sorceress(window, spriteSorc);
	pala = new Paladin(window, spritePala);
	barb = new Barbarian(window, spriteBarb);
	selectScreen = new CharacterSelection(window);
	player = new Player(window, spriteSorc);

}

void ActOne::Update(MainWindow* window)
{
	player->SpriteMovement();
	selectScreen->Update();
}

void ActOne::Draw(MainWindow* window)
{
	if (selectScreen->menu == true)
	{
		selectScreen->Draw(window);

	}
	else if (selectScreen->menu == false)
	{

		map->DrawMap(window, 24, 1);
		CheckSelectedChar();
	}
}

void ActOne::CheckSelectedChar()
{
	if (selectScreen->pick == selectScreen->sorc)
	{
		sorc->DrawPlayer(spriteSorc, window, player->posX, player->posY);
	}
	else if (selectScreen->pick == selectScreen->pala)
	{
		pala->DrawPlayer(spritePala, window, player->posX, player->posY);
	}
	else if (selectScreen->pick == selectScreen->barb)
	{
		barb->DrawPlayer(spriteBarb, window, player->posX, player->posY);
	}
}
