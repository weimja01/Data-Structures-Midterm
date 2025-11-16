#include "game.h"

Game::Game()
{
    health = 100;
    food = 200;
    gameOver = false;
    locationCount = 1;
}

void Game::setupTrail()
{
    std::cout << "Setting up the Oregon Trail..." << std::endl << std::endl;
    
    Location loc1("Independence, Missouri", "Starting point. Time to head West!");
    Location loc2("Kansas River", "A river crossing. Dangerous but necessary.");
    Location loc3("Fort Kearney", "A rest stop on the plains.");
    Location loc4("Chimney Rock", "A famous landmark. Halfway there!");
    Location loc5("Oregon City", "You made it! The end of the trail!");
    
    trail.insert(loc1);
    trail.insert(loc2);
    trail.insert(loc3);
    trail.insert(loc4);
    trail.insert(loc5);
    
    // Set starting position 
    currentLocation = trail.begin();
    
    std::cout << "Trail established with " << trail.length() << " locations." << std::endl;
    std::cout << "Your journey begins....\n" << std::endl;
}

void Game::displayCurrentLocation()
{
    if (currentLocation != trail.end())
    {
        Location loc = *currentLocation;
        std::cout << "=================================" << std::endl;
        std::cout << "LOCATION " << locationCount << " of " << trail.length() << std::endl;
        std::cout << "=================================" << std::endl;
        std::cout << loc.name << std::endl;
        std::cout << loc.description << std::endl;
        std::cout << "=================================" << std::endl;
    }
}

void Game::run()
{   
    // Game display
    std::cout << "========================================" << std::endl;
    std::cout << "     THE OREGON TRAIL" << std::endl;
    std::cout << "========================================\n" << std::endl;
    
    // Setup the trail
    setupTrail();
    int count = 1;
    for (auto it = trail.begin(); it != trail.end(); ++it) {
        Location loc = *it;
        std::cout << "Location " << count << ": " << loc.name <<std:: endl;
        std::cout << loc.description << std::endl << std::endl;
        count++;
    }
    
    // Display the starting location
    displayCurrentLocation();
}