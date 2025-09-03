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
        Game();
        bool winner;
        void SetWinner(bool state);
        void InitGame(string difficulty, string secretWord);
        void MakeGuess(char guess);
        bool IsLetterInWord(char guess);
        int GetMistakes();
        int GetMistakesToLose();
        string GetClue();
        string GetWrongGuesses();
        bool IsGameDone();


    private:
        string secretWord;
        Difficulty currentDifficulty;
        string guesses;
        int mistakes;
        int mistakesToLose;
        string clue;
        string wrongGuesses;
        Difficulty toEnum(string difficulty);
        void AddGuess(char guess);
        void AddWrongGuess(char guess);
        void SetDifficulty(string difficulty);
        void SetSecretWord(string word);
        bool HasLetterBeenGuessed(char currentGuess);
    };
}