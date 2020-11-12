#include "Sorceress.h"


Sorceress::Sorceress(MainWindow* window, Sprite* sprite)
	: Player(window, sprite)
{
	strength = 10;
	dexterity = 25;
	vitality = 10;
	energy = 35;
	stamina = 74;
	//sprite = new Sprite("Assets/Skills/Firebolt.png", window);
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

void Sorceress::UpdateCharacter()
{
	life = ((double)vitality) * 2 + 20;
	mana = ((double)energy) * 2 - 35;
	stamina = vitality + 64;
	LevelUp();
}

void Sorceress::DrawSkill(MainWindow* window)
{
	/*if (Input::KeyState(Key::F))
	{

		skillDirection = { (int)posX++, destRect.y, 32, 32 };
		SDL_Rect skillRect = { 0, 0, 32, 32 };
		SDL_RenderCopyEx(window->GetRender(), sprite->tex, &skillRect, &skillDirection, 0, 0, SDL_FLIP_NONE);
	}*/

}

void Sorceress::DrawCharacter()
{
	destRect = { (int)posX, (int)posY, 42, 72 };

	SDL_RenderCopyEx(window->GetRender(), sprite->tex, &srcRect, &destRect, 0, 0, SDL_FLIP_NONE);
}

int Sorceress::test()
{
	return 0;
}

class BaseClass
{
public:
	int xPos = 32;
};
