#pragma once
#include "Player.h"

class Barbarian : public Player
{
public:
	Barbarian(MainWindow* window, Sprite* sprite);
	~Barbarian();

public:
	void LevelUp() override;
	void Update() override;
	void DrawPlayer(Sprite* sprite, MainWindow* window, int x, int y) override;
};

