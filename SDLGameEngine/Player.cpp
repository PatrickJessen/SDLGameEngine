#include "Player.h"
#include "Input.h"

Player::Player(MainWindow* window, Sprite* sprite)
{
	sprBullet = new Sprite("Assets/Skills/Firebolt.png", window);

	this->window = window;
	this->sprite = sprite;
}

void Player::UpdatePlayer()
{
	if (Input::KeyPressed(Key::F))
	{
		projectiles.push_back(Projectile(sprBullet, posX, posY, hsp, vsp, 2.0f));
	}

	for (int i = 0; i < projectiles.size(); i++)
	{
		if (projectiles[i].CheckTimeToDestroy())
			projectiles.erase(projectiles.begin() + i);
		else
		{
			projectiles[i].x += projectiles[i].hsp * 2.0f;
			projectiles[i].y += projectiles[i].vsp * 2.0f;
		}
	}
}

void Player::DrawPlayer()
{
	for (int i = 0; i < projectiles.size(); i++)
	{
		destRect = { (int)projectiles[i].x, (int)projectiles[i].y, 32, 32 };
		SDL_RenderCopyEx(window->GetRender(), sprBullet->tex, &srcRect, &destRect, 0, 0, SDL_FLIP_NONE);
	}
}

void Player::Update()
{
	UpdatePlayer();
	UpdateCharacter();
}

void Player::Draw()
{
	DrawPlayer();
	DrawCharacter();
}
