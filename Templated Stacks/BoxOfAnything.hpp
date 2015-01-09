/** @author = Kurt Slagle
  * @file = implementation of BoxOfAnything
  *
  *
  *
  **/

//#include "BoxOfAnything.h"

template<typename T>
BoxOfAnything<T>::BoxOfAnything(T value)
{
    m_value = value;
    m_previous = nullptr;
}

template<typename T>
BoxOfAnything<T>* BoxOfAnything<T>::getPrevious()
{
    return m_previous;
}

template<typename T>
T BoxOfAnything<T>::getValue()
{
    return m_value;
}

template<typename T>
void BoxOfAnything<T>::setValue(T value)
{
    m_value = value;
}

template<typename T>
void BoxOfAnything<T>::setPrevious(BoxOfAnything<T> *next)
{
    m_previous = next;
}
