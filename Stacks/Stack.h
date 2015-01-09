#ifndef STACK_H
#define STACK_H

#include "Box.h"

class StackOfBoxes
{
public:
    StackOfBoxes();
    ~StackOfBoxes();
    bool isEmpty(void) const;
    int size(void) const;
    void push(int _VAL);
    int pop(void);

private:
    Box *m_top;
    int m_size;
};


#endif
