#include "console.hpp"
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::toupper;

namespace io {
    
    string ToUpperString(string word) {
        for(char& c : word) {
            toupper(c);
        }
        return word;
    }
    string GetDifficulty() {
        string difficulty;
        cin >> difficulty;
        ToUpperString(difficulty);
        return difficulty;
    }

    string GetSecretWord() {
        string word;
        cin >> word;
        ToUpperString(word);
        return word;
    }

    char GetPlayerGuess() {
        char guess;
        cin >> guess;
        toupper(guess);
        return guess;
    }

    void PrintGameStart() {
        cout << "Hangman" << endl << "_______" << endl << endl;
    }

    void PrintMistakesClueWrong(int mistakes, int mistakesLeft, string clue, string wrongLetters) {
        cout << "Mistakes: " << mistakes << "/" << mistakesLeft << endl << "Clue:     " << clue << endl;
        if (!wrongLetters.empty()) {
            cout << "Wrong:     " << wrongLetters << endl << endl;
        }
    }
    
    void PrintGuess(char guess) {
        cout << "Guess: " << toupper(guess) << endl << endl;
    }

    void PrintWin(string word) {
        cout << "You won!" << endl << "The word was: " << word;
    }

    void PrintLoss(string word) {
      cout << "You lost." << endl << "The word was: " << word;
    }
}