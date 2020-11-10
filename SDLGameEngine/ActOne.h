#pragma once
#include "Map.h"
#include "MainWindow.h"
class ActOne
{
private:
	MainWindow* window;
	Map* map;

public:
	ActOne(MainWindow* window);

	void Update(MainWindow* window);
	void Draw(MainWindow* window);
};

