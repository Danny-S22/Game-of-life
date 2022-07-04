# Game-of-life

This Conway's Game of Life programmed in C.

The Game of Life was created by John Conway in 1970's for a cellular automaton simulation. The game played on a two dimentional grid and each box of the grid represents a cell which can be either dead or alive. Once the initial positions of living cells set, the board evolves to the next generation using following rules:

- An alive cell with 1 or less alive neighbours will die (under population/loneliness)
- An alive cell with 4 or more alive neighbours will die (overpopulation)
- An alive cell with 2 or 3 neighbours will suvive to the next generation.
- A dead cell with exactly 3 alive nieghbours will be alive on the next generation (reproduction)
