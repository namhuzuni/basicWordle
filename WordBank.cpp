//
// Created by Dru on 2/27/2024.
//

#include "WordBank.h"

//Initializes the word bank by loading words from "WordBank.txt" into the wordList vector.
WordBank::WordBank()
{
    srand(time(0));

    std::ifstream file("WordBank.txt");
    std::string word;
    while (file >> word){
        wordList.push_back(word);
    }
}

// Returns a random word from the word list.
std::string WordBank::getRandomWord() {
    if (wordList.empty()) return "";
    int randomIndex = rand() % wordList.size();
    secretWord = wordList[randomIndex];
    return secretWord;
}

// Returns secret word.
std::string WordBank::getSecretWord() const{
    return secretWord;
}

// Checks if a given word is present in the word list, returning true if it is valid.
bool WordBank::checkValidWord(const std::string &input) const {
    auto it = std::find(wordList.begin(), wordList.end(), input);
    return it != wordList.end();
}
