#pragma once
#include "MainWindow.h"
#include "Sprite.h"
#include "Input.h"

class Player
{
public:
	Player(MainWindow* window, Sprite* sprite)
	{
		this->window = window;
		this->sprite = sprite;
	}
	Player() = default;
	~Player() = default;

public:
	int strength;
	int dexterity;
	int vitality;
	int energy;
	int fasterCastRate;
	int level;
	int gold;
	int stamina;
	double life;
	double mana;
	double hitrate;
	double damage;
	double defense;
	//double heal = 0;
	//double manaHeal = 0;
	//double experience;
	//double expToNextLevel;

	const char* path;

public:
	enum Direction
	{
		goUp,
		goDown,
		goLeft,
		goRight,
		stall
	};

	Direction dir = stall;
	float speed = 1.01f;

public:
	virtual void LevelUp() {}
	virtual void UpdateStats() {}
	virtual void Update() {}
	virtual void DrawPlayer(Sprite* sprite, MainWindow* window, int x, int y) {}
	virtual const char* SpritePath() { return nullptr; }
	virtual const char* SpriteStallPath() { return nullptr; }

	void SetEnumState()
	{
		if (Input::KeyState(Key::W))
		{
			dir = goUp;
		}
		else if (Input::KeyState(Key::S))
		{
			dir = goDown;
		}
		else if (Input::KeyState(Key::A))
		{
			dir = goLeft;
		}
		else if (Input::KeyState(Key::D))
		{
			dir = goRight;
		}
		else
		{
			dir = stall;
		}
	}

	void SpriteMovement()
	{
		SetEnumState();
		if (dir == goUp)
		{
			posY -= ((int)speed);
		}
		else if (dir == goDown)
		{
			posY += ((int)speed);
		}
		else if (dir == goLeft)
		{
			posX -= ((int)speed);
		}
		else if (dir == goRight)
		{
			posX += ((int)speed);
		}
	}

public:
	MainWindow* window;
	Sprite* sprite;
	SDL_Rect srcRect = { 0, 0, 42, 72 };
	SDL_Rect destRect;
	float posX = 100;
	float posY = 100;

};