//
// Created by Dru on 2/27/2024.
//

#include "Player.h"

// Constructor for the Player class.
Player::Player(){
}

// Requests and validates a 5-letter word from the user until a valid word is entered.
// Valid words are checked against the word bank, and valid guesses are stored.
std::string Player::getUserInput(WordBank& wordBank) {
    std::string userInput;
    bool valid = false;

    while(!valid) {
        std::cout << "Enter a 5 letter word\n";
        std::cin >> userInput;
        valid = wordBank.checkValidWord(userInput);

        if (valid) {
            guesses.push_back(userInput); //Add user input to guesses
        } else {
            std::cout << "Word is not valid, type again:\n";
        }
    }
    return userInput;
}

