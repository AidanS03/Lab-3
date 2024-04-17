#include <cstdlib>				// system definitions
#include <iostream>				// I/O definitions
#include "AI_Tree.h"

using namespace std;				// make std:: accessible

const int X = 1, O = -1, EMPTY = 0;		// possible marks
int board[3][3];				// playing board
int currentPlayer;				// current player (X or O)
char restart = 'y';

//game functions
void printBoard();
void clearBoard();
void putMark(int i, int j);
bool isWin(int mark);
bool isTie();

//AI functions
RowCol findBestMove(int board[3][3]);
int minimax(int board[3][3], int depth, int mark);

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
                RowCol nextMove = findBestMove(board);
                row = nextMove.row;
                col = nextMove.col;
                putMark(row, col);
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

RowCol findBestMove(int board[3][3]){
   int bestScore = 9999; //variable to save best possible score
   RowCol bestRowCol; //object to hold the best row and column option
   bestRowCol.row = -1; //initalize row and col
   bestRowCol.col = -1; 

   for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == EMPTY){
                board[i][j] = O; // add potential move to the board
                int moveScore = minimax(board, 0 , X); //find best score for this move
                board[i][j] = EMPTY; //undo the tested move

                if(moveScore < bestScore){
                    bestRowCol.row = i;//sets new best row col and best score to be tested against future possible moves
                    bestRowCol.col = j;
                    bestScore = moveScore;
                }
            }
        }
   }

   return bestRowCol;
}

int minimax(int board[3][3], int depth, int mark){
    if(isWin(X)){ //if X won return its value
        return 1;
    }

    if(isWin(O)){//if O won return O's value
        return -1;
    }

    if(isTie()){//if tied return a 0
        return 0;
    }

    if(mark == X){//if it is X's turn
        int best = -9999; //initialize a local best score
        for(int i = 0; i < 3; i++){//move through the game board
            for(int j = 0; j < 3; j++){
                if(board[i][j] == EMPTY){
                    board[i][j] = X; // add potential move to the board
                    best = max(best, minimax(board, depth+1 , O)); //recurssivly call minimax to find best score for this move and compare it to the current best
                    board[i][j] = EMPTY; //undo the tested move
                }
            }
        }
        return best;
    }else{//O's turn
        int best = 9999;
        for(int i = 0; i < 3; i++){//move through the game board
            for(int j = 0; j < 3; j++){
                if(board[i][j] == EMPTY){
                    board[i][j] = O; // add potential move to the board
                    best = min(best, minimax(board, depth+1 , X)); //recurssivly call minimax to find best score for this move and compare it to the current best
                    board[i][j] = EMPTY; //undo the tested move
                }
            }
        }
        return best;
    }
}