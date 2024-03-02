//
// Created by Nam Nguyen on 2/27/24.
//

#ifndef WORDLE_GAME_H
#define WORDLE_GAME_H

#include <iostream>
#include "Player.h"
#include "Board.h"
#include <string>

class Game {
public:
    Game();
    void playGame(Player& player, Board& board, WordBank& wordBank);
    void checkWin(Player& player, WordBank& wordBank, bool winCondition, int turn);
    bool checkWinConditon(Player& player, Board& board, std::string guess, std::string& secretWord);
    void rules();

private:
    std::string guesses;
};


#endif //WORDLE_GAME_H
