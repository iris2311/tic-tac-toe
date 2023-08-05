
enum player{O,X};

class Game{

    private:
    int board[3][3];
    int moves=0;
    enum player winner;

    public:
    Game();
    int number_of_moves();
    bool victory();
    bool game_end();
    ~Game();

};

int Game::number_of_moves(){

    return moves;
}

Game::Game(){
    
    for (auto i=0; i<3; ++i)
        for(auto j=0; j<3; ++j){
            board[i][j]=0;
        }
}

Game::~Game(){


}

bool Game:: victory() {
     for (int i = 0; i < 3; ++ i) {
        if ((board[i][0] != 0) && (board[i][0] == board[i][1]) 
                        && (board[i][1] == board[i][2])) {
            winner = (player)board[i][0];
            
            return true;
        }
        if ((board[0][i] != 0) && (board[0][i] == board[1][i]) 
                        && (board[1][i] == board[2][i])) {
            winner = (player)board[0][i];
           
            return true;
        }            
    }
    if ((board[1][1] != 0) && (board[0][0] == board[1][1]) 
                        && (board[1][1] == board[2][2])) {
        winner = (player)board[1][1];
       
        return true;
    }
    if ((board[1][1] != 0) && (board[0][2] == board[1][1]) 
                        && (board[1][1] == board[2][0])) {
        winner= (player)board[1][1];
        return true;
    }        
    return false;
}


bool Game::game_end(){

    if (victory()==true || number_of_moves()==9)
        return true;

    return false;
    
    
}