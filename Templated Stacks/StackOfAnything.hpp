/**
  * This is apparently all wrong
  * nothing here is correct
  *
  *
  **/

//#include "StackOfAnything.h"
#include <stdexcept>
#include <iostream>

template<typename T>
StackOfAnything<T>::StackOfAnything()
{
    m_top = nullptr;
    m_size = 0;
}

template<typename T>
StackOfAnything<T>::~StackOfAnything()
{
    while (!isEmpty())
    {
        pop();
    }
}

template<typename T>
bool StackOfAnything<T>::isEmpty() const
{
    if (m_size >0)
        return false;
    else
        return true ;
}

template<typename T>
int StackOfAnything<T>::size() const
{
    return m_size;
}

template<typename T>
void StackOfAnything<T>::push(T value)
{
    T* temp = m_top;
    m_top = new T();
    m_top->setValue(value);
    m_top->setPrevious(temp);
    m_size++;
}

template<typename T>
T StackOfAnything<T>::peek() const throw(std::runtime_error)
{
    if ((m_size <= 0))
    {
        throw std::runtime_error("Peek attempted on an empty stack.");
    }
    else
    {
        std::cout << "The value is: " << m_top->getValue() << std::endl;
    }
}

template<typename T>
T StackOfAnything<T>::pop() throw(std::runtime_error)
{
    if (!isEmpty())
    {
        T tempVal = m_top->getValue();
        T* temp = m_top->getPrevious();
        delete m_top;
        m_top = temp;
        m_size--;
        return tempVal;
    }
    else
    {
        throw std::runtime_error("Pop atempted on an empty stack");
    }
}
