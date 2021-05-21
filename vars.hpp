#include <iostream>
#include <string>
using namespace std;

char board[9] = { '-', '-', '-',
	'-', '-', '-',
	'-', '-', '-' };

char visual[100] = { '1', '2', '3',
	'4', '5', '6', '7', '8', '9' };

int pos;
int smartPos;
char player, winner;
char current = 'X';
bool game_ended = false;
bool has_won;
int move_counter = 0;
