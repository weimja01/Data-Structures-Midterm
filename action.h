#ifndef ACTION_H
#define ACTION_H
#include <iostream>
#include <string>

struct Action
{
    std::string actionType;

    Action() : actionType("") {}

    Action(std::string type) : actionType(type) {}

    Action(const Action &other) : actionType(other.actionType) {}

    // equality operator
    bool operator==(const Action &other) const
    {
        return (actionType == other.actionType);
    }

    // printing

    friend std::ostream &operator<<(std::ostream &out, const Action &action)
    {
        out << action.actionType;
        return out;
    }
};

#endif