/**
  * @author = Kurt Slagle
  * @file = main.cpp Main entry point for program
  *
  *
  *
  **/

#include <iostream>
#include "Stack.h"


int main()
{
    StackOfBoxes stack; /** stack allocated **/
    StackOfBoxes *stackPtr = new StackOfBoxes; /** heap allocated **/

    int sizeOfStack{0};

    for (int i = 1; i <= 10; i++)
    {
        stack.push(i*5);
        stackPtr->push(i*5);
    }


    /** Store the size of the stack BEFORE popping **/
    sizeOfStack = stack.size();

    std::cout << "There are " << sizeOfStack << " items on the stack-allocated stack" << std::endl;

    for (int i = 0; i < sizeOfStack; i++)
    {
        std::cout << "Popping from the top: " << stack.pop() << std::endl;
        /** won't pop anything from stackPtr **/
    }

    delete stackPtr;
}
