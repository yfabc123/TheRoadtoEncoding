#include "ChessBoard.hpp"
#include "BlackChess.hpp"
#include "WhiteChess.hpp"
#include "WhitePlayer.hpp"
#include "BlackPlayer.hpp"
#include <iostream>
using namespace std;
int main()
{
    fprintf(stderr, "\033[2J"); // 清屏

    ChessBoard *chessboard = ChessBoard::getChessBoard();
    chessboard->show();

    // BlackChess blackchess(5, 1);
    // WhiteChess whitechess(5, 3);

    // chessboard->placeChess(&blackchess);
    // chessboard->placeChess(&whitechess);
    WhitePlayer *wplayer = new WhitePlayer("张三");
    BlackPlayer *bplayer = new BlackPlayer("李四");
    wplayer->playChess(9, 9);
    bplayer->playChess(9, 5);
    wplayer->playChess(13, 9);

    return 0;
}
