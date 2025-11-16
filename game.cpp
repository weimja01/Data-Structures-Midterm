#include "game.h"

Game::Game()
{
    health = 100;
    food = 200;
    gameOver = false;
    locationCount = 1;
}

void Game::displayMenu()
{
    std::cout << "========================================" << std::endl;
    std::cout << "WHAT DO YOU WANT TO DO?" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "1. Solve current problem" << std::endl;
    std::cout << "2. Move to next location" << std::endl;
    std::cout << "3. View detailed status" << std::endl;
    std::cout << "4. Manually add problem (testing)" << std::endl;
    std::cout << "5. Quit game" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Enter choice: ";
}

void Game::setupTrail()
{
    std::cout << "Setting up the Oregon Trail..." << std::endl
              << std::endl;

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
    std::cout << "Your journey begins....\n"
              << std::endl;
}

void Game::addProblem(const Problem &prob)
{
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

void Game::displayStatus()
{
    std::cout << "---PARTY STATUS---" << std::endl;
    std::cout << "Health:" << health << "/100" << std::endl;
    std::cout << "Food:" << food << std::endl;
    std::cout << "------------------\n"
              << std::endl;
}

bool Game::checkWinCondition()
{
    // check if at last location
    linkedListIterator<Location> tempIterator = currentLocation;
    ++tempIterator;
    if (tempIterator == trail.end() && health > 0)
    {
        return true;
    }
    return false;
}

bool Game::checkLoseCondition()
{
    if (health <= 0)
    {
        std::cout << "\n=====================================" << std::endl;
        std::cout << "GAME OVER - Your party didn't survive" << std::endl;
        std::cout << "=====================================" << std::endl;
        return true;
    }

    if (food <= 0)
    {
        std::cout << "\n=====================================" << std::endl;
        std::cout << "GAME OVER - Starved" << std::endl;
        std::cout << "=====================================" << std::endl;
        return true;
    }
    return false;
}

void Game::generateRandomProblem()
{
    int random = rand() % 4;
    switch (random)
    {
    case 0:
        addProblem(Problem("Broken Wagon", "Your wagon axle broke! Must repair before continuing."));
        break;
    case 1:
        addProblem(Problem("Illness", "Someone in your party has dysentery. Rest to recover."));
        break;
    case 2:
        addProblem(Problem("Bad Weather", "A thunderstorm is approaching. Must wait it out."));
        break;
    case 3:
        addProblem(Problem("Snake Bite", "A rattlesnake bit someone! Need immediate treatment."));
        break;
    }
}

void Game::run()
{
    // Game display
    std::cout << "========================================" << std::endl;
    std::cout << "     THE OREGON TRAIL" << std::endl;
    std::cout << "========================================\n"
              << std::endl;

    // Setup the trail
    setupTrail();
    int count = 1;
    for (auto it = trail.begin(); it != trail.end(); ++it)
    {
        Location loc = *it;
        std::cout << "Location " << count << ": " << loc.name << std::endl;
        std::cout << loc.description << std::endl
                  << std::endl;
        count++;
    }

    // Display the starting location
    displayCurrentLocation();
}