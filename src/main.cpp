#include <iostream>
#include <ctime>
#include <array>
#include <cstdio>

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

void handle_input(std::string command, Player e)
{
    std::cout<<"command: ";
    std::cin>>command;
    if(command == "right")
    {
        e.right(1);
    }
    else if(command == "left")
    {
        e.left(1);
    }
    else if(command == "up")
    {
        e.up(1);
    }
    else if(command == "down")
    {
        e.down(1);
    }
}

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
    int counter = 0;
    std::string command;
    while(1)
    {
    handle_input(command, p);
    d.draw(p);
    }
    // while(1)
    // {   
    //     clock = std::time(nullptr);
    //     if(clock - prev_tick > 0)
    //     {
    //         std::cout<<std::asctime(std::localtime(&clock));
    //         d.draw(p);
    //         if(counter%4==0)
    //             p.up(1);
    //         if(counter%4==1)
    //             p.right(1);
    //         if(counter%4==2)
    //             p.down(1);
    //         if(counter%4==3)
    //             p.left(1);
    //         prev_tick = clock;
    //         counter++;
    //     }
    // }
}