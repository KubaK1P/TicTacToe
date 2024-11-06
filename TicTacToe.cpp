#include "TicTacToe.h"
#include <cstdlib>
#include <ctime>

TicTacToe::TicTacToe() : board(3, std::vector<char>(3, ' ')) {
    std::srand(static_cast<unsigned int>(std::time(0)));  // Inicjalizacja generatora liczb pseudolosowych
}

void TicTacToe::displayBoard() const {
    for (const auto& row : board) {
        for (char cell : row) {
            std::cout << (cell == ' ' ? '.' : cell) << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

bool TicTacToe::makeMove(int player, int row, int col) {
    if (isMoveValid(row, col)) {
        board[row][col] = getSymbol(player);
        return true;
    }
    return false;
}

bool TicTacToe::isWinner(int player) const {
    char symbol = getSymbol(player);
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) ||  // Wiersze
            (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)) {  // Kolumny
            return true;
        }
    }
    return (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||  // Przekątna 1
           (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol);    // Przekątna 2
}

bool TicTacToe::isDraw() const {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') return false;
        }
    }
    return true;
}

void TicTacToe::computerMove() {
    int row, col;
    do {
        row = std::rand() % 3;
        col = std::rand() % 3;
    } while (!isMoveValid(row, col));
    board[row][col] = getSymbol(2);
}

char TicTacToe::getSymbol(int player) const {
    return player == 1 ? 'X' : 'O';
}

bool TicTacToe::isMoveValid(int row, int col) const {
    return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ';
}
