#include <iostream>

class Entity
{
public:
    Entity(size_t, size_t);
    size_t x_;
    size_t y_;
    int x_velocity;
    int y_velocity;
    int get_x();
    int get_y();
};