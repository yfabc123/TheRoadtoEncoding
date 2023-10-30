#ifndef _CHESSBOARD_HEAD_H_
#define _CHESSBOARD_HEAD_H_
#include "Chess.hpp"
#include <iostream>
#define MIN_X 1
#define MAX_X 57
#define MIN_Y 1
#define MAX_Y 29
#define LINE 15
#define COLUMN 15
using namespace std;

class ChessBoard
{
public:
    ~ChessBoard()
    {
        for (int i = 0; i < 15; i++)
        {
            for (int j = 0; j < 15; j++)
            {
                if (this->chess_arr[i][j])
                {
                    delete chess_arr[i][j];
                }
            }
        }
        fprintf(stderr, "\033[%d;%dH", MAX_Y + 1, MIN_X);
    }
    static ChessBoard *getChessBoard()
    {
        if (nullptr == chessBoard) // 常量写在左边
        {
            chessBoard = new ChessBoard();
        }
        return chessBoard;
    }
    void show()
    {
        FILE *file = fopen("ChessBoard.txt", "r");
        if (!file)
        {
            perror("fopen");
            return;
        }
        fprintf(stderr, "\033[%d;%dH", MIN_X, MIN_Y); // 将光标移动到1,1这个位置上 下一次输出从这开始

        char buffer[1024];
        while (fgets(buffer, 1024, file))
        {
            fprintf(stderr, "%s", buffer);
        }
    }
    /* 用来自动释放堆区内存以及将光标移动至棋盘下方 */
    class GC
    {
    public:
        ~GC()
        {
            if (chessBoard)
            {
                delete chessBoard;
            }
        }
    };
    void placeChess(const Chess *chess) // 存放棋子
    {
        currentLine = (chess->getY() - 1) / 2;
        currentColum = (chess->getX() - 1) / 4;
        color = chess->getColor();
        chess_arr[currentLine][currentColum] = chess;
        chess->show();
    }
    int getCurrentLine(void) const
    {

        return currentLine;
    }
    int getCurrentColumn(void) const
    {
        return currentColum;
    }
    bool isVaildPosition(int x, int y) // 判断位置是否有效
    {
        if (x < MIN_X || x > MAX_X || y < MIN_Y || y > MAX_Y)
        {
            return false;
        }
        // int row = y - 1 / 2; //bug
        // int column = x - 1 / 4;  //bug

        int temp_row = (y - 1) / 2;
        int temp_column = (x - 1) / 4;

        return chess_arr[temp_row][temp_column] ? false : true;
    }
    ChessBoard()
    {
        for (int i = 0; i < 15; i++)
        {
            for (int j = 0; j < 15; j++)
            {
                chess_arr[i][j] = nullptr;
            }
        }
    }
    // 判断指定棋子和刚刚放下的棋子是否相同
    bool isSameColorChess(string color, int line, int column)
    {
        if (line < 0 || line >= LINE || column < 0 || column > COLUMN)
        {
            return false;
        }
        auto *temp = chess_arr[line][column];
        if (temp == nullptr || temp->getColor() != color)
        {
            return false;
        }
        else
            return true;
    }

private:
    static ChessBoard *chessBoard;
    static GC gc;
    Chess const *chess_arr[LINE][COLUMN]; // 用来存放棋子 const *表示指针指向的值不能修改
    /* 存放刚刚玩家放下的棋子信息 */
    int currentLine;
    int currentColum;
    string color;
};
ChessBoard *ChessBoard::chessBoard = nullptr;
ChessBoard::GC gc;
#endif