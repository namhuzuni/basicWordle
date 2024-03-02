//
// Created by Dru on 2/27/2024.
//

#ifndef WORDLE_PLAYER_H
#define WORDLE_PLAYER_H

#include <string>
#include <iostream>

#include "Board.h"
#include "WordBank.h"

class Player {
public:
    Player();
    std::string getUserInput(WordBank& wordBank);
    std::vector<std::string> getGuesses() const { return guesses; }

private:
    std::string userInput;
    Board board;
    WordBank secret;
    std::vector<std::string> guesses;
};


#endif //WORDLE_PLAYER_H
