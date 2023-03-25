#include <iostream>
#include <ctime>
#include <array>

#include "../includes/Display.h"

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

int main(int argc, char** argv)
{
    Screen s{30, 10, 10};
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
    d.draw(p);
    std::time_t prev_tick = 0;
    std::time_t clock = std::time(nullptr);
    while(1)
    {   
        clock = std::time(nullptr);
        if(clock - prev_tick > 0)
        {
            std::cout<<std::asctime(std::localtime(&clock));
            d.draw(p);
            prev_tick = clock;
        }
    }
}