#include "game.h"

Game::Game()
{
    health = 100;
    food = 200;
    gameOver = false;
    locationCount = 1;
    //currentLocation = nullptr;
}

void Game::setupTrail()
{
    Location loc1("Independence, Missouri", "Starting point. Time to head West!");
    Location loc2("Kansas River", "Ariver crossing. Dangerous but necessary.");
    Location loc3("Fort Kearney=", "A rest stop on the plains.");
    Location loc4("Chimney Rock", "Starting point. Time to head West!");
    Location loc5("Independencs, Missouri", "Starting point. Time to head West!");

    trail.insert(loc1);
    trail.insert(loc2);
    trail.insert(loc3);
    trail.insert(loc4);
    trail.insert(loc5);

        //set starting position 
    currentLocation = trail.begin();
    
    std::cout <<"trail established with " << trail.length() << "locations." << std::endl;
    std::cout << "Your journey begins.... \n" << std::endl;
}

void Game::displayCurrentLocation()
{
    if (currentLocation != trail.end())
    {
        Location loc = *currentLocation;
        std::cout << "================================="<<  std:: endl;
        std::cout << "LOCATION " << locationCount << " of " << trail.length() << std::endl;
        std::cout << "=================================" << std::endl;
        std::cout << loc.name << std::endl;
        std::cout<< loc.description << std::endl;
        std:: cout << "=================================" <<std::endl;
    }
}
void Game::addProblem(const Problem &prob)
{
}

void Game::displayProblems()
{
}

void Game::solveTopProblem()
{
}

void Game::displayStatus()
{
}

void Game::moveToNextLocation()
{
}

bool Game::checkWinCondition()
{
    return false;
}

bool Game::checkLoseCondition()
{
    return false;
}

void Game::run()
{   
    //game display
    std:: cout << "========================================" << std::endl;
    std::cout << "     THE OREGON TRAIL" << std::endl;
    std::cout << "========================================\n" << std::endl;
//setup tht trail
    setupTrail();
}
