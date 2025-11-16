#ifndef LINKEDI_H
#define LINKEDI_H
#include <stdexcept>
#include "node.h"

template <class t>
class linkedListIterator
{
public:
    linkedListIterator();
    linkedListIterator(node<t> *);
    t &operator*();
    linkedListIterator<t> operator++();
    bool operator==(const linkedListIterator<t> &) const;
    bool operator!=(const linkedListIterator<t> &) const;

private:
    node<t> *current;
};

template <class t>
linkedListIterator<t>::linkedListIterator()
{
    current = nullptr;
}

template <class t>
linkedListIterator<t>::linkedListIterator(node<t> *ptr)
{
    current = ptr;
}

template <class t>
t &linkedListIterator<t>::operator*()
{
    if (current != nullptr)
    {
        return *(current->data);
    }
   throw std::runtime_error("Cannot dereference null iterator");
}

template <class t>
bool linkedListIterator<t>::operator==(const linkedListIterator<t> &right) const
{
    return this->current == right.current;
}

template <class t>
bool linkedListIterator<t>::operator!=(const linkedListIterator<t> &right) const
{
    return this->current != right.current;
}
template <class t>
linkedListIterator<t> linkedListIterator<t>::operator++()
{
    if (current != nullptr)
    {
        current = current->link;
    }
    return *this;
}

#endif