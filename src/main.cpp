#include <iostream>
#include <ctime>
#include <array>
#include <cstdio>

#include "../includes/Display.h"
#include "../includes/defines.h"

struct Screen
{
    int width;
    int height;
    int refresh;
};

enum arg
{
    w = 1,
    h,
    r
};

enum directions
{
    NORTH = 0,
    EAST,
    SOUTH,
    WEST,
};

int main(int argc, char** argv)
{
    bool gameover = false;
    Screen s{MAX_WIDTH, MAX_HEIGHT, 10};
    for(int i = 0; i < argc; i++) // handle input flags
    {
        if(*argv[i] == '-')
        {
            switch (*(argv[i]+1))
            {
            case 'w':
                s.width = std::stoi(argv[i+1]);
                break;
            case 'h':
                s.height = std::stoi(argv[i+1]);
                break;
            case 'r':
                s.refresh = std::stoi(argv[i+1]);
                break;
            default:
                std::cout<<"invalid argument";
                break;
            }
        }
    }
    std::cout<< s.height << " "
            << s.width << " "
            << s.refresh << "\n";
    Display d(s.width, s.height, s.refresh);
    Player p(s.width/2, s.height/2);
    p.set_velocity(2, 1);
    std::time_t prev_tick = 0;
    std::time_t clock = std::time(nullptr);
    while(!gameover)
    {   
        clock = std::time(nullptr);
        if(clock - prev_tick > 0)
        {
            std::cout<<std::asctime(std::localtime(&clock));
            p.update();
            d.draw(p);
            prev_tick = clock;
            std::cout<<ESC<<"[2J";
        }
    }
}