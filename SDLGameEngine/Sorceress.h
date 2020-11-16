#pragma once
#include "Player.h"

class Sorceress : public Player
{
public:
	Sorceress(MainWindow* window, Sprite* sprite);
	~Sorceress();

private:
	void UpdateCharacter() override;

public:
	void LevelUp() override;
	void DrawSkill() override;
	void DrawCharacter() override;
	
	//const char* SpritePath() override;
	//const char* SpriteStallPath() override;
};