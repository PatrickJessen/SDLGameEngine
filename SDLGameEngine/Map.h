#pragma once
#include "SDL.h"
#include "MainWindow.h"
#include <fstream>
#include <vector>

struct Tile
{
	int texture;
	int depth;
};

class Map
{
public:
	MainWindow* window;

	SDL_Texture* texture = nullptr;
	SDL_Rect dstRect;
	SDL_Rect srcRect;
	SDL_Rect moveMap = { 0, 0 };

	int height;
	int width;
	Tile* level = nullptr;

	Map(MainWindow* window, const char* path, int width, int height);
	~Map();

public:
	void LoadMap(const char* path, int width, int height);
	void SaveMap(const char* path);

public:
	int tileSize;
	int zoom;
	void DrawMap(MainWindow* window, int tileSize, int zoom);

	static SDL_Texture* loadTexture(SDL_Renderer* renderer, const char* filePath);
};

