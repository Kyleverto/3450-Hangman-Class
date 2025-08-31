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
        for(char& letter : word) {
            letter = toupper(letter);
        }
        return word;
    }

    string GetDifficulty() {
        string difficulty;
        cin >> difficulty;
        string upper = ToUpperString(difficulty);
        return upper;
    }

    string GetSecretWord() {
        string word;
        cin >> word;
        word = ToUpperString(word);
        return word;
    }

    char GetPlayerGuess() {
        char guess;
        cin >> guess;
        guess = toupper(guess);
        return guess;
    }

    void PrintGameStart() {
        cout << "Hangman" << endl << "_______" << endl << endl;
    }

    void PrintGameStatus(int mistakes, int mistakesToLose, string clue, string wrongGuesses) {
        cout << "Mistakes: " << mistakes << "/" << mistakesToLose << endl << "Clue:     " << clue << endl;
        if (!wrongGuesses.empty()) {
            cout << "Wrong:    " << wrongGuesses << endl << endl;
        }
    }
    
    void PrintGuess(char guess) {
        guess = toupper(guess);
        cout << endl << "Guess: " << guess << endl << endl;
    }

    void PrintWin(string word) {
        cout << "You won!" << endl << "The word was: " << word << endl;
    }

    void PrintLoss(string word) {
      cout << "You lost." << endl << "The word was: " << word << endl;
    }
}