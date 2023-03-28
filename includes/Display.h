#include <iostream>
#include <array>

#include "./defines.h"
#include "./Player.h"

class Display{
    private:
        size_t height_;
        size_t width_;
        int refresh_;
        std::array<std::array<char,MAX_WIDTH>,MAX_HEIGHT> frame_;
    public:
        Display(size_t, size_t, int);
        void draw();
        void draw(Player);
};

