#ifndef _CHESSBOARD_HEAD_H_
#define _CHESSBOARD_HEAD_H_
#include <iostream>
#define MIN_X 1
#define MAX_X 57
#define MIN_Y 1
#define MAX_Y 29

using namespace std;

class ChessBoard
{
public:
    ~ChessBoard()
    {

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

private:
    ChessBoard() {}
    static ChessBoard *chessBoard;
    static GC gc;
};
ChessBoard *ChessBoard::chessBoard = nullptr;
ChessBoard::GC gc;
#endif