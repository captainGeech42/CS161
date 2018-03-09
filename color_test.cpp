#include <iostream>
#include <stdio.h>

#define SIZE 8

using namespace std;

/* box
    ╭───╮
    │   │
    ╰───╯
*/

struct piece {
    
}



int main() {
    char** board;
    init_board(&board);

    printf("%c\n", board[SIZE-1][SIZE-1]);

    // cout << "|\033[30;47m "  << "X" << endl;

    for (int i = 0; i < SIZE; i++) {
        delete[] board[i];
    }
    delete[] board;
    return 0;
}