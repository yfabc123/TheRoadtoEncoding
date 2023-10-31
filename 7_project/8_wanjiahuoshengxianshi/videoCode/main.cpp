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
    Player *plays[2]{wplayer, bplayer};
    bool finish = false;
    WinLogo winLog;

    while (1)
    {

        for (auto temp : plays)
        {
            key.waitPlayerPlaceChess(temp);
            if (judge.isWin(temp))
            {
                winLog.showWinPlayer(temp->getName(), temp->getColor());
                finish = true;
                break;
            }
        }
        if (finish)
        {

            break;
        }
    }
    return 0;
}
