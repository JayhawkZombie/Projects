 
#ifndef STACK_OF_ANYTHING_H
#define STACK_OF_ANYTHING_H

#include "BoxOfAnything.h"
#include <stdexcept>

template<typename T>
class StackOfAnything
{
public:
    StackOfAnything();
    ~StackOfAnything();
    bool isEmpty() const;
    int size() const;
    void push(T value);
    T peek() const throw(std::runtime_error);
    T pop() throw(std::runtime_error);
private:
    BoxOfAnything<T>* m_top;
    int m_size;
};


#include "StackOfAnything.hpp"
#endif
