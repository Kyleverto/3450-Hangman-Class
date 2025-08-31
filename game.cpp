#include "console.hpp"
#include "game.hpp"

namespace hangman {
    void PlayGame() {
        io::PrintGameStart();
        string difficulty = io::GetDifficulty();
        string secretWord = io::GetSecretWord();

    }

}