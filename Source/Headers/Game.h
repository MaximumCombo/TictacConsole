#pragma once
#include <array>

enum State {
	NOT_PLAYING,
	PLAYING
};

class Game {
private:
	std::array<char, 9> banmen{ '.', '.', '.', '.', '.', '.', '.', '.', '.' };

	bool running = false;

	char player = '\0';
	char turn = 'O';

	State cur_mode = NOT_PLAYING;

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