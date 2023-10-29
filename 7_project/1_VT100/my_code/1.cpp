#include <iostream>
using namespace std;

class Mizi
{

public:
    Mizi(int x, int y, int len) : x(x), y(y), len(len)
    {
    }
    void print_xy(int x, int y, int background, int font)
    {
        fprintf(stderr, "\033[%d;%dH\033[%d;%dm*\033[0m", y, x, background, font);
    }
    void print_vertical()
    {
        for (int i = 0; i < len; i++)
        {
            print_xy(x, y + i, 45, 37);
            print_xy(x, y - i, 45, 37);
        }
    }
    void print_level()
    {
        for (int i = 0; i < len; i++)
        {
            print_xy(x + i, y, 44, 37);
            print_xy(x - i, y, 44, 37);
        }
    }
    void print_oblique_up()
    {
        for (int i = 0; i < len; i++)
        {
            print_xy(x + i, y - i, 43, 37);
            print_xy(x - i, y + i, 43, 37);
        }
    }
    void print_oblique_down()
    {
        for (int i = 0; i < len; i++)
        {
            print_xy(x + i, y + i, 42, 37);
            print_xy(x - i, y - i, 42, 37);
        }
    }
    void show()
    {
        print_vertical();
        print_level();
        print_oblique_up();
        print_oblique_down();
        fprintf(stderr, "\033[%d;%dH\033[0m", y + len, 0);
    }

private:
    int x;
    int y;
    int len;
};

int main()
{
    Mizi m(20, 10, 5);
    m.show();
    return 0;
}