#include <iostream>
#include <array>

#include "./Entity.h"

class Player: public Entity{
    public:
        Player(size_t , size_t);
        void right(int);
        void left(int);
        void up(int);
        void down(int);
};