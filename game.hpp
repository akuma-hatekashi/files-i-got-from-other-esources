#include <iostream>
#include "vars.hpp"
#include <string>

#define NC "\e[0m"
#define RED "\e[0;31m"

bool work2 = true;
bool work3 = true;
bool sim_full;
bool simulating;
int cMoveCounter = 0;

void print_board();
char handle_turn(char player);
char flip(char current);
char check_horizontal();
char check_vertical();
char check_diagonal();
void get_winner();
void check_if_ended();
void play_game();

void print_board()
{
	std::cout << '\n';
	std::string div = " | ";
	std::cout << board[0] << div << board[1] << div << board[2] << "        " << visual[0] << div << visual[1] << div << visual[2];
	std::cout << '\n';
	std::cout << board[3] << div << board[4] << div << board[5] << "   ->   " << visual[3] << div << visual[4] << div << visual[5];
	std::cout << '\n';
	std::cout << board[6] << div << board[7] << div << board[8] << "        " << visual[6] << div << visual[7] << div << visual[8];
	std::cout << '\n';
}

char handle_turn(char c_player)
{
	move_counter++;
	if (move_counter > 9)
	{
		game_ended = true;
		std::cout << "\nIt's a tie!";
	}
	else
	{
		if (simulating == false && sim_full == false)
		{
			std::cout << '\n';
			std::cout << c_player << "'s turn!\n";
			std::cout << "Chose a position: ";
			std::cin >> pos;
			pos -= 1;
		}
		else
		{
			if (sim_full == false)
			{
				if (current == 'X')
				{
					std::cout << '\n';
					std::cout << c_player << "'s turn!\n";
					std::cout << "Chose a position: ";
					std::cin >> pos;
					pos -= 1;
					cMoveCounter = 0;
				}
				else
				{
					if (cMoveCounter <= 1)
					{
						std::cout << '\n';
						std::cout << "Guessing possible moves...\n";
					}
					/*if (smartPos == 0) { 	pos = rand()%9;
					} else { 	pos = smartPos;
					}*/
					pos = rand() % 10;
				}
			}
			else
			{
				pos = rand() % 10;
			}
		}
		if (board[pos] != '-')
		{
			if (simulating == false && sim_full == false)
			{
				std::cout << "Invalid move! Retry\n";
			}
			move_counter -= 1;
			if (current == 'X')
			{
				current = 'O';
			}
			else if (current == 'O')
			{
				current = 'X';
			}
		}
		else
		{
			board[pos] = current;
			visual[pos] = '-';
			if (sim_full == false)
			{
				print_board();
			}
		}
		cMoveCounter++;
	}
	return player;
}

char flip(char current_p)
{
	if (current_p == 'X')
	{
		current = 'O';
	}
	else
	{
		current = 'X';
	}
	return current;
}

char check_horizontal()
{

	bool row1, row2, row3;

	if (((board[0] == 'X') and(board[1] == 'X') and(board[2] == 'X')) or((board[0] == 'O') and(board[1] == 'O') and(board[2] == 'O')))
	{
		row1 = true;
	}

	if (((board[3] == 'X') and(board[4] == 'X') and(board[5] == 'X')) or((board[3] == 'O') and(board[4] == 'O') and(board[5] == 'O')))
	{
		row2 = true;
	}

	if (((board[6] == 'X') and(board[7] == 'X') and(board[8] == 'X')) or((board[6] == 'O') and(board[7] == 'O') and(board[8] == 'O')))
	{
		row3 = true;
	}

	if ((row1) or(row2) or(row3))
	{
		game_ended = true;
	}

	if (row1)
	{
		return board[0];
	}
	else if (row2)
	{
		return board[3];
	}
	else if (row3)
	{
		return board[6];
	}
	else
	{
		return 0;
	}
}

char check_vertical()
{
	bool row1, row2, row3;

	if (((board[0] == 'X') and(board[3] == 'X') and(board[6] == 'X')) or((board[0] == 'O') and(board[4] == 'O') and(board[7] == 'O')))
	{
		row1 = true;
	}

	if (((board[1] == 'X') and(board[4] == 'X') and(board[7] == 'X')) or((board[1] == 'O') and(board[4] == 'O') and(board[7] == 'O')))
	{
		row2 = true;
	}

	if (((board[2] == 'X') and(board[5] == 'X') and(board[8] == 'X')) or((board[2] == 'O') and(board[5] == 'O') and(board[8] == 'O')))
	{
		row3 = true;
	}

	if ((row1) or(row2) or(row3))
	{
		game_ended = true;
	}

	if (row1)
	{
		return board[0];
	}
	else if (row2)
	{
		return board[1];
	}
	else if (row3)
	{
		return board[2];
	}
	else
	{
		return 0;
	}
}

char check_diagonal()
{
	bool row1, row2;

	if (((board[0] == 'X') and(board[4] == 'X') and(board[8] == 'X')) or((board[0] == 'O') and(board[4] == 'O') and(board[8] == 'O')))
	{
		row1 = true;
	}

	if (((board[2] == 'X') and(board[4] == 'X') and(board[6] == 'X')) or((board[2] == 'O') and(board[4] == 'O') and(board[6] == 'O')))
	{
		row2 = true;
	}

	if ((row1) or(row2))
	{
		game_ended = true;
	}

	if (row1)
	{
		return board[0];
	}
	else if (row2)
	{
		return board[2];
	}
	else
	{
		return 0;
	}
}

void get_winner()
{
	char hor_winner = check_horizontal();
	char vert_winner = check_vertical();
	char diag_winner = check_diagonal();

	if (hor_winner != 0)
	{
		winner = hor_winner;
	}
	else if (vert_winner != 0)
	{
		winner = vert_winner;
	}
	else if (diag_winner != 0)
	{
		winner = diag_winner;
	}
}

void check_if_ended()
{
	get_winner();
}

void play_game()
{

	game_ended = false;

	if (sim_full == false)
	{
		print_board();
	}

	while (game_ended == false)
	{
		handle_turn(current);
		check_if_ended();
		flip(current);
	}
	if (sim_full)
	{
		print_board();
	}
	if (winner == 'X'
		or winner == 'O')
	{
		std::cout << winner << " won!";
	}
}
