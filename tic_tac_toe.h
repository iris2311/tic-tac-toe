

class Game{

    private:
    int board[3][3];
    bool victory=false;
    bool Victory();

    public:
    Game();
    ~Game();

};

Game::Game(){
    
    for (auto i=0; i<3; ++i)
        for(auto j=0; j<3; ++j){
            board[i][j]=0;
        }
}

Game::~Game(){


}

Game::bool Victory() {
     for (int i = 0; i < 3; ++ i) {
        if ((board[i][0] != 0) && (board[i][0] == board[i][1]) 
                        && (board[i][1] == board[i][2])) {
            winner = board[i][0];
            victory=true;
            return true;
        }
        if ((board[0][i] != 0) && (board[0][i] == board[1][i]) 
                        && (board[1][i] == board[2][i])) {
            winner = board[0][i];
            victory=true;
            return true;
        }            
    }
    if ((board[1][1] != 0) && (board[0][0] == board[1][1]) 
                        && (board[1][1] == board[2][2])) {
        winner = board[1][1];
        victory=true;
        return true;
    }
    if ((board[1][1] != 0) && (board[0][2] == board[1][1]) 
                        && (board[1][1] == board[2][0])) {
        winner= board[1][1];
        victory=true;
        return true;
    }        
    return false;
}