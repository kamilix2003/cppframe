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

void Player::right(int range)
{
    x_+=range;
}

void Player::left(int range)
{
    x_-=range;
}

void Player::up(int range)
{
    y_-=range;
}

void Player::down(int range)
{
    y_+=range;
}
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

int Player::get_x()
{
    return x_;
}

int Player::get_y()
{
    return y_;
}
Player::Player(size_t x, size_t y)
{
    x_ = x;
    y_ = y;
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
        std::cout<< y;
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

int main(int argc, char** argv)
{
    Screen s{30, 10, 10};
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
    Player p(s.width/2, s.height/2);
    for(int i = 0; i < 5; i++)
    {
        std::cout<<"x: "<<p.get_x()<<" y: "<<p.get_y()<<"\n";
        d.draw(p);
        p.right(i);
        p.down(1);
    }
}