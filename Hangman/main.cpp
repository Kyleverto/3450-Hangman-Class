#include <iostream>
#include "game.hpp"

int main(){
    try {
        hangman::PlayGame();
    }
    catch (std::exception& error) {
        std::cerr << "ERROR: " << error.what() << std::endl;
    }
}
