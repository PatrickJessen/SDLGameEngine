#pragma once
#include "Player.h"

class Sorceress : public Player
{
public:
	Sorceress(MainWindow* window, Sprite* sprite);
	~Sorceress();

public:
	void LevelUp() override;
	void Update() override;
	void DrawPlayer(Sprite* sprite, MainWindow* window, int x, int y) override;
	//const char* SpritePath() override;
	//const char* SpriteStallPath() override;
};