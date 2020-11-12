#pragma once
#include "Sprite.h"

class Projectile
{
public:
	Sprite* sprite;
	float x, y;
	float hsp, vsp;
	float currentTime = 0.0f;
	float liveTime;

public:
	Projectile(Sprite* sprite, float hsp, float vsp, float x, float y, float liveTime);

public: 
	bool CheckTimeToDestroy();
};

