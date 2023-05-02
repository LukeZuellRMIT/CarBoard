#include "board.h"

using std::vector;

const vector<vector<Cell>> Board::BOARD_1 =
{
    { BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED }
};

const vector<vector<Cell>> Board::BOARD_2 =
{
    { BLOCKED, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
};

const vector<vector<Cell>> Board::EMPTY_BOARD =
{
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
};

Board::Board()
{
    this->board = new std::vector<vector<Cell>>; 
    *(this->board) = Board::EMPTY_BOARD;

}

Board::~Board()
{
    // TODO
    delete board;

}

void Board::load(int boardId)
{   
    //std::string boardID; 
    //delete board;
    if (boardId == 1)   {
        *(this->board) = BOARD_1;
    }

    else if (boardId == 2)   {
        *(this->board) = BOARD_2;
    }

    else if (boardId == -1)   {
        *(this->board) = EMPTY_BOARD;
    }

    else    {
        Helper::printInvalidInput();
    }
    display(nullptr);
    // std::cout << "| |0|1|2|3|4|5|6|7|8|9|" << std::endl;
    //     for (int row = 0; row < 10; ++row) {
    //         std::cout << "|" << row << "|";
    //         for (int col = 0; col < 10; ++col) {
    //             if (((this->board))[row][col] == 0)    {
    //                 std::cout << " " << "|";
    //             }
    //             else    {
    //                 std::cout << "*" << "|";
    //             }
                
    //         }
    //         std::cout << std::endl;
    //     }
}

bool Board::placePlayer(Position position)
{   
    // std::cout << position.x << std::endl;
    // std::cout << position.y << std::endl;
    // std::cout << (*(this->board))[position.x][position.y] << std::endl;
    if ((*(this->board))[position.y][position.x] != 0)    {
        // std::cout << position.x << std::endl;
        // std::cout << position.y << std::endl;
        std::cout << "Unable to place player at that position." << std::endl << std::endl;
        Board::display(nullptr);
        return false;
    }
    // std::cout << "made it!" << std::endl;         
    return true; // feel free to revise this line, depending on your implementation.
}

PlayerMove Board::movePlayerForward(Player* player)
{
    // TODO
    return PLAYER_MOVED;
}

void Board::display(Player* player) {
    if (player == nullptr) {
        std::cout << "| |0|1|2|3|4|5|6|7|8|9|" << std::endl;
        for (int row = 0; row < DEFAULT_BOARD_DIMENSION; ++row) {
            std::cout << LINE_OUTPUT << row << LINE_OUTPUT;
            for (int col = 0; col < DEFAULT_BOARD_DIMENSION; ++col) {
                // places player at said x and y
                //if (col == (player->position.y) && row == (player->position.x))   {
                //    std::cout << player->direction << LINE_OUTPUT;
                //}
                //else if ((*(this->board))[row][col] == 0)    {
                if ((*(this->board))[row][col] == 0)    {
                    std::cout << EMPTY_OUTPUT << LINE_OUTPUT;
                }
                else    {
                    std::cout << BLOCKED_OUTPUT << LINE_OUTPUT;
                }
            }
            std::cout << std::endl;
        }
    }
    else    {
            std::cout << "| |0|1|2|3|4|5|6|7|8|9|" << std::endl;
            for (int row = 0; row < DEFAULT_BOARD_DIMENSION; ++row) {
                std::cout << LINE_OUTPUT << row << LINE_OUTPUT;
                for (int col = 0; col < DEFAULT_BOARD_DIMENSION; ++col) {
                    // places player at said x and y
                    if (col == (player->position.x) && row == (player->position.y))   {
                        if(player->direction == NORTH)    {
                            std::cout << DIRECTION_ARROW_OUTPUT_NORTH << LINE_OUTPUT;
                        }
                        else if(player->direction == SOUTH)    {
                            std::cout << DIRECTION_ARROW_OUTPUT_SOUTH << LINE_OUTPUT;
                        }
                        else if(player->direction == EAST)    {
                            std::cout << DIRECTION_ARROW_OUTPUT_EAST << LINE_OUTPUT;
                        }
                        else if(player->direction == WEST)    {
                            std::cout << DIRECTION_ARROW_OUTPUT_WEST << LINE_OUTPUT;
                        }
                    }
                    else if ((*(this->board))[row][col] == 0)    {
                    //if ((*(this->board))[row][col] == 0)    {
                        std::cout << EMPTY_OUTPUT << LINE_OUTPUT;
                    }
                    else    {
                        std::cout << BLOCKED_OUTPUT << LINE_OUTPUT;
                    }
                }
                std::cout << std::endl;
            }
    }
}


