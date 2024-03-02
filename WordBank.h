//
// Created by Dru on 2/27/2024.
//

#ifndef WORDLE_WORDBANK_H
#define WORDLE_WORDBANK_H

#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <iostream>
#include <algorithm>

class WordBank {
private:
    std::vector<std::string> wordList;
    std::string secretWord;

public:
    WordBank();
    std::string getRandomWord() ;
    std::string getSecretWord() const;
    bool checkValidWord(const std::string& input) const;


};


#endif //WORDLE_WORDBANK_H
