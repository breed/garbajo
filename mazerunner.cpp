#include <iostream>
#include <stack>
using namespace std;

enum Direction { west, east, north, south};

string dir2str(Direction d) {
    switch (d) {
        case west: return "west";
        case east: return "east";
        case north: return "north";
        case south: return "south";
    }
    return "unknown";
}

// finds a path through a maze with walls has #
// and destination as X
// we assume there is a wall around the whole maze
// IOW the first/last column/row will have all #

template <int Rows>
class MazeRunner {
public:
    char maze[Rows][Rows];
    MazeRunner(string m) {
        cout << "contructing maze " << endl << m << endl;
        int row = 0;
        int col = 0;
        for (auto &c : m) {
            if (c == '\n') {
                row += 1;
                col = 0;
                continue;
            }
            if (col > Rows || row > Rows) {
                cout << "bounds exceeded " << row << ", " << col << endl;
            } else {
                maze[row][col++] = c;
            }
        }
    }
    bool findpath(int row, int column, stack<Direction> &moves) {
    }

    void printPath(int row, int column) {
        stack<Direction> moves;
        if (findpath(row, column, moves)) {
            cout << "found path from " << row << ", " << column << " to X: ";
            for (;!moves.empty(); moves.pop()) cout << dir2str(moves.top()) << " ";
            cout << endl;
        } else {
            cout << "no path from " << row << ", " << column << endl;
        }
    }
};

int main(int argc, char **argv) {
    MazeRunner<5> maze0(
            "#####\n"
            "# # #\n"
            "# # #\n"
            "# X##\n"
            "#####\n"
            );
    maze0.printPath(1, 1);
    maze0.printPath(2, 1);
    maze0.printPath(1, 2);
    maze0.printPath(1, 3);
    maze0.printPath(3, 2);

    MazeRunner<8> maze1(
            "########\n"
            "# #    #\n"
            "# #### #\n"
            "# #  # #\n"
            "# #    #\n"
            "# #  # #\n"
            "#  #  X#\n"
            "########\n");
    maze1.printPath(1,1);
    maze1.printPath(1,2);
    maze1.printPath(1,3);
    maze1.printPath(7,5);
}