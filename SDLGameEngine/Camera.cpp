#include "Camera.h"

void Camera::WorldCamera(Map* map, Player* player)
{
	map->moveMap.x = player->srcRect.x - 200;
	map->moveMap.y = player->srcRect.y - 200;

    
}
