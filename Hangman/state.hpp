#pragma once
#include <string>
#include "difficulty.hpp"

namespace hangman {
    class Game {
        public:
        Game();
        bool winner;
        void SetWinner(bool state);
        void InitGame(Difficulty difficulty, std::string secretWord);
        void MakeGuess(char guess);
        bool IsLetterInWord(char guess);
        int GetMistakes();
        int GetMistakesToLose();
        std::string GetClue();
        std::string GetWrongGuesses();
        bool IsGameDone();


    private:
        std::string secretWord;
        Difficulty currentDifficulty;
        std::string guesses;
        int mistakes;
        int mistakesToLose;
        std::string clue;
        std::string wrongGuesses;
        void AddGuess(char guess);
        void AddWrongGuess(char guess);
        void SetDifficulty(Difficulty difficulty);
        void SetSecretWord(std::string word);
        bool HasLetterBeenGuessed(char currentGuess);
    };
}