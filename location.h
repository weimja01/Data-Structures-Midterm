#ifndef LOCATION_H
#define  LOCATION_H
#include <string>
#include <iostream>
#include <ostream>

struct Location {

    std::string name;
    std::string description;

    //constructor
    Location(): 
    name(" "), 
    description(" ")
    {

    }
    // parameterized constructor
    Location(std::string n, std::string d): name(n), description(d)
    {

    }
    //copy constructor
    Location(const Location& other): name(other.name), description(other.description)
    {

    }

    //equality operator
    bool operator ==(const Location&other) const {
        return(name==other.name);
    }

    bool operator!=(const Location& other) const{
        return !(*this == other);
    }
    
    friend std::ostream& operator << (std::ostream& out, const Location& loc)
    {
        out << loc.name;
        return out;
    }

};



#endif