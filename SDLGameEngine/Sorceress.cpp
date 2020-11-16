#include "Sorceress.h"


Sorceress::Sorceress(MainWindow* window, Sprite* sprite)
	: Player(window, sprite)
{
	strength = 10;
	dexterity = 25;
	vitality = 10;
	energy = 35;
	stamina = vitality + 64;
	sprBullet = new Sprite("Assets/Skills/Firebolt.png", window);
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
	//LevelUp();

	if (Input::KeyPressed(Key::F))
	{
		projectiles.push_back(Projectile(sprBullet, posX, posY, hsp, vsp, 2.0f));
	}

	for (int i = 0; i < 100; i++)
		projectiles.push_back(Projectile(sprBullet, posX, posY, hsp, vsp, 2.0f));

	for (int i = 0; i < projectiles.size(); i++)
	{
		if (projectiles[i].CheckTimeToDestroy())
			projectiles.erase(projectiles.begin() + i);
		else
		{
			projectiles[i].x += projectiles[i].hsp * 2.0f;
			projectiles[i].y += projectiles[i].vsp * 2.0f;
			//hitRect = { (int)projectiles[i].x, (int)projectiles[i].y, 120, 120 };
		}
	}
}

void Sorceress::DrawSkill()
{
	for (int i = 0; i < projectiles.size(); i++)
	{
		destRect = { (int)projectiles[i].x, (int)projectiles[i].y, 32, 32 };
		SDL_SetRenderDrawColor(window->GetRender(), 255, 0, 0, 255);
		SDL_RenderDrawRect(window->GetRender(), &destRect);
		SDL_RenderCopyEx(window->GetRender(), sprBullet->tex, &srcRect, &destRect, 0, 0, SDL_FLIP_NONE);
	}

}

void Sorceress::DrawCharacter()
{
	destRect = { (int)posX, (int)posY, 42, 72 };
	SDL_RenderDrawRect(window->GetRender(), &destRect);

	SDL_RenderCopyEx(window->GetRender(), sprite->tex, &srcRect, &destRect, 0, 0, SDL_FLIP_NONE);
}