#ifndef _GAME_HEAD_H_
#define _GAME_HEAD_H_
#include "ChessBoard.hpp"
#include "BlackChess.hpp"
#include "WhiteChess.hpp"
#include "WhitePlayer.hpp"
#include "BlackPlayer.hpp"
#include "KeyHandle.hpp"
#include "Cursor.hpp"
#include "Judge.hpp"
#include "WinLog.hpp"

using namespace std;

class Game
{
public:
    Game(const string &blackPlayerName, const string &whitePlayerName)
    {
        fprintf(stderr, "\033[2J"); // 清屏
        ChessBoard *chessBoard = ChessBoard::getChessBoard();
        chessBoard->show();
        players[0] = new WhitePlayer(whitePlayerName);
        players[1] = new BlackPlayer(blackPlayerName);
        key = new KeyHandle();
    }
    ~Game()
    {

        delete players[0];
        delete players[1];
        delete key;
    }
    void run()
    {
        bool finish = false;
        while (1)
        {
            for (auto temp : players)
            {
                key->waitPlayerPlaceChess(temp);
                if (judge.isWin(temp))
                {
                    winlog.showWinPlayer(temp->getName(), temp->getColor());
                    finish = true;
                    break;
                }
            }
            if (finish)
            {
                break;
            }
        }
    }

private:
    Player *players[2];
    Judge judge;
    WinLogo winlog;
    KeyHandle *key; // 光标构造需要在棋盘构造之后 否则光标不在棋盘正中间 故不能创建栈对象
};
#endif
