#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer = 'X';
int xWins = 0, oWins = 0, draws = 0;

void initializeBoard() {
    char ch = '1';
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            board[i][j] = ch++;
}

void displayBoard() {
    for(int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << "\n";
        if(i < 2) cout << "---|---|---\n";
    }
}

bool equal(char a, char b, char c, char p) {
    return a == b && b == c && a == p;
}

bool checkWin() {
    for(int i = 0; i < 3; i++) {
        if(equal(board[i][0], board[i][1], board[i][2], currentPlayer)) return true; // rows
        if(equal(board[0][i], board[1][i], board[2][i], currentPlayer)) return true; // cols
    }
    if(equal(board[0][0], board[1][1], board[2][2], currentPlayer)) return true; // diagonal
    if(equal(board[0][2], board[1][1], board[2][0], currentPlayer)) return true; // anti-diagonal
    return false;
}

bool checkDraw() {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void displayResult(bool win) {
    if(win) {
        cout << "Player " << currentPlayer << " wins!\n";
        if(currentPlayer == 'X') xWins++;
        else oWins++;
    } else {
        cout << "It's a draw!\n";
        draws++;
    }
    cout << "\nScoreboard:\n";
    cout << "X wins: " << xWins << "\n";
    cout << "O wins: " << oWins << "\n";
    cout << "Draws : " << draws << "\n\n";
}

void playGame() {
    int move;
    initializeBoard();
    while(true) {
        displayBoard();
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        if(move < 1 || move > 9) {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        if(board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Cell already taken. Try again.\n";
            continue;
        }

        board[row][col] = currentPlayer;

        if(checkWin()) {
            displayBoard();
            displayResult(true);
            break;
        } else if(checkDraw()) {
            displayBoard();
            displayResult(false);
            break;
        }

        switchPlayer();
    }
}

int main() {
    char again;
    cout << " Welcome to Tic-Tac-Toe Game "<< endl;
    do {
        playGame();
        cout << "Play again? (y/n): ";
        cin >> again;
    } while(again == 'y' || again == 'Y');
    return 0;
}
