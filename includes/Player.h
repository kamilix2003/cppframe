#include <iostream>
#include <array>

class Player{
    private:
        size_t x_;
        size_t y_;
    public:
        Player(size_t , size_t);
        void right(int);
        void left(int);
        void up(int);
        void down(int);
        int get_x();
        int get_y();
};