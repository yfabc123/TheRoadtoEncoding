#ifndef _WHITEPLAYER_HEAD_H_
#define _WHITEPLAYER_HEAD_H_
#include "Player.hpp"
#include "ChessBoard.hpp"
#include "WhiteChess.hpp"
class WhitePlayer : public Player // 不要继承棋盘 棋盘是单例模式直接能获取
{
public:
    WhitePlayer(const string &name) : Player(name, "white") {}
    virtual bool playChess(int x, int y)
    {
        ChessBoard *chessboard = ChessBoard::getChessBoard();
        bool ok = chessboard->isVaildPosition(x, y);
        if (ok)
        {
            chessboard->placeChess(new WhiteChess(x, y));
        }
        return ok;
    }
};

#endif