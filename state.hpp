#pragma once
#include <string>
using std::string;

namespace hangman {
    string ToUpperString(string difficulty);
     enum class Difficulty {
        easy,
        regular,
        hard
    };
    class Game {
        public:
        void InitGame(string difficulty, string secretWord);
        void MakeGuess(char Guess);
        bool HasLetterBeenGuessed(char currentGuess);
        bool IsLetterInWord(char guess);
        string GetWrongGuesses();


    private:
        string secretWord;
        string guesses;
        int mistakes;
        int mistakesLeft;
        string clue;
        string wrongGuesses;
        Difficulty currentDifficulty;
        Difficulty toEnum(string difficulty);
        void AddGuess(char guess);
        void SetDifficulty(string difficulty);
        void SetSecretWord(string word);
    };
}