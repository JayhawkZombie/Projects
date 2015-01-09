#ifndef BOX_H
#define BOX_H

class Box
{
public:
    Box();
    void setValue(int _VAL);
    int getValue(void);
    void setPrevious(Box *_PREV);
    Box *getPrevious(void);

private:
    int m_value;
    Box *m_previous;
};



#endif
