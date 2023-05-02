#include "player.h"

Position::Position()
{
    //TODO
    this->x = 0;
    this->y = 0;
}


Position::Position(int x, int y)
{
    //TODO
    this->x = x;
    this->y = y;
}

Player::Player()
{
    //TODO
    this->position = Position();
    this->direction = Direction();
    this->moves = 0;
}

void Player::initialisePlayer(Position* position, Direction direction)
{
    //TODO
    this->position = *position;
    this->direction = direction;
    this->moves = 0;
    //std::cout << position->x << std::endl;
}

void Player::turnDirection(TurnDirection turnDirection)
{
    //TODO
}

Position Player::getNextForwardPosition()
{
    //TODO

    return this->position;
}

void Player::updatePosition(Position position)
{
    //TODO
}

void Player::displayDirection()
{
    //TODO
}
