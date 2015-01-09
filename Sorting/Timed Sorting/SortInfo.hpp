/**
 * @file SortInfo.hpp Sorts Lab07
 * @author Kurt Slagle
 * @date November 14th, 2014
 * @due Novemer 14th, 2014
 *
 */

//#include "SortInfo.h" // for code completion - will comment out when compiling
#include <string>

template<typename T>
SortInfo<T>::SortInfo(std::function<void(T[], T)> sort, std::string name)
{
    m_sort = sort;
    m_name = name;
}

template<typename T>
std::function<void(T[], T)> SortInfo<T>::getSort() const
{
    return m_sort;
}

template<typename T>
std::string SortInfo<T>::getName() const
{
    return m_name;
}

template<typename T>
void SortInfo<T>::setTime(double t)
{
    m_time = t;
}

template<typename T>
double SortInfo<T>::getTime() const
{
    return m_time;
}

template<typename T>
void SortInfo<T>::setCount(int count)
{
    m_count = count;
}

template<typename T>
int SortInfo<T>::getCount() const
{
    return m_count;
}
