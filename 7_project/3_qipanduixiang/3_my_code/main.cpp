#include "ChessBoard.hpp"
#include "BlackChess.hpp"
#include "WhiteChess.hpp"
#include <iostream>
using namespace std;
int main()
{
    fprintf(stderr, "\033[2J"); // 清屏

    ChessBoard *chessboard = ChessBoard::getChessBoard();
    chessboard->show();

    BlackChess blackchess(5, 1);
    blackchess.show();
    WhiteChess whitechess(1, 2);
    whitechess.show();
   
    /* 还有什么方式 让光标不要遮住棋板呢? 析构函数 让其自动 释放堆区内存同时把光标到棋板下 */
    //     fprintf(stderr, "\033[100;1H\033[0m");
    return 0;
}
