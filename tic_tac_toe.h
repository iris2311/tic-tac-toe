
#include <set>


enum player{O=0,X=1, e=2};

static const char *enum_string[] = { "O", "X", "e" };

std::string convert_to_enum (int tmp){

    std::string MyStr(enum_string[tmp]);
    return MyStr;
}

class Game{

    private:
    char board[3][3];
    std::string input;
    std::set <int> valid_moves;
    int moves=0;
    enum player winner;

    public:
    player current_player;
    int current_move;

    Game();
    void begin();
    int number_of_moves();
    bool victory();
    bool game_end();
    void print_board();
    void update(player, int);
    bool valid_move(int);
    player change_player(player);
    ~Game();

};

void Game::begin(){

   std::cout<<"When playing, press numbers from 1 to 9."<<std::endl;

   std::cout<<"Who will play first? Press 'X' for X and 'O' for x"<<std::endl;
   getline(std::cin,input);
   if(input=="x")
      input="X";
    if(input=="o")
        input="0";

    if(input=="O")
        current_player=O;
    else
        current_player=X;

}

int Game::number_of_moves(){

    return moves;
}

player Game::change_player(player current){

    if(current==X)
        return O;
    return X;
}

Game::Game(){
    
    for (auto i=1; i<=9; ++i)
        valid_moves.insert(i);

    for(auto i=0; i<3; ++i)
        for(auto j=0; j<3; ++j)
            board[i][j]=2;
}

Game::~Game(){


}

bool Game:: victory() {
     for (int i = 0; i < 3; ++ i) {
        if ((board[i][0] != 2) && (board[i][0] == board[i][1]) 
                        && (board[i][1] == board[i][2])) {
            winner = (player)board[i][0];
            
            return true;
        }
        if ((board[0][i] != 2) && (board[0][i] == board[1][i]) 
                        && (board[1][i] == board[2][i])) {
            winner = (player)board[0][i];
           
            return true;
        }            
    }
    if ((board[1][1] != 2) && (board[0][0] == board[1][1]) 
                        && (board[1][1] == board[2][2])) {
        winner = (player)board[1][1];
       
        return true;
    }
    if ((board[1][1] != 2) && (board[0][2] == board[1][1]) 
                        && (board[1][1] == board[2][0])) {
        winner= (player)board[1][1];
        return true;
    }        
    return false;
}


bool Game::game_end(){

    if (victory()==true){

        std::cout<<"Winner is "<<convert_to_enum(current_player)<<"!"<<std::endl;
        return true;
    }

    if(number_of_moves()==9){
        std::cout<<"It's a tie!"<<std::endl;
        return true;
    }

    return false;
    
    
}

void Game::print_board(){

    for (auto i=0; i<3; ++i){
        for(auto j=0; j<3; ++j){
            if(board[i][j]==2){
                std::cout<<std::setw(5)<<"-";

            }
                
            else
                 {
                    std::cout<<std::setw(5)<<convert_to_enum(board[i][j]);
                 }
        }

        std::cout<<std::endl;
    }

}

void Game::update(player current_player, int move){

    int row, column;

    switch(move){
        case 1: row=0; column=0; 
            break;
        case 2: row=0; column=1; 
            break;
        case 3: row=0; column=2; 
            break;
        case 4: row=1; column=0;
            break;
        case 5: row=1; column=1; 
            break;
        case 6: row=1; column=2; 
            break;
        case 7: row=2; column=0; 
            break;
        case 8: row=2; column=1; 
            break;
        case 9: row=2; column=2; 
            break;
    }

    board[row][column]=player(current_player);
    valid_moves.erase(move);
    moves++;

}

bool Game::valid_move(int move){

  if(valid_moves.find(move)==valid_moves.end())
    return false;

  return true;
    

}