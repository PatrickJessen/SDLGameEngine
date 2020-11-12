#include "Paladin.h"

Paladin::Paladin(MainWindow* window, Sprite* sprite)
{
	this->window = window;
	this->sprite = sprite;
	strength = 25;
	dexterity = 20;
	vitality = 25;
	energy = 15;
	stamina = 89;
}

Paladin::~Paladin()
{

}

void Paladin::LevelUp()
{
	life += 2;
	mana += ((int)1.5);
	stamina += 1;
}

void Paladin::UpdateCharacter()
{
	life = ((double)vitality) * 2 + 5;
	mana = ((double)energy) * 1.5 - 7.5;
	stamina = vitality + 64;
	LevelUp();
}

void Paladin::DrawCharacter()
{
	destRect = { (int)posX, (int)posY, 42, 72 };

	SDL_RenderCopyEx(window->GetRender(), sprite->tex, &srcRect, &destRect, 0, 0, SDL_FLIP_NONE);
}