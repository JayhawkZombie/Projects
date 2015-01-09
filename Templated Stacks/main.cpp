/**
 * @brief main
 * @return
 */

#include "BoxOfAnything.h"
#include "StackOfAnything.h"
#include <iostream>
#include <stdexcept>
#include <string>

void PrintMenu(int &userChoice);

int main()
{
    StackOfAnything<int> intStack;
    StackOfAnything<char> charStack;

    int userChoice(0);

    while (userChoice >= 1 && userChoice < 9)
    {
        PrintMenu(userChoice);

        if (userChoice == 1)
        {
            int num;
            std::cout << "Enter a number: " << std::endl;
            std::cin >> num;
            intStack.push(num);
        }
        else if (userChoice == 2)
        {
            char c;
            std::cout << "Enter a character: " << std::endl;
            std::cin >> c;
            charStack.push(c);
        }
        else if (userChoice == 3)
        {
            int peeked;
            try
            {
                peeked = intStack.peek();
            }
            catch (std::runtime_error &error)
            {
                std::cout << error.what() << std::endl;
            }
        }
        else if (userChoice == 4)
        {
            char peeked;
            try
            {
                peeked = charStack.peek();
            }
            catch (std::runtime_error &error)
            {
                std::cout << error.what() << std::endl;
            }
        }
        else if (userChoice == 5)
        {
            try
            {
                intStack.pop();
            }
            catch (std::runtime_error &error)
            {
                std::cout << error.what() << std::endl;
            }
        }
        else if (userChoice == 6)
        {
            try
            {
                charStack.pop();
            }
            catch (std::runtime_error &error)
            {
                std::cout << error.what() << std::endl;
            }
        }
        else if (userChoice == 7)
        {
            std::cout << "Size of number stack is " << intStack.size() << std::endl;
        }
        else if (userChoice == 8)
        {
            std::cout << "Size of character stack is " << charStack.size() << std::endl;
        }
        else if (userChoice == 9)
        {
            std::cout << "Exiting..." << std::endl;
        }
    } /** end of the while loop for the user input **/
    /** if the user enters anything below zero or above 9, then the program will exit **/
}

void PrintMenu(int &userChoice)
{
    std::cout << "Select an action:" << std::endl;
    std::cout << "1) Push onto the number stack\n";
    std::cout << "2) Push onto the character stack\n";
    std::cout << "3) Peek at top of number stack\n";
    std::cout << "4) Peek at top of character stack" << std::endl;
    std::cout << "5) Pop top of number stack\n";
    std::cout << "6) Pop top of character stack\n";
    std::cout << "7) Check size of number stack\n";
    std::cout << "8) Check size of character stack\n";
    std::cout << "9) Quit" << std::endl;
    std::cin >> userChoice;
    return;
}
