#ifndef _BLACKPLAYER_HEAD_H_
#define _BLACKPLAYER_HEAD_H_
#include "Player.hpp"
#include "ChessBoard.hpp"
#include "BlackChess.hpp"
class BlackPlayer : public Player
{
public:
    BlackPlayer(const string &name) : Player(name, "黑"){}; // 构造函数一个参数即可 白棋手必定是白棋
    virtual bool placeChess(int x, int y)
    {
        ChessBoard *chessboard = ChessBoard::getChessBoard();
        bool ok = chessboard->isVaildPosition(x, y);
        if (ok) // 如果该位置没数据则更新棋盘数组数据
        {
            chessboard->placeChess(new BlackChess(x, y));
        }
        return ok;
    }
};
#endif