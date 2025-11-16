#include "game.h"

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
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
    problemStack.push(prob);
    std::cout << "\n *** NEW PROBLEM OCCURED ***" << std::endl;
    std::cout << prob << std::endl;
    std::cout << "***************************" << std::endl;
}

void Game::displayProblems()
{
    if (problemStack.isEmptyStack())
    {
        std::cout << "***There are no current problems***\n"
                  << std::endl;
    }
    else
    {
        std::cout << "!!! URGENT PROBLEM (must solve first) !!!" << std::endl;
        Problem topProblem = problemStack.peek();
        std::cout << topProblem << std::endl;
    }
}

void Game::solveTopProblem()
{
    if (problemStack.isEmptyStack())
    {
        std::cout << "\nNo problems to solve! You're good to go.\n"
                  << std::endl;
        return;
    }

    Problem solved = problemStack.pop();

    std::cout << "\n=== SOLVING PROBLEM ===" << std::endl;
    std::cout << solved << std::endl;
    std::cout << "=======================" << std::endl;

    // Apply effects based on problem type
    if (solved.type == "Broken Wagon")
    {
        health -= 10;
        food -= 5;
        std::cout << "You spent time and energy fixing the wagon." << std::endl;
        std::cout << "Lost: 10 health, 5 food" << std::endl;
    }
    else if (solved.type == "Illness")
    {
        health -= 15;
        food -= 10;
        std::cout << "Your party rested to recover from illness." << std::endl;
        std::cout << "Lost: 15 health, 10 food" << std::endl;
    }
    else if (solved.type == "Bad Weather")
    {
        food -= 15;
        std::cout << "You waited out the storm safely." << std::endl;
        std::cout << "Lost: 15 food" << std::endl;
    }
    else if (solved.type == "Snake Bite")
    {
        health -= 25;
        std::cout << "Treated the snake bite. It was serious!" << std::endl;
        std::cout << "Lost: 25 health" << std::endl;
    }

    std::cout << "\n*** PROBLEM SOLVED! ***\n"
              << std::endl;
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

void Game::moveToNextLocation()
{
    if (!problemStack.isEmptyStack())
    {
        std::cout << "\n!!! Cannot travel with unresolved problems !!!" << std::endl;
        std::cout << "Solve your current problem first!\n"
                  << std::endl;
        return;
    }

    linkedListIterator<Location> tempIterator = currentLocation;
    ++tempIterator;

    if (tempIterator == trail.end())
    {
        std::cout << "\nYou're already at the final location!" << std::endl;
        gameOver = true;
        return;
    }
    // Move forward
    ++currentLocation;
    locationCount++;

    // Consume food for travel
    food -= 20;

    std::cout << "\n======================================" << std::endl;
    std::cout << "Traveling to next location..." << std::endl;
    std::cout << "You consumed 20 lbs of food." << std::endl;
    std::cout << "======================================\n"
              << std::endl;
    if (locationCount < 5)
    {
        // Small chance of random problem when traveling (33% chance)
        if (rand() % 3 == 1)
        {
            generateRandomProblem();
        }
        // Random chance of getting 0-3 problems
        int numProblems = rand() % 4; // 0, 1, 2, or 3 problems
        for (int i = 0; i < numProblems; i++)
        {
            generateRandomProblem();
        }

        if (locationCount == 3)
        {
            addProblem(Problem("River Crossing", "The river is high and dangerous!"));
        }
    }
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

void Game::clearScreen()
{

    std::cout << "\033[2J\033[1;1H";
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

    // Add one starting problem for demonstration
    addProblem(Problem("Broken Wagon", "Your wagon needs repair before departing."));

    // Main game loop
    while (!gameOver)
    {
        // Display current state
        clearScreen();

        displayCurrentLocation();
        displayStatus();
        displayProblems();

        // Check lose conditions
        if (checkLoseCondition())
        {
            gameOver = true;
            break;
        }

        // Check win condition
        if (checkWinCondition())
        {
            std::cout << "\n========================================" << std::endl;
            std::cout << "   CONGRATULATIONS!" << std::endl;
            std::cout << "   You reached Oregon City!" << std::endl;
            std::cout << "========================================" << std::endl;
            std::cout << "Final Health: " << health << "/100" << std::endl;
            std::cout << "Final Food: " << food << " lbs" << std::endl;
            std::cout << "========================================\n"
                      << std::endl;
            gameOver = true;
            break;
        }

        // Show menu and get choice
        displayMenu();

        int choice;
        std::cin >> choice;
        std::cin.ignore(); // Clear newline from input buffer

        std::cout << std::endl;

        // Process choice
        switch (choice)
        {
        case 1:
            solveTopProblem();
            break;
        case 2:
            moveToNextLocation();
            break;
        case 3:
            // Detailed status already shown at top of loop
            std::cout << "Status displayed above.\n"
                      << std::endl;
            break;
        case 4:
            // Manual problem addition for testing
            generateRandomProblem();
            break;
        case 5:
            std::cout << "Thanks for playing!" << std::endl;
            gameOver = true;
            break;
        default:
            std::cout << "Invalid choice. Try again.\n"
                      << std::endl;
        }

        std::cout << "\nPress Enter to continue...";
        std::cin.get();
        // clearScreen();
        std::cout << "\n\n";
    }

    std::cout << "Game ended." << std::endl;
}