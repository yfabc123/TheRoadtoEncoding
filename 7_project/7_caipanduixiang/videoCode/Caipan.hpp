#ifndef _CAIPAN_HEAD_H_
#define _CAIPAN_HEAD_H_
#include "Player.hpp"
class Caipan
{
public:
    bool isWin(Player *player)
    {
        bool ok;

        /*horizontal*/
        ok = isHorizontalWin(player->getColor());
        if (ok)
        {
            return (true);
        }

        /* vertical */
        ok = isVerticalWin(player->getColor());
        if (ok)
        {
            return (true);
        }

        /* uphill */
        ok = isUphillWin(player->getColor());
        if (ok)
        {
            return (true);
        }

        /* downhill */
        ok = isDownhillWin(player->getColor());
        if (ok)
        {
            return (true);
        }

        return (false);
    }

    bool isHorizontalWin(const string &color)
    {
        int count = 0;
        ChessBoard *chessBoard = ChessBoard::getChessBoard();
        int line = chessBoard->getCurrentLine();
        int column = chessBoard->getCurrentColumn();

        /* right:行不变，列增加 */
        for (int i = 0; i < 5; i++)
        {
            bool ok = chessBoard->isSameColorChess(color, line, column + i);
            if (ok)
            {
                count++;
            }
            else
            {
                break;
            }
        }

        if (count >= 5)
        {
            return (true);
        }

        /* left：行不变，列减少 */
        for (int i = 0; i < 5; i++)
        {
            bool ok = chessBoard->isSameColorChess(color, line, column - i);
            if (ok)
            {
                count++;
            }
            else
            {
                break;
            }
        }

        // 中间棋子多算了一次
        if (count - 1 >= 5)
        {
            return (true);
        }

        return (false);
    }

private:
};
#endif