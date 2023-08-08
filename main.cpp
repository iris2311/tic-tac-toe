
#include <stdlib.h>
#include <iostream>
#include <string>
#include <iomanip>
#include "tic_tac_toe.h"

using namespace std;

int main(void)
{

  Game game;
  int player_number = 1;

  game.begin();

  while (!game.game_end())
  {

    game.player_move(player_number % 2);
    game.update(game.current_player, game.current_move);
    game.print_board();
    game.current_player = game.change_player(game.current_player);
    player_number++;
  }

  return 0;
}