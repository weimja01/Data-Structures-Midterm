#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include "problem.h"
#include "location.h"
#include "unorderdLinkedList.h"
#include "linkedStack.h"
#include "linkedQueue.h"
#include "linkedListIterator.h"
#include "action.h"

class Game
{
private:
    unorderedLinkedList<Location> trail;
    linkedStack<Problem> problemStack;
    linkedQueue<Action> actionQueue;
    linkedListIterator<Location> currentLocation;

    int health;
    int food;
    bool gameOver;
    int locationCount;

public:
    Game();

    // action management
    void addActionToQueue();
    void executeQueuedAction();
    void executeAction(const Action &action);

    void displayQueuedActions();
    void displayMenu();
    void setupTrail();
    void addProblem(const Problem &prob);
    void displayProblems();
    void solveTopProblem();
    void displayCurrentLocation();
    void displayStatus();
    void moveToNextLocation();
    bool checkWinCondition();
    bool checkLoseCondition();

    void generateRandomProblem();

    void clearScreen();
    void run();
};

#endif