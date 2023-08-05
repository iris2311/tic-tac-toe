#include <stdio.h>
#include <stdlib.h>
#include<string>
#include <iostream>
#include <algorithm>

  
#include "tic_tac_toe.h"

using namespace std;

int main(void){

   Game game;
   string input;
   player current_player;
   int current_move;

   cout<<"When playing, press numbers from 1 to 9."<<endl;

   cout<<"Who will play first? Press 'X' for X and 'O' for x"<<endl;
   getline(cin,input);
   if(input=="x")
      input="X";
    if(input=="o")
        input="0";

    if(input=="O")
        current_player=O;
    else
        current_player=X;

   while(!game.game_end()){

    cout<<"Player 1, it is your turn."<<endl;
    cin>>current_move;
    if(!game.valid_move(current_move)){
        while(!game.valid_move(current_move))
        { cout<<"Invalid move, try again."<<endl;
          cin>>current_move;
        }
    }

    game.update(current_player, current_move);
    game.print_board();
    if (game.game_end())
        break;

    cout<<"Player 2, it is your turn."<<endl;
    current_player=game.change_player(current_player);
    cin>>current_move;
    if(!game.valid_move(current_move)){
        while(!game.valid_move(current_move))
        { cout<<"Invalid move, try again."<<endl;
          cin>>current_move;
        }
    }
    game.update(current_player, current_move);
    game.print_board();
    current_player=game.change_player(current_player);
   }

    return 0;
}