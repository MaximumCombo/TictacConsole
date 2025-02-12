#pragma once
#include <array>

enum Mode {
	INIT,
	PLAYING
};

class Game {
private:
	std::array<char, 9> banmen{ '.', '.', '.', '.', '.', '.', '.', '.', '.' };

	bool running = false;

	char player = '\0';
	char turn = 'O';

	Mode cur_mode = INIT;

	void PrintCmd();
	void SetCmd();
	void ExitCmd();
	void CheckCmd();
	void ClearCmd();
	void PlayCmd();
	void PlaceCmd(int);

	char WinCheck();


public:
	void Init();
	void MainLoop();
	bool IsRunning();
};