#include "game.h"

Game::Game()
{
    // TODO
    this->board = new Board();
    this->player = new Player();
    //myPlayer.initializePlayer()
    int status = system("ls -l");
}

Game::~Game()
{
    // TODO
    delete board;
    delete player;
}


void Game::start()
{   
    // sets initial board to empty
    //bool gameRunning = true;
    board->load(-1);
    std::cout << "" << std::endl;
    loadBoard();
}

bool Game::loadBoard()
{   
    // starts off with the game board not loaded
    int loadedBoard = -1;
    while (loadedBoard == -1)    {
        // get the users input
        std::cout << "At this stage of the program, only two commands are acceptable:" << std::endl
        << "load <g>" << std::endl
        << "quit" << std::endl << std::endl;
        std::string input = Helper::readInput();
        std::vector<std::string> tokens;
        std::string delimiter = " ";
        if (input == COMMAND_QUIT)  {
            system("./assign1");
            exit(0);
        }
        // splits the string into loading the board
        Helper::splitString(input, tokens, delimiter);
        //if board never been loaded, only allow load
        if (loadedBoard == -1)  {
            // makes sure user typed load
            if (tokens.at(0) == "load")    {
                // makes sure user input is a number
                if (Helper::isNumber(tokens.at(1)) == true) {
                    //std::cout << "test" << std::endl;
                    board->load(stoi(tokens.at(1)));
                    loadedBoard = 0;
                    initializePlayer();
                }
                else    {
                    Helper::printInvalidInput();
                }
            }
            else    {
                Helper::printInvalidInput();
            }
        }
    }
    return false; // feel free to revise this line, depending on your implementation.
}

bool Game::initializePlayer()   {
    //will stop once player is loaded
    int initializedPlayer = 0;
    while(initializedPlayer == 0)  {
        // reads users input
        std::cout << std::endl << "At this stage of the program, only three commands are acceptable:" << std::endl
        << "load <g>" << std::endl
        << "init <x>,<y>,<direction>" << std::endl
        << "quit" << std::endl << std::endl;
        std::string input = Helper::readInput();
        if (input == COMMAND_QUIT)  {
            system("./assign1");
            exit(0);
        }
        std::vector<std::string> tokens;
        //std::string delimiter = " ";
        // if it finds a ','
        if (input == COMMAND_QUIT)  {
            return false;
        }
        if(input.find(',') != std::string::npos)   {
            std::string delimiter = ",";
            // replace it with a ' '
            std::replace(input.begin(), input.end(), ' ', ',');
            Helper::splitString(input, tokens, delimiter);
            // split the string as now all delimit is the same
            if(tokens.at(0) == "init")   {
                int x = stoi(tokens.at(1));
                int y = stoi(tokens.at(2));
                if (x <= DEFAULT_BOARD_DIMENSION && y <= DEFAULT_BOARD_DIMENSION) {
                    this->player->position = Position(x, y);
                    std::vector<std::string> directions = {DIRECTION_NORTH, DIRECTION_EAST, DIRECTION_SOUTH, DIRECTION_WEST};
                    if (tokens.at(3) == "north")  {
                        this->player->direction = NORTH;
                    }
                    else if (tokens.at(3) == "east")   {
                        this->player->direction = EAST;
                    }
                    else if (tokens.at(3) == "south")   {
                        this->player->direction = SOUTH;   
                    }
                    else if (tokens.at(3) == "west")   {
                        this->player->direction = WEST;
                    }
                    //std::cout << std::endl << "sdfsdsdfsdfsdffsdfsd." << std::endl;
                    initializedPlayer = 1;
                    //board->placePlayer(this->player->position);
                    play();
                }
                else    {
                    Helper::printInvalidInput();
                    //std::cout << "sdfsdfsdfsdf" << std::endl;
                    board->display(nullptr);
                }
            }
            else    {
                Helper::printInvalidInput();
                std::cout << "" << std::endl;
                board->display(nullptr);
            }
        }
        else if(input.find(' ') != std::string::npos)   {
        //REMOVE THE FIRST 5 TIHNGS AND THE DO DELIMIT CHECKER
            std::string delimiter = " ";
            Helper::splitString(input, tokens, delimiter);
            if (tokens.at(0) == "load")    {
                if (Helper::isNumber(tokens.at(1)) == true) {
                    board->load(stoi(tokens.at(1)));
                }
                else    {
                    Helper::printInvalidInput();
                    std::cout << "" << std::endl;
                    board->display(nullptr);
                }
            }
            else    {
                Helper::printInvalidInput();
                board->display(nullptr);
            }
        }
        else    {
            Helper::printInvalidInput();
            board->display(nullptr);
        }
    }
    return false;
}

    //return false; // feel free to revise this line.

void Game::play()
{
    //TODO
    player->initialisePlayer(&this->player->position, this->player->direction);
    if((board->placePlayer(this->player->position)))  {
        board->display(this->player);
        //std::cout << "stf" << std::endl;
    }
    else    {
        initializePlayer();
    }
}