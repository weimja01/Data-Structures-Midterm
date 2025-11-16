#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"

int main()
{

    srand(time(0));

    // // Create and run game
    Game oregonTrail;
    oregonTrail.addActionToQueue();

    // oregonTrail.run();

    return 0;
}
