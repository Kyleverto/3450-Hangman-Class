#include "state.hpp"
#include "difficulty.hpp"
#include <string>
#include <algorithm>
using std::string;

namespace hangman {

    Game::Game()
    : winner(false), mistakes(0), mistakesToLose(0), secretWord(""), guesses(""), clue(""), wrongGuesses(""), currentDifficulty(Difficulty::easy){}


    void Game::SetWinner(bool state) {
        winner = state;
    }

    void Game::InitGame(Difficulty difficulty, string secretWord) {
        SetDifficulty(difficulty);
        SetSecretWord(secretWord);
    }

    void Game::MakeGuess(char guess) {
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

    int Game::GetMistakes() {
        return mistakes;
    }

    int Game::GetMistakesToLose() {
        return mistakesToLose;
    }

    string Game::GetClue() {
        return clue;
    }

    string Game::GetWrongGuesses() {
        return wrongGuesses;
    }

    bool Game::IsGameDone() {
        if(mistakes >= mistakesToLose) {
            SetWinner(false);
            return true;
        }
        if(clue == secretWord) {
            SetWinner(true);
            return true;
        }
        return false;
    }

    void Game::AddGuess(char guess) {
        guesses.push_back(guess);
    }

    void Game::AddWrongGuess(char guess) {
        wrongGuesses.push_back(guess);
        std::sort(wrongGuesses.begin(), wrongGuesses.end());
    }

    void Game::SetDifficulty(Difficulty currentDifficulty) {
        if (currentDifficulty == Difficulty::easy || currentDifficulty == Difficulty::regular) {
            mistakesToLose = 9;
        }
        else {
            mistakesToLose = 6;
        }
    }

    void Game::SetSecretWord(string word) {
        secretWord = word;
        clue.resize(word.length(), '_');
    }

    bool Game::IsLetterInWord(char guess) {
        for(char& letter : secretWord) {
            if(guess == letter) {
                return true;
            }
        }
        return false;
    }

    bool Game::HasLetterBeenGuessed(char currentGuess) {
        for(char& guessed : guesses) {
            if(currentGuess == guessed) {
                return true;
            }
        }
        return false;
    }

}
