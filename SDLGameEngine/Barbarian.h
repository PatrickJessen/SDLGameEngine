#pragma once
#include "Player.h"

class Barbarian : public Player
{
public:
	Barbarian(MainWindow* window, Sprite* sprite);
	~Barbarian();

private:
	void UpdateCharacter() override;

public:
	void LevelUp() override;
	void DrawCharacter() override;
};

