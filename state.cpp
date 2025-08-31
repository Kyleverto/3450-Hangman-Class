#include "state.hpp"
#include <string>
using std::string;

namespace hangman {
    
    string ToUpperString(string word) {
        for(char& letter : word) {
            toupper(letter);
        }
        return word;
    }
    class Game {
        
        bool IsLetterInWord(char guess, string secretWord) {
                for(char& letter : secretWord) {
                    if(guess == letter) {
                        return true;
                    }
                }
                return false;
            }
        bool HasLetterBeenGuessed(char currentGuess, string alreadyGuessed) {
            for(char& guessed : alreadyGuessed) {
                if(currentGuess == guessed) {
                    return true;
                }
            }
            return false;
        }
        string GetGuesses() {
            return guesses;
        }

        void AddGuess(char guess) {
            guesses.push_back(guess);
        }
        
        void SetDifficulty(string difficulty) {
            currentDifficulty = toEnum(difficulty);
        }

        private:
            string guesses;
            Difficulty currentDifficulty;
            int mistakes;
            int mistakesLeft;
            string clue;
            string wrongLetters;

            Difficulty toEnum(string difficulty) {
                string upper = ToUpperString(difficulty);
                if (upper == "EASY") 
                    return Difficulty::easy;

                if (upper == "MEDIUM") 
                    return Difficulty::medium;

                if (upper == "HARD") 
                    return Difficulty::hard;
            }

    };

}
