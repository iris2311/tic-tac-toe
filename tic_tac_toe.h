
#include <set>
#include <string>
#include <cctype>
#include <algorithm>
#include "enum.h"
class Game
{

private:
    char board[3][3];
    std::string input;
    std::set<int> valid_moves;
    int moves = 0;
    int row, column;
    enum player winner;

public:
    player current_player;
    int current_move;

    Game();
    void begin();
    void begin_message();
    void first_player_setup();
    void player_move(int);
    int number_of_moves();
    bool victory();
    bool horizontal_victory(int i);
    bool diagonal_victory();
    bool vertical_victory(int i);
    bool game_end();
    void print_board();
    void move_row_column(int);
    void update(player, int);
    bool valid_move(int);
    player change_player(player);
    ~Game();
};

void Game::begin_message()
{

    std::cout << "When playing, press numbers from 1 to 9." << std::endl;
    std::cout << "Who will play first? Press 'X' for X and 'O' for x" << std::endl;
}

void Game::begin()
{

    begin_message();
    getline(std::cin, input);
    first_player_setup();
}

void Game::first_player_setup()
{

    transform(input.begin(), input.end(), input.begin(), ::toupper);
    if (input == "X")
        current_player = X;
    else
        current_player = O;
}

void Game::player_move(int player_number)
{

    std::cout << "Player" << player_number << ", it is your turn." << std::endl;
    std::cin >> current_move;
    if (!valid_move(current_move))
    {
        while (!valid_move(current_move))
        {
            std::cout << "Invalid move, try again." << std::endl;
            std::cin >> current_move;
        }
    }
}

int Game::number_of_moves()
{

    return moves;
}

player Game::change_player(player current)
{

    if (current == X)
        return O;
    return X;
}

Game::Game()
{

    for (auto i = 1; i <= 9; ++i)
        valid_moves.insert(i);

    for (auto i = 0; i < 3; ++i)
        for (auto j = 0; j < 3; ++j)
            board[i][j] = 2;
}

Game::~Game()
{
}

bool Game::diagonal_victory()
{

    if ((board[1][1] != 2) && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2]))
    {
        winner = (player)board[1][1];

        return true;
    }

    if ((board[1][1] != 2) && (board[0][2] == board[1][1]) && (board[1][1] == board[2][0]))
    {
        winner = (player)board[1][1];
        return true;
    }

    return false;
}

bool Game::horizontal_victory(int i)
{

    if ((board[i][0] != 2) && (board[i][0] == board[i][1]) && (board[i][1] == board[i][2]))
    {
        winner = (player)board[i][0];

        return true;
    }

    return false;
}

bool Game::vertical_victory(int i)
{

    if ((board[0][i] != 2) && (board[0][i] == board[1][i]) && (board[1][i] == board[2][i]))
    {
        winner = (player)board[0][i];

        return true;
    }

    return false;
}

bool Game::victory()
{
    for (int i = 0; i < 3; ++i)
    {
        if (vertical_victory(i) || horizontal_victory(i))
            return true;
    }

    if (diagonal_victory())
        return true;

    return false;
}

bool Game::game_end()
{

    if (victory())
    {

        std::cout << "Winner is " << convert_to_enum(current_player) << "!" << std::endl;
        return true;
    }

    if (number_of_moves() == 9)
    {
        std::cout << "It's a tie!" << std::endl;
        return true;
    }

    return false;
}

void Game::print_board()
{

    std::cout << std::endl;

    for (auto i = 0; i < 3; ++i)
    {
        for (auto j = 0; j < 3; ++j)
        {
            if (board[i][j] == 2)
                std::cout << std::setw(5) << "-";

            else
                std::cout << std::setw(5) << convert_to_enum(board[i][j]);
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
}

void Game::move_row_column(int move)
{

    switch (move)
    {
    case 1:
        row = 0;
        column = 0;
        break;
    case 2:
        row = 0;
        column = 1;
        break;
    case 3:
        row = 0;
        column = 2;
        break;
    case 4:
        row = 1;
        column = 0;
        break;
    case 5:
        row = 1;
        column = 1;
        break;
    case 6:
        row = 1;
        column = 2;
        break;
    case 7:
        row = 2;
        column = 0;
        break;
    case 8:
        row = 2;
        column = 1;
        break;
    case 9:
        row = 2;
        column = 2;
        break;
    }
}

void Game::update(player current_player, int move)
{

    move_row_column(move);
    board[row][column] = player(current_player);
    valid_moves.erase(move);
    moves++;
}

bool Game::valid_move(int move)
{

    if (valid_moves.find(move) == valid_moves.end())
        return false;

    return true;
}