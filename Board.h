//
// Created by Dru on 2/27/2024.
//

#ifndef WORDLE_BOARD_H
#define WORDLE_BOARD_H

#include <vector>
#include <string>
#include <iostream>

const int ROWS = 6;
const int COLS = 5;

class Board {
private:
    std::vector<std::vector<char>> grid; // 2D vector to represent the game board

public:
    Board();
    void display(const std::vector<std::string>& guesses);
    void updateBoard(std::string word, int turn_num, std::string secret);
};


#endif //WORDLE_BOARD_H
