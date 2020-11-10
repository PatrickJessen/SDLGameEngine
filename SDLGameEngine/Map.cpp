#include "Map.h"
#include "Filehandler/simple_file_handler.h"

#define INDEX y * width + x

using namespace SimpleFileHandler;

Map::Map(MainWindow* window, const char* path, int width, int height)
{
    this->window = window;
    LoadMap(path, width, height);
}

Map::~Map()
{
    delete level;
}


void Map::LoadMap(const char* path, int width, int height)
{
    this->height = height;
    this->width = width;

    if (level != nullptr)
        delete level;

    level = new Tile[height * width];

    ReadFile inFile(path);

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            level[INDEX] = inFile.ReadClass<Tile>();
            //level[INDEX].texture = inFile.ReadPrimitive<int>();
        }
    }
    inFile.Close();
}

void Map::SaveMap(const char* path)
{
    WriteFile outFile(path);
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            outFile.WriteClass<Tile>(level[INDEX]);
        }
    }
    outFile.Close();
}

void Map::DrawMap(MainWindow* window, int tileSize, int zoom)
{
    this->tileSize = tileSize;
    this->zoom = zoom;
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            // tile position
            dstRect = { x * tileSize * zoom + moveMap.x, y * tileSize * zoom + moveMap.y, tileSize * zoom, tileSize * zoom };
            // tilenummer fra txt filen
            srcRect = { level[INDEX].texture * tileSize, 0, tileSize, tileSize };
            SDL_RenderCopy(window->GetRender(), texture, &srcRect, &dstRect);
        }
    }
}

SDL_Texture* Map::loadTexture(SDL_Renderer* renderer, const char* filePath)
{
    SDL_Surface* surface(SDL_LoadBMP(filePath));
    if (surface) {
        SDL_Texture* texture(SDL_CreateTextureFromSurface(renderer, surface));
        if (texture) {
            printf("Texture loaded successfully: %s\n", filePath);
            return texture;
        }
        printf("Failed to create texture: %s\n", filePath);
        return nullptr;
    }
    printf("Cannot find texture file: %s\n", filePath);
    return nullptr;
}