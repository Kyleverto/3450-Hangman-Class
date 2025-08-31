#include "console.hpp"
#include "game.hpp"
#include "state.hpp"
#include <string>

using std::string;

namespace hangman {
    void PlayGame() {
        Game game;
        bool isGameOver;

        io::PrintGameStart();
        string difficulty = io::GetDifficulty();
        string secretWord = io::GetSecretWord();
        game.InitGame(difficulty, secretWord);

        int mistakes = game.GetMistakes();
        int mistakesToLose = game.GetMistakesToLose();
        string clue = game.GetClue();
        io::PrintGameStatus(mistakes, mistakesToLose, clue);

        while(!isGameOver) {
            char guess = io::GetPlayerGuess();
            game.MakeGuess(guess);
            io::PrintGuess(guess);

            mistakes = game.GetMistakes();
            mistakesToLose = game.GetMistakesToLose();
            clue = game.GetClue();
            string wrongGuesses = game.GetWrongGuesses();
            
            if(game.IsGameDone() == true) {
                isGameOver == true;
            }
            else {
                io::PrintGameStatus(mistakes, mistakesToLose, clue, wrongGuesses);
            }
        }
        if(game.winner == true) {
            io::PrintWin(secretWord);
        }
        else {
            io::PrintLoss(secretWord);
        }
    }

}