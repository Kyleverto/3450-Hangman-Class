#pragma once
#include "difficulty.hpp"
#include <string>
namespace io {

        void PrintGameStart();
        void PrintGameStatus(int mistakes, int mistakesToLose, std::string clue, std::string wrongGuesses = "");
        void PrintGuess(char guess);
        void PrintWin(std::string word);
        void PrintLoss(std::string word);
        Difficulty toEnum(std::string difficulty);
        Difficulty GetDifficulty();
        std::string GetSecretWord();
        char GetPlayerGuess();
    }


