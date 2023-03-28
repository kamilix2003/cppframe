#include <iostream>

#include "../includes/Entity.h"
#include "../includes/defines.h"

Entity::Entity(size_t x, size_t y)
{
    x_ = x;
    y_ = y;
}

Entity::Entity(size_t x, size_t y, int v_x, int v_y)
{
    x_ = x;
    y_ = y;
    x_velocity_ = v_x;
    y_velocity_ = v_y;
}

void Entity::set_velocity(int v_x, int v_y)
{
    x_velocity_ = v_x;
    y_velocity_ = v_y;
}

void Entity::update()
{
    if(x_ + x_velocity_ <= 0 || x_ + x_velocity_ >= MAX_WIDTH)
    {
        x_velocity_ = -x_velocity_;
        x_ += x_velocity_;
    }else
    {
        x_ += x_velocity_;
    }
        if(y_ + y_velocity_ <= 0 || y_ + y_velocity_ >= MAX_HEIGHT)
    {
        y_velocity_ = -y_velocity_;
        y_ += y_velocity_;
    }else
    {
        y_ += y_velocity_;
    }
}

int Entity::get_x()
{
    return x_;
}

int Entity::get_y()
{
    return y_;
}