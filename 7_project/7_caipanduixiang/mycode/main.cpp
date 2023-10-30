#include "ChessBoard.hpp"
#include "BlackChess.hpp"
#include "WhiteChess.hpp"
#include "WhitePlayer.hpp"
#include "BlackPlayer.hpp"
#include <iostream>
#include "KeyHandle.hpp"
#include "Cursor.hpp"
#include "Judge.hpp"
using namespace std;
int main()
{
    fprintf(stderr, "\033[2J"); // 清屏

    ChessBoard *chessboard = ChessBoard::getChessBoard();
    chessboard->show();

    WhitePlayer *wplayer = new WhitePlayer("张三");
    BlackPlayer *bplayer = new BlackPlayer("李四");


    KeyHandle key;
    Judge judge;
    while (1)
    {
        key.waitPlayerPlaceChess(wplayer);
        // if (judge.isWin(wplayer))
        // {
        //     break;
        // }
    }

    return 0;
}
