#include <iostream>

#include "../includes/Entity.h"

Entity::Entity(size_t x, size_t y)
{
    x_ = x;
    y_ = y;
}

int Entity::get_x()
{
    return x_;
}

int Entity::get_y()
{
    return y_;
}