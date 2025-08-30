#include <iostream>
#include "console.hpp"

void PlayGame() {
    io::PrintGameStart();
    string difficulty = io::GetDifficulty();
    string secretWord = io::GetSecretWord();


    

}

int main(){
    try {
        PlayGame();
    }
    catch (std::exception& error) {
        std::cerr << "ERROR: " << error.what() << std::endl;
    }
}
