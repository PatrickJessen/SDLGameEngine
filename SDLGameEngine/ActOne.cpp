#include "ActOne.h"

ActOne::ActOne(MainWindow* window)
{
	map = new Map(window, "Assets/Map/newMap.map", 59, 50);
	map->texture = map->loadTexture(window->GetRender(), "Assets/Map/newtest.bmp");
}

void ActOne::Update(MainWindow* window)
{
	
}

void ActOne::Draw(MainWindow* window)
{
	map->DrawMap(window, 24, 1);
}
