#include "MainWindow.h"
#include "ActOne.h"

int main()
{
	MainWindow* window = new MainWindow("RPG GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 700, false);
	ActOne* actOne = new ActOne(window);

	while (window->Running())
	{
		actOne->Update(window);
		actOne->Draw(window);


		window->Update();
		window->Clear();
		SDL_Delay(10);
	}

	window->Clean();
}