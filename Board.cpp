//
// Created by Dru on 2/27/2024.
//

#include "Board.h"

// Board constructor initializes the game board with empty spaces.
Board::Board() {
    grid.resize(ROWS, std::vector<char>(COLS, ' '));
}

// Displays the current state of the board along with the player's guesses.
void Board::display(const std::vector<std::string>& guesses) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << "| " << grid[i][j] << " ";
        }
        if (i < guesses.size()) {
            std::cout << "| " << guesses[i];
        }
        std::cout << "\n";
    }
    std::cout << "-----------------------------\n";
}

// Updates the board with feedback for the current guess compared to the secret word.
void Board::updateBoard(std::string word, int turn_num, std::string secret)
{
    int row_input = turn_num - 1;
    const char* input = word.c_str(); // Convert to cstring to compare
    const char* secretWord = secret.c_str();

    for(int j = 0; j < COLS; j++)
    {
        // Check if the letter is correct and in the correct position.
        if (input[j] == secretWord[j])
            grid[row_input][j] = input[j];
        // checks if letter exits in the word
        else
        {
            char letter = input[j];
            size_t found = secret.find(letter);

            // Mark the letter as present in the wrong position or not present at all.
            if (found != -1)
            {
                grid[row_input][j] = '*';
            }
            else
                grid[row_input][j] = 'X';
        }
    }
}
