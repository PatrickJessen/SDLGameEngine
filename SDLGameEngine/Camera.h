#pragma once
#include "Map.h"
#include "Player.h"

class Camera
{
public:
	Camera() = default;
	~Camera() = default;

public:
	void WorldCamera(Map* map, Player* player);

public:
	Map* map;
	Player* player;
};

