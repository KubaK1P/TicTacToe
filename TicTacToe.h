#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <vector>
#include <iostream>

class TicTacToe {
public:
    TicTacToe();  
    void displayBoard() const; 
    bool makeMove(int player, int row, int col);  
    bool isWinner(int player) const;   
    bool isDraw() const;  
    void computerMove();  
private:
    std::vector<std::vector<char>> board;  
    char getSymbol(int player) const;  
    bool isMoveValid(int row, int col) const;  
};

#endif
