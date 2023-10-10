#include <iostream>
#include <cstring>
using namespace std;

template<int Rows>
struct nQueensPuzzle {
    // the column of the queen in a given row
    int queensInRow[Rows];
    bool canPlaceQueen(int k, int i) {
        for (int j = 0; j < k; j++) {
            if ((queensInRow[j] == i) || abs(queensInRow[j] - i) == abs(j-k)) return false;
        }
        return true;
    }
    void queensConfiguration(int k) {
        for (int i = 0; i < Rows; i++) {
            if (canPlaceQueen(k, i)) {
                queensInRow[k] = i;
                if (k == Rows -1) printConfiguration();
                else queensConfiguration(k+1);
            }
        }
    }
    void printConfiguration() {
        char board[Rows][Rows+1];
        memset(board, '~', sizeof(board));
        for (int row = 0; row < Rows; row++) {
            board[row][queensInRow[row]] = 'Q';
            board[row][Rows] = '\n';
        }
        cout << endl;
        cout.write((char*)board, sizeof(board));
        cout << endl;
    }
};

int main(int argc, char **argv) {
    nQueensPuzzle<5> puzzle;
    puzzle.queensConfiguration(0);
}