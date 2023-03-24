#include <iostream>
#include <array>

#include "./Player.h"

class Display{
    private:
        size_t height_;
        size_t width_;
        int refresh_;
        std::array<std::array<char,30>,10> frame_;
    public:
        Display(size_t, size_t, int);
        void draw();
        void draw(Player);
};

