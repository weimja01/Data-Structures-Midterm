#include <iostream>
#include "unorderdLinkedList.h"
#include "location.h"
#include "linkedStack.h"
#include "problem.h"

int main(){
    //unordered linked list
    unorderedLinkedList<Location> trail;
    linkedStack<Problem> problemStack;

    std::cout << "Is stack Empty? " << (problemStack.isEmptyStack() ?  "Yes" : "No") << std::endl;

    Problem prob1("Broken Wagon", "Your wagon axle broke! must repair");
    Problem prob2("illness", "Someone has dysentery");
    problemStack.push(prob1);
    problemStack.push(prob2);
    std::cout << "Is stack Empty? " << (problemStack.isEmptyStack() ?  "Yes" : "No") << std::endl;

    Location loc1("Independence, Missouri", "Starting point. Time to head west!");
    Location loc2("Kansas River", "A River Crossing. Dangerous but necessary.");

    std::cout << "building the trail...." << std::endl;

    trail.insert(loc1);
    trail.insert(loc2);

    trail.print(std::cout, "\n");
    std::cout << loc2.description <<"\n";

    Problem topProblem = problemStack.peek();
    std::cout << topProblem << std::endl;

    return 0;

}


