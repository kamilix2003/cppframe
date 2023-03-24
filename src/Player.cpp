#include <iostream>

#include "../includes/Player.h"

void Player::right(int range)
{
    x_+=range;
}

void Player::left(int range)
{
    x_-=range;
}

void Player::up(int range)
{
    y_-=range;
}

void Player::down(int range)
{
    y_+=range;
}

int Player::get_x()
{
    return x_;
}

int Player::get_y()
{
    return y_;
}
Player::Player(size_t x, size_t y)
{
    x_ = x;
    y_ = y;
}
