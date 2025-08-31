#pragma once
#include <string>
using std::string;

namespace hangman {
    string ToUpperString(string difficulty);
     enum class Difficulty {
        easy,
        medium,
        hard
    };
    class Game {
        bool HasLetterBeenGuessed(char currentGuess, string alreadyGuessed);
        bool IsLetterInWord(char guess, string secretWord);
        string GetGuesses();
        void AddGuess(char guess);
        void SetDifficulty(string difficulty);
    private:
        string guesses;
        Difficulty currentDifficulty;
        Difficulty toEnum(string difficulty);
    };
}