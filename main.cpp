
#include <stdlib.h>
#include<string>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include "tic_tac_toe.h"

using namespace std;

int main(void){

   Game game;
   
   game.begin();

   while(!game.game_end()){

    cout<<"Player 1, it is your turn."<<endl;
    cin>>game.current_move;
    if(!game.valid_move(game.current_move)){
        while(!game.valid_move(game.current_move))
        { cout<<"Invalid move, try again."<<endl;
          cin>>game.current_move;
        }
    }

    cout<<endl;

    game.update(game.current_player, game.current_move);
    game.print_board();
    if (game.game_end())
        break;

    cout<<"Player 2, it is your turn."<<endl;
    game.current_player=game.change_player(game.current_player);
    cin>>game.current_move;
    if(!game.valid_move(game.current_move)){
        while(!game.valid_move(game.current_move))
        { cout<<"Invalid move, try again."<<endl;
          cin>>game.current_move;
        }
    }
    game.update(game.current_player, game.current_move);
    cout<<endl;
    game.print_board();
    game.current_player=game.change_player(game.current_player);
   }


    return 0;
}