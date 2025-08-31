## - Kyle Vertodoulos

- 3450 Hangman Project

- This is a game of hangman where you select a difficulty easy, regular, or hard. Then you type a secret word and guess letters to find out the "secret" word.

- I was getting many errors with the linker so I asked chatgpt why it could be happening and it helped me figure out that it was due to an outdated binary build with CMake.

- There is no type checking so only type in "easy", "regular", or "hard" for the difficulty.

- I had a hard time figuring out how to use CMake because I did not realize that you needed to rebuild the binary file for VSCode. Also for printing the game status I wanted a way to get the status in a Struct or something so I didn't have to call 4 different Game functions to call PrintGameStatus(), but I wasn't sure how to do that without creating dependancies.

- I feel like I defined the Game class fairly well, I made good use of helper functions and named everything so the functions are more readable. I also think I did a good job of making this completely modular with minimal dependancies.
