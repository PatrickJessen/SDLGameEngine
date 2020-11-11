#include "Sorceress.h"

Sorceress::Sorceress(MainWindow* window, Sprite* sprite)
{
	this->window = window;
	this->sprite = sprite;
	strength = 10;
	dexterity = 25;
	vitality = 10;
	energy = 35;
	stamina = 74;
}

Sorceress::~Sorceress()
{

}

void Sorceress::LevelUp()
{
	life += 1;
	mana += 2;
	stamina += 1;
}

void Sorceress::Update()
{
	life = ((double)vitality) * 2 + 20;
	mana = ((double)energy) * 2 - 35;
	stamina = vitality + 64;
	LevelUp();
}

void Sorceress::DrawPlayer(Sprite* sprite, MainWindow* window, int x, int y)
{
	destRect = { x, y, 42, 72 };

	SDL_RenderCopyEx(window->GetRender(), sprite->tex, &srcRect, &destRect, 0, 0, SDL_FLIP_NONE);
}