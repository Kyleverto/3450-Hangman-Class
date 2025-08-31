#pragma once
#include <string>
using std::string;
namespace io {

        void PrintGameStart();
        void PrintMistakesClueWrong(int mistakes, int mistakesToLose, string clue, string wrongGuesses);
        void PrintGuess(char guess);
        void PrintWin(string word);
        void PrintLoss(string word);
        string GetDifficulty();
        string GetSecretWord();
        char GetPlayerGuess();
    }


