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
        while(!isGameOver) {
            char guess = io::GetPlayerGuess();
            game.MakeGuess(guess);
        }
    }

}