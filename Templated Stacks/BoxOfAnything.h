/**
  *
  *
  *
  */

#ifndef BOX_OF_ANYTHING_H
#define BOX_OF_ANYTHING_H

template <typename T>
class BoxOfAnything
{
public:
    BoxOfAnything(T value);
    BoxOfAnything<T>* getPrevious();
    T getValue();
    void setValue(T value);
    void setPrevious(BoxOfAnything<T>* next);

private:
    BoxOfAnything<T>* m_previous;
    T m_value;
};


#include "BoxOfAnything.hpp"
#endif
