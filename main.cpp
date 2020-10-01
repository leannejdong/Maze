#include "Maze.h"
#include <iostream>

int main()
{
    // Initially setting the visited
    // array to true (unvisited)
    for (auto &row : visited) {
        row.fill(true);
    }

    // Maze matrix
    array<array<int, M>, N> maze = {{
                                            { 1, 0, 1, 1, 0 },
                                            { 1, 1, 1, 0, 1 },
                                            { 0, 1, 0, 1, 1 },
                                            { 1, 1, 1, 1, 1 }
                                    }};

    // Food coordinates
    fx = 2;
    fy = 3;

    if (isReachable(maze)) {
        cout << "Path Found!" << '\n';
    }
    else
        cout << "No Path Found!" << '\n';

    return 0;
}