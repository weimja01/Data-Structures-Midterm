/* Program name: oregonjourney.cpp
 * Author: Jeff Weimer
 * Date last updated: 11/19/25
 * Purpose: Play the game of The Oregon Journey
 */

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
