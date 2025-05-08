#include <iostream>
#include <vector>

using namespace std;

void displayBoard(const vector<char>& board) {
    cout << board[0] << board[1] << board[2] << endl;
    cout << board[3] << board[4] << board[5] << endl;
    cout << board[6] << board[7] << board[8] << endl;
}

bool isWinner(const vector<char>& board, char player) {
    // Winning combinations
    int wins[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // cols
        {0, 4, 8}, {2, 4, 6}             // diagonals
    };
    for (auto& win : wins) {
        if (board[win[0]] == player &&
            board[win[1]] == player &&
            board[win[2]] == player)
            return true;
    }
    return false;
}

bool isDraw(const vector<char>& board) {
    for (char c : board) {
        if (c != 'X' && c != 'O') return false;
    }
    return true;
}

int main() {
    vector<char> board = { '1','2','3','4','5','6','7','8','9' };
    char currentPlayer = 'X';
    int move;

    while (true) {
        displayBoard(board);
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        // Validate move
        if (move < 1 || move > 9 || board[move - 1] == 'X' || board[move - 1] == 'O') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        board[move - 1] = currentPlayer;

        if (isWinner(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }
        else if (isDraw(board)) {
            displayBoard(board);
            cout << "draw" << endl;
            break;
        }

        // Switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
