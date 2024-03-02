//
// Created by Nam Nguyen on 2/27/24.
//

#include "Game.h"

// Constructor initializes the game by creating player, board, and word bank objects,
// and then starting the gameplay loop.
Game::Game() {
    Player player;
    Board board;
    WordBank wordBank;
    wordBank.getRandomWord();
    playGame(player, board, wordBank);
};

// The main gameplay loop. Runs through turns, accepting guesses from the player,
// checking win conditions, and updating the board accordingly
void Game::playGame(Player& player, Board& board, WordBank& wordBank) {
    bool winCondition = false;
    rules();
    std::string secretWord = wordBank.getSecretWord();

    for (int turn = 0; turn < 6 && !winCondition; ++turn) {
        std::string guess = player.getUserInput(wordBank);
        winCondition = checkWinConditon(player, board, guess, secretWord);
        board.updateBoard(guess, turn + 1, secretWord);
        board.display(player.getGuesses());

        checkWin(player,wordBank,winCondition,turn);
    }
}

// Checks if the player's guess matches the secret word.
bool Game::checkWinConditon(Player& player, Board& board, std::string guess, std::string& secretWord) {
    return guess == secretWord;
}

// Displays the outcome of the game based on the win condition and current turn.
void Game::checkWin(Player& player, WordBank& wordBank, bool winCondition, int turn) {
    if (!winCondition && turn == 5) {
        std::cout << "You Lose: The word is: " << wordBank.getSecretWord() << std::endl;
        return;
    }
    if (winCondition){
        std::cout << "You guessed the right word! The word is: " << wordBank.getSecretWord() << std::endl;
        return;
    } else{
        std::cout << "Total Turns: " << 6 - (turn + 1) << std::endl;
    }

}

// Displays the rules of the game at the beginning.
void Game::rules() {
    std::cout << "Welcome to Wordle - the game where you guess a 5-letter word.\n\n"
              << "Here's how to interpret the feedback symbols:\n"
              << "  - An 'X' indicates that a letter is not in the word at all.\n"
              << "  - A '*' signifies that a letter is in the word but in the wrong position.\n\n"
              << "Use these clues to guess the word within six tries. Good luck!\n";
}
