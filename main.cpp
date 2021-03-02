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

    int available_turns = 0;

    print_board(board);

    while (!determined_winner(board) && available_turns < 9) {
        if (is_player_x_turn) {
            std::cout << "Player X turn\n";
            std::cout << "Make a move: ";
            std::cin >> player_move;
            if (valid_move(player_move, board)) {
                board[player_move] = PLAYER_X;
                available_turns++;
            }
            else {
                std::cout << "Invalid Move, Try again!\n";
            }
        }
        else {
            std::cout << "Player O turn\n";
            std::cout << "Make a move: ";
            std::cin >> player_move;
            if (valid_move(player_move, board)) {
                board[player_move] = PLAYER_O;
                available_turns++;
            }
            else {
                std::cout << "Invalid Move, Try again!\n";
            }
        }

        if (!determined_winner(board)) {
            is_player_x_turn = !is_player_x_turn;
        }

        print_board(board);
    }

    if (available_turns == 9 && !determined_winner(board)) {
        std::cout << "Tie Game";
    }
    else {
        if (is_player_x_turn) {
            std::cout << "Player X wins";
        }
        else {
            std::cout << "Player O wins";
        }
    }



}