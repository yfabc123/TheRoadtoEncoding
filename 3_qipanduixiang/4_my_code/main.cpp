#include "ChessBoard.hpp"
#include "BlackChess.hpp"
#include "WhiteChess.hpp"
#include <iostream>
using namespace std;
int main()
{
    fprintf(stderr, "\033[2J"); // 清屏

    ChessBoard *chessboard = ChessBoard::getChessBoard();
    chessboard->show();

    BlackChess blackchess(5, 1);
    // blackchess.show();
    WhiteChess whitechess(5, 3);
    // whitechess.show();

    chessboard->placeChess(&blackchess);
    chessboard->placeChess(&whitechess);

    if (chessboard->isVaildPosition(17, 1))
    {
        chessboard->placeChess(new BlackChess(17, 1));
    }

    return 0;
}
