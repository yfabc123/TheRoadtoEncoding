#ifndef _WHITECHESS_HEAD_H
#define _WHITECHESS_HEAD_H

#include <stdio.h>
#include "Chess.hpp"

class WhiteChess : public Chess
{

public:
    WhiteChess(int x, int y) : Chess("white", x, y) {}
    void show(void) const
    {
        fprintf(stderr, "\033[%d;%dH\033[44;36m[o]\033[0m",
                getY(), getX()-1);
        fprintf(stderr, "\033[%d;%dH", getY(), getX());
    }
};

#endif
