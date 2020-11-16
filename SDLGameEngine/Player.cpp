#include "Player.h"
#include "Input.h"

Player::Player(MainWindow* window, Sprite* sprite)
{

	this->window = window;
	this->sprite = sprite;
}

void Player::UpdatePlayer()
{
	
}

void Player::DrawPlayer()
{
	
}

bool Player::Testing(int hp)
{
	if (hp <= 0)
	{
		std::cout << life << "\n";
		return false;
	}
	else
	{
		std::cout << life << "\n";
		return true;
	}
}

void Player::Update()
{
	//UpdatePlayer();
	UpdateCharacter();
	if (Input::KeyPressed(Key::G))
	{
		life = 0;
	}
	Testing(life);
}

void Player::Draw()
{
	//DrawPlayer();
	DrawCharacter();
	DrawSkill();
}
