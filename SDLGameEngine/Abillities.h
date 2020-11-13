#pragma once
#include "Projectile.h"
#include <vector>

class Abillities
{
public:
	Abillities();
	~Abillities();

public:
	void Fireball();

public:
	Sprite* spell;
	std::vector<Projectile> casterSpells;
};

