#include <iostream>
#include <time.h>
#include <array>

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

class Display{
    private:
        int height_;
        int width_;
        int refresh_;
        std::array<std::array<char,10>,10> map;
    public:
        Display(int, int, int);
        void draw();
};

Display::Display(int width, int height, int refresh)
{
    width_ = width;
    height_ = height;
    refresh_ = refresh;
}

void Display::draw()
{
    for(int y = 0; y < height_; y++)
    {
        for(int x = 0; x < height_; x++)
        {
            if(y == 0 || y == height_ - 1)
            {
                std::cout<<"x";
                continue;    
            }
        }
        std::cout<<"\n";
    }
}

int main(int argc, char** argv)
{
    Screen s{0, 0, 0};
    for(int i = 0; i < argc; i++)
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
    d.draw();
}