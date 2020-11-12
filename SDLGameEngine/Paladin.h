#pragma once
#include "Player.h"

class Paladin : public Player
{
public:
	Paladin(MainWindow* window, Sprite* sprite);
	~Paladin();

private:
	void UpdateCharacter() override;

public:
	void LevelUp() override;
	void DrawCharacter() override;
};

