#include <cstdlib>				// system definitions
#include <iostream>				// I/O definitions

using namespace std;				// make std:: accessible

const int X = 1, O = -1, EMPTY = 0;		// possible marks
int board[3][3];				// playing board
int currentPlayer;				// current player (X or O)
char restart = 'y';

void printBoard();
void clearBoard();
void putMark(int i, int j);
bool isWin(int mark);
bool isTie();

int main(){
    clearBoard();
    int row, col;
    cout << "Instructions: Rows from top to bottom are 1, 2, 3 and columns from left to right are 1, 2, 3." << endl;
    cout << "\t      When prompted enter the row and column seperated by a space. ex: 1 1\n\n";
    while(restart == 'y'){
        while(!isWin(X) && !isWin(O) && !isTie()){
            if(currentPlayer == X){
                cout << "X's turn." << endl;
                cout << "Please input the row then column of your pick." << endl;
                cin >> row >> col;
                if((row > 0 && row < 4) && (col > 0 && col < 4) && (board[row-1][col-1] == 0)){
                    putMark(row-1, col-1);
                    printBoard();
                }else{
                    cout << "\nError: invalid row or column. Input again.\n\n";
                }
            }else{
                cout << "O's turn." << endl;
                putMark(0, 0);
                printBoard();
            }
        }
        cout << "Would you like to play again? (y/n)\n";
        cin >> restart;
        if(restart == 'y'){
            clearBoard();
        }
    }
}

void printBoard(){
    cout << "\n---------------\n";
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << "|";
            if(board[i][j] == X){
                cout << " X ";
            }else if(board[i][j] == O){
                cout << " O ";
            }else cout << "   ";
            cout << "|";
        }
        cout << "\n---------------\n";
    }
    cout << "\n";
}

void clearBoard() {				// clear the board
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = EMPTY;			// every cell is empty
    currentPlayer = X;				// player X starts
}

void putMark(int i, int j) {			// mark row i column j
    board[i][j] = currentPlayer;		// mark with current player
    currentPlayer = -currentPlayer;		// switch players
}

bool isWin(int mark) {			// is mark the winner?
    int win = 3*mark;				// +3 for X and -3 for O
    return ((board[0][0] + board[0][1] + board[0][2] == win)	    // row 0
    	 || (board[1][0] + board[1][1] + board[1][2] == win)	    // row 1
    	 || (board[2][0] + board[2][1] + board[2][2] == win)	    // row 2
    	 || (board[0][0] + board[1][0] + board[2][0] == win)	    // column 0
    	 || (board[0][1] + board[1][1] + board[2][1] == win)	    // column 1
    	 || (board[0][2] + board[1][2] + board[2][2] == win)	    // column 2
    	 || (board[0][0] + board[1][1] + board[2][2] == win)	    // diagonal
    	 || (board[2][0] + board[1][1] + board[0][2] == win));	    // diagonal
}

bool isTie(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == EMPTY){
                return false;
            }
        }
    }
    return true;
}