#include "Luban.hpp"
#include "Xiangyu.hpp"

void playGame(Hero *hero)
{
    hero->skill();
}
int main()
{
    Luban luban("luban", 100, 10, "red");
    playGame(&luban);

    Xiangyu xiangyu("xiangyu", 200, 200, "blue");
    playGame(&xiangyu);

    return 0;
}