#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include "problem.h"
#include "location.h"
#include "unorderdLinkedList.h"
#include "linkedStack.h"
#include "linkedListIterator.h"

class Game
{
    private:
    unorderedLinkedList<Location> trail;
    linkedStack<Problem> problemStack;
    linkedListIterator<Location> currentLocation;


    int health;
    int food;
    bool gameOver;
    int locationCount;

    public:
    Game();
    void setupTrail();
    // void addProblem(const Problem& prob);
    // void displayProblems();
    // void solveTopProblem();
    void displayCurrentLocation();
    // void displayStatus();
    // void moveToNextLocation();
    // bool checkWinCondition();
    // bool checkLoseCondition();
    void run();
    



};





#endif