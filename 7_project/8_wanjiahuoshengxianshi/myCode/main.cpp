#include "ChessBoard.hpp"
#include "BlackChess.hpp"
#include "WhiteChess.hpp"
#include "WhitePlayer.hpp"
#include "BlackPlayer.hpp"
#include <iostream>
#include "KeyHandle.hpp"
#include "Cursor.hpp"
#include "Judge.hpp"
#include "WinLog.hpp"
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
    WinLogo winlog;
    while (1)
    {
        key.waitPlayerPlaceChess(bplayer);
        if (judge.isWin(bplayer))
        {
            winlog.showWinPlayer(bplayer->getName(), bplayer->getColor());
            break;
        }
        key.waitPlayerPlaceChess(wplayer);
        if (judge.isWin(wplayer))
        {
            winlog.showWinPlayer(wplayer->getName(), wplayer->getColor());

            break;
        }
    }

    return 0;
}
