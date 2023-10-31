#ifndef _JUDGE_HEAD_H_
#define _JUDGE_HEAD_H_

#include <iostream>
#include "Player.hpp"
#include "ChessBoard.hpp"
using namespace std;
class Judge
{
public:
    bool isWin(Player *player)
    {
        bool ok = false;
        string chessColor = player->getColor();
        /*horizontal 水平*/
        ok = isHorizontalWin(player->getColor());
        if (ok)
        {
            return ok;
        }
        ok = isVerticalWin(player->getColor());
        if (ok)
        {
            return ok;
        }
        ok = isUphillWin(player->getColor());
        if (ok)
        {
            return ok;
        }
        ok = isDownhillWin(player->getColor());
        if (ok)
        {
            return ok;
        }
        return ok;
    }
    bool isHorizontalWin(const string &color)
    {
        int count = 1;
        ChessBoard *chessBoard = ChessBoard::getChessBoard();
        int line = chessBoard->getCurrentLine();
        int column = chessBoard->getCurrentColumn();
        // 水平方向 列增加
        for (int i = 1; i < 5; i++)
        {
            if (chessBoard->isSameColorChess(color, line, column + i))
            {
                count++;
            }
            else
                break;
        }

        if (count >= 5)
        {
            return true;
        }
        for (int i = 1; i <= 4; i++)
        {
            if (chessBoard->isSameColorChess(color, line, column - i))
            {
                count++;
                if (count >= 5)
                {
                    return true;
                }
            }
            else
                break;
        }
        return false;
    }

    bool isVerticalWin(const string color)
    {

        int count = 1;
        ChessBoard *chessBoard = ChessBoard::getChessBoard();
        int line = chessBoard->getCurrentLine();
        int column = chessBoard->getCurrentColumn();
        // 水平方向 列增加
        for (int i = 1; i < 5; i++)
        {
            if (chessBoard->isSameColorChess(color, line + i, column))
            {
                count++;
            }
            else
                break;
        }

        if (count >= 5)
        {
            return true;
        }
        for (int i = 1; i <= 4; i++)
        {
            if (chessBoard->isSameColorChess(color, line - i, column))
            {
                count++;
                if (count >= 5)
                {
                    return true;
                }
            }
            else
                break;
        }
        return false;
    }
    bool isUphillWin(const string color)
    {
        {
            int count = 1;
            ChessBoard *chessBoard = ChessBoard::getChessBoard();
            int line = chessBoard->getCurrentLine();
            int column = chessBoard->getCurrentColumn();
            // 水平方向 列增加
            for (int i = 1; i < 5; i++)
            {
                if (chessBoard->isSameColorChess(color, line - i, column + i))
                {
                    count++;
                }
                else
                    break;
            }

            if (count >= 5)
            {
                return true;
            }
            for (int i = 1; i <= 4; i++)
            {
                if (chessBoard->isSameColorChess(color, line + i, column - i))
                {
                    count++;
                    if (count >= 5)
                    {
                        return true;
                    }
                }
                else
                    break;
            }
            return false;
        }
    }
    bool isDownhillWin(const string color)
    {
        {
            int count = 1;
            ChessBoard *chessBoard = ChessBoard::getChessBoard();
            int line = chessBoard->getCurrentLine();
            int column = chessBoard->getCurrentColumn();
            // 水平方向 列增加
            for (int i = 1; i < 5; i++)
            {
                if (chessBoard->isSameColorChess(color, line + i, column + i))
                {
                    count++;
                }
                else
                    break;
            }

            if (count >= 5)
            {
                return true;
            }
            for (int i = 1; i <= 4; i++)
            {
                if (chessBoard->isSameColorChess(color, line - i, column - i))
                {
                    count++;
                    if (count >= 5)
                    {
                        return true;
                    }
                }
                else
                    break;
            }
            return false;
        }
    }

private:
};
#endif