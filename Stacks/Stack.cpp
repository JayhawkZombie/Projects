#include "Stack.h"

StackOfBoxes::StackOfBoxes()
{
    m_top = nullptr;
    m_size = 0;
}

StackOfBoxes::~StackOfBoxes()
{
    while (!isEmpty())
    {
        pop();
    }
}

bool StackOfBoxes::isEmpty() const
{
    if (m_size > 0)
        return false;
    else
        return true;
}

int StackOfBoxes::size() const
{
    return m_size;
}

void StackOfBoxes::push(int _VAL)
{
    Box *temp = m_top;
    m_top = new Box();
    m_top->setValue(_VAL);
    m_top->setPrevious(temp);
    m_size++;
}

int StackOfBoxes::pop()
{
    if (!isEmpty())
    {
        int temp_val = m_top->getValue();
        Box *temp = m_top->getPrevious();
        delete m_top;
        m_top = temp;
        m_size--;
        return temp_val;
    }
    else
        return 0; /** what?  We should throw an exception if the stack is empty **/
}
