#include "Barbarian.h"

Barbarian::Barbarian(MainWindow* window, Sprite* sprite)
	: Player(window, sprite)
{
	strength = 30;
	dexterity = 20;
	vitality = 25;
	energy = 10;
	stamina = 92;
}

Barbarian::~Barbarian()
{

}

void Barbarian::LevelUp()
{
	life += 2;
	mana += 1;
	stamina += 1;
}

void Barbarian::UpdateCharacter()
{
	life = (((double)vitality) * 4) + stamina - 137;
	mana = ((double)energy);
	LevelUp();
}

void Barbarian::DrawCharacter()
{
	destRect = { (int)posX, (int)posY, 42, 72 };
	SDL_RenderDrawRect(window->GetRender(), &destRect);
	SDL_RenderCopyEx(window->GetRender(), sprite->tex, &srcRect, &destRect, 0, 0, SDL_FLIP_NONE);
}