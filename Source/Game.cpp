#include "Headers/Game.h"

#include <iostream>

char Enemy(char);

void Game::Init() {
    this->running = true;
}

void Game::MainLoop()
{
    
    if (cur_mode == INIT) {
        //Waiting for Input...
        std::string input;

        std::cout << "> ";
        std::cin >> input;

        if (!input.compare("print")) PrintCmd();
        else if (!input.compare("set")) SetCmd();
        else if (!input.compare("play")) PlayCmd();
        else if (!input.compare("clear")) ClearCmd();
        else if (!input.compare("exit")) ExitCmd();
        else if (!input.compare("check")) CheckCmd();
        else {
            std::cout << "\"" << input << "\"" << " is not a recognized instructuion" << std::endl;
        }
    }
    else if (cur_mode == PLAYING) {
        PrintCmd();

        char winner = WinCheck();
        if (winner) {
            std::cout << "Winner: " << winner << std::endl;
            ExitCmd();
            return;
        }

        if (this->player == this->turn) {
            std::cout << "Player's turn" << std::endl;

            //Waiting for Input...
            std::string input;

            std::cout << "> ";
            std::cin >> input;

            if (!input.compare("exit")) ExitCmd();
            else if ('0' <= input[0] && input[0] <= '8') PlaceCmd(input[0] - '0');
            else {
                std::cout << "\"" << input << "\"" << " is not a recognized instructuion" << std::endl;
            }
        }
        else {
            std::cout << "AI's turn" << std::endl;
            this->turn = Enemy(this->turn);
        }
    }

}

void Game::PrintCmd()
{
    std::cout << banmen[0] << " " << banmen[1] << " " << banmen[2] << " " << std::endl;
    std::cout << banmen[3] << " " << banmen[4] << " " << banmen[5] << " " << std::endl;
    std::cout << banmen[6] << " " << banmen[7] << " " << banmen[8] << " " << std::endl;
}

void Game::SetCmd()
{
    int pos;
    char chara;

    std::cout << "Please input posion [0-8]: ";
    while (true) {
        std::cin >> pos;
        if (0 <= pos && pos <= 8) break;
        std::cout << pos << " is not a valid number [0-8]" << std::endl;
    }

    std::cout << "Please input char: ";
    std::cin >> chara;

    banmen[pos] = chara;
    std::cout << "Pos " << pos << " has been changed to " << chara << std::endl;
}

void Game::ExitCmd()
{
    if (cur_mode == INIT) {
        std::cout << "Exiting this program..." << std::endl;
        this->running = false;
    }
    else if (cur_mode == PLAYING) {
        std::cout << "Game stopped" << std::endl;
        cur_mode = INIT;
    }
}

void Game::CheckCmd() {
    char winner = WinCheck();

    if (!winner) {
        std::cout << "No Winner" << std::endl;
        return;
    }

    std::cout << "Winner: " << winner << std::endl;
}

void Game::ClearCmd()
{
    this->banmen = { '.', '.', '.', '.', '.', '.', '.', '.', '.' };
    std::cout << "Board cleared" << std::endl;
}

void Game::PlayCmd()
{
    std::cout << "Entering to Playing Mode..." << std::endl;
    this->cur_mode = PLAYING;

    std::cout << "Please select the player 'O' or 'X': ";

    while (true)
    {
        std::cin >> this->player;
        if (this->player == 'O' || this->player == 'X') break;
        std::cout << "Only 'O' or 'X' is acceptable: ";
    }
    
    std::cout << "Player: " << this->player << std::endl;
    std::cout << "AI: " << Enemy(this->player) << std::endl;

}

void Game::PlaceCmd(int pos)
{
    if (banmen[pos] == '.') {
        banmen[pos] = this->turn;
        std::cout << "Placed " << this->turn << " on pos " << pos << std::endl;

        this->turn = Enemy(this->turn);
    }
    else std::cout << "Already occupied" << std::endl;
}


char Game::WinCheck()
{
    //Check rows
    for (size_t i = 0; i < 9; i += 3)
    {
        if (banmen[i] != '.' && banmen[i] == banmen[i + 1] && banmen[i] == banmen[i + 2]) return banmen[i];
    }

    //Check cols
    for (size_t i = 0; i < 3; i++)
    {
        if (banmen[i] != '.' && banmen[i] == banmen[i + 3] && banmen[i] == banmen[i + 6]) return banmen[i];
    }

    //Check diagnals
    if (banmen[0] != '.' && banmen[0] == banmen[4] && banmen[0] == banmen[8]) return banmen[0];
    if (banmen[2] != '.' && banmen[2] == banmen[4] && banmen[2] == banmen[6]) return banmen[2];

    return 0;
}

bool Game::IsRunning()
{
    return this->running;
}

char Enemy(char koma) {
    if (koma == 'O') return 'X';
    return 'O';
}



