#include <iostream>

#include "../includes/Player.h"

void Player::right(int range)
{
    Entity::x_+=range;
}

void Player::left(int range)
{
    Entity::x_-=range;
}

void Player::up(int range)
{
    Entity::y_-=range;
}

void Player::down(int range)
{
    Entity::y_+=range;
}

Player::Player(size_t x, size_t y):
    Entity(x, y)
    {
    }