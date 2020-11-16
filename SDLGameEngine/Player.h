#pragma once
#include "MainWindow.h"
#include "Sprite.h"
#include "Input.h"
#include "Projectile.h"
#include <vector>

class Player
{
public:
	Player(MainWindow* window, Sprite* sprite);
	Player() = default;
	~Player() = default;

public:
	int strength = 0;
	int dexterity = 0;
	int vitality = 0;
	int energy = 0;
	int fasterCastRate = 0;
	int level = 0;
	int gold = 0;
	int stamina = 0;
	double life = 0;
	double mana = 0;
	double hitrate = 0;
	double damage = 0;
	double defense = 0;
	Sprite* sprBullet;
	std::vector<Projectile> projectiles;

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

private:
	void UpdatePlayer();
	void DrawPlayer();

protected:
	virtual void UpdateCharacter() {} // = 0;
	virtual void DrawCharacter() {} // = 0;

public:
	void Update();
	void Draw();
	bool Testing(int hp);

public:
	virtual void LevelUp() {}
	virtual void UpdateStats() {}

	virtual void DrawPlayer(Sprite* sprite, MainWindow* window, int x, int y) {}

	virtual void DrawSkill() {}
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
			hsp = 0.0f;
			vsp = -1.0f;
			posY -= ((int)speed);
		}
		else if (dir == goDown)
		{
			hsp = 0.0f;
			vsp = 1.0f;
			posY += ((int)speed);
		}
		else if (dir == goLeft)
		{
			hsp = -1.0f;
			vsp = 0.0f;
			posX -= ((int)speed);
		}
		else if (dir == goRight)
		{
			hsp = 1.0f;
			vsp = 0.0f;
			posX += ((int)speed);
		}
	}

public:
	MainWindow* window;
	Sprite* sprite;
	SDL_Rect srcRect = { 0, 0, 42, 72 };
	SDL_Rect destRect;
	SDL_Rect hitRect;
	SDL_Rect playerHitbox;
	float posX = 100;
	float posY = 100;
	float hsp = 1.0f;
	float vsp = 1.0f;

};