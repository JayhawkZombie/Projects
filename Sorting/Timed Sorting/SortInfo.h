/**
 * @file SortInfo.h Sorts Lab07
 * @author Kurt Slagle
 * @date November 14th, 2014
 * @due Novemer 14th, 2014
 *
 */

#ifndef SORT_INFO_H
#define SORT_INFO_H

#include <functional>

template<typename T>
class SortInfo
{
public:
    /**
    * @function function pointer to a Sorts class sorting method
    * @return none
    * @param Sorts class sort, string (name of sort method)
    * @pre takes array of type T
    * @post calls the corresponding sorts method
    */
   SortInfo(std::function<void(T[], T)> sort, std::string name);
    /**
    * @function getSort
    * @return returns Sorts class sort function
    * @param array of type T, int (size of array)
    * @pre none
    * @post returns Sorts class sort function
    */
   std::function<void(T[], T)> getSort() const;
    /**
    * @function getName
    * @return none
    * @param none
    * @pre none
    * @post returns the name of the sort method
    */
   std::string getName() const;
    /**
    * @function getTime
    * @return double
    * @param none
    * @pre none
    * @post returns the time it took for the sort function to sort an array
    */
   double getTime() const;
    /**
    * @function setTime
    * @return none
    * @param double
    * @pre takes double, the time it took to sort
    * @post sorts m_time to the time it took to sort
    */
   void setTime(double t);
    /**
    * @function getCount
    * @return int
    * @param none
    * @pre none
    * @post returns the number of numbers that were sorted
    */
   int getCount() const;
    /**
    * @function setCount
    * @return none
    * @param int (the number of numbers sorted)
    * @pre takes number of numbers sorted
    * @post sets the number of the numbers that were sorted
    */
   void setCount(int count);

private:
   std::function<void(T[], T)> m_sort;
   std::string m_name;
   double m_time;
   int m_count;
};

#include "SortInfo.hpp"

#endif
