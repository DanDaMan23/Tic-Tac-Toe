#include <iostream>
#include <vector>

#include "functions.hpp"

int main () {

    std::vector<char> board = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};

    std::cout << "Tic-Tac-Toe\n\n";

    const char PLAYER_X = 'X';
    const char PLAYER_O = 'O';

    bool is_player_x_turn = true;

    int player_move = 0;

    print_board(board);

    // Make a move

    while (!determined_winner(board) ) {
        if (is_player_x_turn) {
            std::cout << "Player X turn\n";
            std::cout << "Make a move: ";
            std::cin >> player_move;
            board[player_move] = PLAYER_X;
        }
        else {
            std::cout << "Player O turn\n";
            std::cout << "Make a move: ";
            std::cin >> player_move;
            board[player_move] = PLAYER_O;
        }

        is_player_x_turn = !is_player_x_turn;

        print_board(board);
    }

}