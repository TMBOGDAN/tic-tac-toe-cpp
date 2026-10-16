# Tic Tac Toe (C++)

A two-player console exercise on a 3×3 board. It accepts a row, column, and symbol from the terminal, reports a win or draw, tracks round scores, and offers a replay prompt in Romanian.

## Run

```sh
g++ -std=c++17 -Wall -Wextra tictactoe.cpp -o tictactoe
./tictactoe
```

Enter row and column values from 1 to 3. The program then asks for the symbol to place; the intended players are `x` and `0` (zero). At the end of a round, type `da` to replay. There are no external dependencies or automated tests.

## Structure

`tictactoe.cpp` contains the board display, winner/draw checks, score display helper, round loop, and `main`.

## Known limitations

Input is not validated before indexing the board, so coordinates outside 1–3 are unsafe. The game asks users to enter a symbol on every move instead of enforcing alternating turns. A full board is checked for a draw before reporting a win on the last move, and replay uses recursion. This is a learning exercise rather than a hardened game.

## Next steps

Validate input, manage turns internally, evaluate wins before draws, and use a loop for replay.
