#include "Headers/Game.h"

int main()
{
	Game game;

	game.Init();
	while (game.IsRunning()) {
		game.MainLoop();
	}
}