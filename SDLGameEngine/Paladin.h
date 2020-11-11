#pragma once
#include "Player.h"

class Paladin : public Player
{
public:
	Paladin(MainWindow* window, Sprite* sprite);
	~Paladin();

public:
	void LevelUp() override;
	void Update() override;
	void DrawPlayer(Sprite* sprite, MainWindow* window, int x, int y) override;
};

