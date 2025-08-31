#include "console.hpp"
#include "game.hpp"
#include "state.hpp"
#include <string>

using std::string;

namespace hangman {
    void PlayGame() {
        io::PrintGameStart();
        string difficulty = io::GetDifficulty();
        string secretWord = io::GetSecretWord();

    }

}