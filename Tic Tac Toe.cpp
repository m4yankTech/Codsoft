#include <iostream>
#include <vector>

// Function prototypes
void displayBoard(const std::vector<std::vector<char> >& board);
bool isMoveValid(const std::vector<std::vector<char> >& board, int row, int col);
bool checkWin(const std::vector<std::vector<char> >& board, char player);
bool checkDraw(const std::vector<std::vector<char> >& board);
void switchPlayer(char& currentPlayer);

int main() {
    std::vector<std::vector<char> > board(3, std::vector<char>(3, ' '));
    char currentPlayer = 'X';
    bool gameWon = false;
    bool gameDraw = false;

    while (true) {
        displayBoard(board);
        int row, col;
        std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        std::cin >> row >> col;

        while (!isMoveValid(board, row, col)) {
            std::cout << "Invalid move. Try again: ";
            std::cin >> row >> col;
        }

        board[row][col] = currentPlayer;
        gameWon = checkWin(board, currentPlayer);
        gameDraw = checkDraw(board);

        if (gameWon) {
            displayBoard(board);
            std::cout << "Player " << currentPlayer << " wins!" << std::endl;
            break;
        } else if (gameDraw) {
            displayBoard(board);
            std::cout << "The game is a draw!" << std::endl;
            break;
        }

        switchPlayer(currentPlayer);
    }

    return 0;
}

void displayBoard(const std::vector<std::vector<char> >& board) {
    std::cout << "Current board state:" << std::endl;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            std::cout << (board[i][j] == ' ' ? '.' : board[i][j]) << ' ';
        }
        std::cout << std::endl;
    }
}

bool isMoveValid(const std::vector<std::vector<char> >& board, int row, int col) {
    return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ';
}

bool checkWin(const std::vector<std::vector<char> >& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

bool checkDraw(const std::vector<std::vector<char> >& board) {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

void switchPlayer(char& currentPlayer) {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

