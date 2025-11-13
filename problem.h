#ifndef PROBLEM_H
#define PROBLEM_H

#include <string>
#include <iostream>

struct Problem
{
    std::string type;
    std::string description;

    Problem(): type(" "), description(" "){}

    Problem(std::string t, std::string d) : type(t), description(d){}

    //copy const
    Problem(const Problem& other) : type(other.type), description(other.description){}

    //equality operator 
    bool operator == (const Problem& other) const{
        return (type == other.type && description == other.description);
    }

    //printing
    friend std::ostream& operator <<(std::ostream& out, const Problem& prob)
    {
        out << "[" << prob.type << "]" << prob.description;
        return out;
    }


};




#endif