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
        for(int i = 0; i <= frame_[0].size()+1 && y == 0;i++)
        {
            std::cout<<'x';
        }
        for(size_t x = 0; x < frame_[y].size(); x++)
        {
            if((x == 0)&&(y != 0))
            {
                std::cout<<'x';
            }
            if(p.get_x() == x && p.get_y() == y)
            {
                std::cout<<"P";
                if((x == frame_[0].size()-1)&&(y != 0))
                {
                std::cout<<'x';
                }
                continue;
            }
            std::cout<<frame_[y][x];
            if((x == frame_[0].size()-1)&&(y != 0))
            {
                std::cout<<'x';
            }
        }
        for(int i = 0; i <= frame_[0].size()+1 && y == frame_.size()-1;i++)
        {
            if(i == 0)
                std::cout<<"\n";
            std::cout<<'x';
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
        }
    }
}
