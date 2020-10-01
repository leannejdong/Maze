/*
 * The Maze class represents a 2D maze contained in a rectangular
 * grid of squares. The maze is read in from a data file in which the character
 * '+', '-' and '|' represent corners, horizontal walls, vertical walls, resp;
 * space represent open passageway squares.
 * The start position is indicated by the character 'S'. For example, the following
 * data file defines a simple maze:
 * +-+-+-+-+-+
 * |     |
 * + +-+ + +-+
 * |S  |     |
 * +-+-+-+-+-+
 * In most other implementations, Recursion uses a call stack to keep the store
 * each recursive call and then pop as the function ends.
 * Here, we will take an iterative approach by creating our own stack
 * Algorithm
 * Push starting Location onto stack
 * while the stack isn't empty and we are not at the end:
 *      Pop stack to get current location
 *      While we haven't tried every possible direction:
 *          Let Step be the Location from Current in the next direction.
 *          If Step is the end cell:
 *              Push Step onto the stack.
 *              Quit.
 *          Else If Step hasn't been visited and it is not a Wall:
 *              Mark Step as visited
 *              Rotate the direction at Current ( in case we back up).
 *              Push Current onto the stack (so we can back up).
 *              Set Current to Step.
 *          Else
 *              Rotate the direction at Current
 *      EndWhile
 * EndWhile
 */
#include <string>
#include <array>
#include <stack>
using namespace std;
using std::array;

constexpr int N = 4;
constexpr int M = 5;

#ifndef MAZE_MAZE_H
#define MAZE_MAZE_H

//class Maze {
//private:
//    bool amIaWall;
//    bool beenVisited;
//};

struct node {
    int x, y, dir;

    node(int i, int j)
    {
        x = i;
        y = j;

        // set initial direction to 0
        dir = 0;
    }
};

int n = N, m = M;

// Coordinates of food
int fx, fy;
array<array<bool, M>, N> visited;

bool isReachable(array<array<int, M>, N> &maze)
{
    // Initially starting at (0, 0).
    int i = 0, j = 0;

    stack<node> s;

    node temp(i, j);

    s.push(temp);

    while (!s.empty()) {

        // Pop the top node and move to the
        // left, right, top, down or retract
        // back according the value of node's
        // dir variable.
        temp = s.top();
        int d = temp.dir;
        i = temp.x, j = temp.y;

        // Increment the direction and
        // push the node in the stack again.
        temp.dir++;
        s.pop();
        s.push(temp);

        // If we reach the Food coordinates
        // return true
        if (i == fx and j == fy) {
            return true;
        }

        // Checking the Up direction.
        if (d == 0) {
            if (i - 1 >= 0 and maze[i - 1][j] and
                visited[i - 1][j]) {
                node temp1(i - 1, j);
                visited[i - 1][j] = false;
                s.push(temp1);
            }
        }

            // Checking the left direction
        else if (d == 1) {
            if (j - 1 >= 0 and maze[i][j - 1] and
                visited[i][j - 1]) {
                node temp1(i, j - 1);
                visited[i][j - 1] = false;
                s.push(temp1);
            }
        }

            // Checking the down direction
        else if (d == 2) {
            if (i + 1 < n and maze[i + 1][j] and
                visited[i + 1][j]) {
                node temp1(i + 1, j);
                visited[i + 1][j] = false;
                s.push(temp1);
            }
        }
            // Checking the right direction
        else if (d == 3) {
            if (j + 1 < m and maze[i][j + 1] and
                visited[i][j + 1]) {
                node temp1(i, j + 1);
                visited[i][j + 1] = false;
                s.push(temp1);
            }
        }

            // If none of the direction can take
            // the rat to the Food, retract back
            // to the path where the rat came from.
        else {
            visited[temp.x][temp.y] = true;
            s.pop();
        }
    }

    // If the stack is empty and
    // no path is found return false.
    return false;
}
#endif //MAZE_MAZE_H
