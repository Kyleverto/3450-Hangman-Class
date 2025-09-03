# - Kyle Vertodoulos

## 3450 Hangman Project

- This is a game of hangman where you select a difficulty easy, regular, or hard. Then you type a secret word and guess letters to find out the "secret" word.

- I was getting many errors with the linker so I asked chatgpt why it could be happening and it helped me figure out that it was due to an outdated binary build with CMake.

- I had a hard time figuring out how to use CMake because I did not realize that you needed to rebuild the binary file for VSCode.

- I feel like I defined the Game class fairly well, I made good use of helper functions and named everything so the functions are more readable. I also think I did a good job of making this completely modular with minimal dependancies.
