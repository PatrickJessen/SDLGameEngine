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
	SDL_RenderDrawRect(window->GetRender(), &palaRect);
	SDL_RenderDrawRect(window->GetRender(), &barbRect);
}

void CharacterSelection::Update()
{
	if (Input::MousePressed(MouseButton::LEFT) && menu == true)
	{
		if (XYInRect(sorcRect, Input::MouseX(), Input::MouseY()))
		{
			pick = sorc;
			menu = false;
		}
		else if (XYInRect(palaRect, Input::MouseX(), Input::MouseY()))
		{
			pick = pala;
			menu = false;
		}
		else if (XYInRect(barbRect, Input::MouseX(), Input::MouseY()))
		{
			pick = barb;
			menu = false;
		}
	}
}

bool CharacterSelection::XYInRect(const SDL_Rect& rect, int x, int y)
{
	return ((x >= rect.x && x <= rect.x + rect.w) && (y >= rect.y && y <= rect.y + rect.h));
}
