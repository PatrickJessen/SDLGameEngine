#pragma once
#include "Map.h"
#include "MainWindow.h"
#include "Player.h"
#include "Sorceress.h"
#include "Paladin.h"
#include "CharacterSelection.h"

class ActOne
{
private:
	MainWindow* window;
	//Sprite* select;
	Map* map;
	Player* sorc;
	Player* pala;
	Player* barb;
	Sprite* spriteSorc;
	Sprite* spritePala;
	Sprite* spriteBarb;
	CharacterSelection* selectScreen;

public:
	ActOne(MainWindow* window);

	void Update(MainWindow* window);
	void Draw(MainWindow* window);

private:
	void CheckSelectedChar();
	void CharUpdate();
};

