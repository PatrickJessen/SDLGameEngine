#include "CharacterSelection.h"

CharacterSelection::CharacterSelection(MainWindow* window)
{
	this->window = window;
	sprite = new Sprite("Assets/SelectScreen/SelectScreen.png", window);
}

void CharacterSelection::Draw(MainWindow* window)
{
	destRect = { 0,0,900,700 };

	SDL_RenderCopyEx(window->GetRender(), sprite->tex, &srcRect, &destRect, 0, 0, SDL_FLIP_NONE);

	SDL_SetRenderDrawColor(window->GetRender(), 255, 0, 0, 0);
	SDL_RenderDrawRect(window->GetRender(), &sorcRect);
}
