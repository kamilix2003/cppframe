#include <iostream>

class Entity
{
public:
    Entity(size_t, size_t);
    Entity(size_t, size_t, int, int);
    size_t x_;
    size_t y_;
    int x_velocity_;
    int y_velocity_;
    void set_velocity(int, int);
    void update();
    int get_x();
    int get_y();
};