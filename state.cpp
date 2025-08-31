#include "state.hpp"
#include <string>
#include <algorithm>
using std::string;

namespace hangman {
    
    string ToUpperString(string word) {
        for(char& letter : word) {
            toupper(letter);
        }
        return word;
    }
    class Game {
        public:

        void InitGame(string difficulty, string secretWord) {
            SetDifficulty(difficulty);
            SetSecretWord(secretWord);
        }

        void MakeGuess(char guess) {
            if(HasLetterBeenGuessed(guess) == true) {
                if(currentDifficulty != Difficulty::easy) {
                    mistakes++;
                }
                return;
            }
            else {
                AddGuess(guess);
                if(IsLetterInWord(guess) == true) {
                    for (int i = 0; i < secretWord.length(); ++i) {
                        if (secretWord[i] == guess) {
                            clue[i] = guess;
                        }
                    }
                }
                else {
                    AddWrongGuess(guess);
                    mistakes++;
                }
            }
        }


        bool HasLetterBeenGuessed(char currentGuess) {
            for(char& guessed : guesses) {
                if(currentGuess == guessed) {
                    return true;
                }
            }
            return false;
        }

        string GetWrongGuesses() {
            return wrongGuesses;
        }


        private:
        string secretWord;
        Difficulty currentDifficulty;
        string guesses;
        int mistakes;
        int mistakesToLose;
        string clue;
        string wrongGuesses;

        Difficulty toEnum(string difficulty) {
            string upper = ToUpperString(difficulty);
            if (upper == "EASY") 
                return Difficulty::easy;

            if (upper == "REGULAR") 
                return Difficulty::regular;

            if (upper == "HARD") 
                return Difficulty::hard;
        }

        void AddGuess(char guess) {
            guesses.push_back(guess);
        }

        void AddWrongGuess(char guess) {
            wrongGuesses.push_back(guess);
            std::sort(wrongGuesses.begin(), wrongGuesses.end());
        }

        void SetDifficulty(string difficulty) {
            currentDifficulty = toEnum(difficulty);
            if (currentDifficulty == Difficulty::easy || currentDifficulty == Difficulty::regular) {
                mistakesToLose = 9;
            }
            else {
                mistakesToLose = 6;
            }
        }

        void SetSecretWord(string word) {
            secretWord = word;
            clue.resize(word.length(), '_');
        }

        bool IsLetterInWord(char guess) {
            for(char& letter : secretWord) {
                if(guess == letter) {
                    return true;
                }
            }
            return false;
        }
        
    };

}
