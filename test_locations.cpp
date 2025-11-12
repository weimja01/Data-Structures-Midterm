#include <iostream>
#include "unorderdLinkedList.h"
#include "location.h"

int main(){
    //unordered linked list
    unorderedLinkedList<Location> trail;
    Location loc1("Independence, Missouri", "Starting point. Time to head west!");
    Location loc2("Kansas River", "A River Crossing. Dangerous but necessary.");

    std::cout << "building the trail...." << std::endl;

    trail.insert(loc1);
    trail.insert(loc2);

    trail.print(std::cout, "\n");
    std::cout << loc2.description;
    return 0;

}


