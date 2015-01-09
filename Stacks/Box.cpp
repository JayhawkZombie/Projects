#include "Box.h"

Box::Box()
{
    m_value = 0;
    m_previous = nullptr;
}

void Box::setValue(int _VAL)
{
    m_value = _VAL;
}

int Box::getValue()
{
    return m_value;
}

void Box::setPrevious(Box *_PREV)
{
    m_previous = _PREV;
}

Box* Box::getPrevious()
{
    return m_previous;
}
