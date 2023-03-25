#include <iostream>
#include <array>

#include "../includes/Display.h"

void Display::draw()
{
    for(size_t y = 0; y < frame_.size(); y++)
    {
        for(size_t x = 0; x < frame_[y].size(); x++)
        {
            std::cout<<frame_[y][x];
        }
        std::cout<<std::endl;
    }
}

void Display::draw(Player p)
{
    for(size_t y = 0; y < frame_.size(); y++)
    {
        for(size_t x = 0; x < frame_[y].size(); x++)
        {
            if(p.get_x() == x && p.get_y() == y)
            {
                std::cout<<'p';
                continue;
            }
            std::cout<<frame_[y][x];
        }
        std::cout<<std::endl;
    }
}
Display::Display(size_t width, size_t height, int refresh)
{
    width_ = width;
    height_ = height;
    refresh_ = refresh;
    for(size_t y = 0; y < height_; y++)
    {
        for(size_t x = 0; x < width_; x++)
        {
            frame_[y][x] = ' ';
            if(y == 0 || y == height_-1)
            {
                frame_[y][x] = '-';
            }
            else if(x == 0 || x == width_-1)
            {
                frame_[y][x] = '|';
            }
        }
    }
}
