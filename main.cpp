#include "TicTacToe.h"
#include <iostream>

int main() {
    TicTacToe game;
    int choice;
    std::cout << "Wybierz tryb gry:\n1. Gracz vs Gracz\n2. Gracz vs Komputer\n";
    std::cin >> choice;

    int row, col;
    bool playerTurn = true;

    while (true) {
        game.displayBoard();
        
        if (playerTurn || choice == 1) {
            std::cout << "Ruch gracza " << (playerTurn ? "X" : "O") << " - podaj wiersz i kolumne (0-2): ";
            std::cin >> row >> col;

            if (!game.makeMove(playerTurn ? 1 : 2, row, col)) {
                std::cout << "Niepoprawny ruch! Spróbuj ponownie.\n";
                continue;
            }
        } else {
            std::cout << "Ruch komputera:\n";
            game.computerMove();
        }

        if (game.isWinner(playerTurn ? 1 : 2)) {
            game.displayBoard();
            std::cout << "Gracz " << (playerTurn ? "X" : "O") << " wygrywa!\n";
            break;
        } else if (game.isDraw()) {
            game.displayBoard();
            std::cout << "Remis!\n";
            break;
        }

        playerTurn = !playerTurn;
    }

    return 0;
}
