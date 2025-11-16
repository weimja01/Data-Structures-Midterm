#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"

int main()
{

    srand(time(0));

    Game oregonTrail;

    oregonTrail.run();

    return 0;
}
