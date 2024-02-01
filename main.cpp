#include "LinkedList.h"
#include <iostream>
#include <list>
int main()
{
    std::list<int> new_list;
    LinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    list.push_back(7);
    list.push_back(8);
    list.push_back(9);
    std::cout << "Range Base Loop\n";
    for (auto &e : list)
    {
        std::cout << e << " ";
    }
    std::cout << "\nIterator Base LOOP\n";
    for (LinkedList<int>::iterator it = list.begin(); it != list.end(); it++)
    {
        std::cout << *it << " ";
    }
    
    return 0;
}