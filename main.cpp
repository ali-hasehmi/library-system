#include "LinkedList.h"
#include <iostream>
#include <list>
#include <string>
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
    list.clear();
    // list.pop_back();
    // list.pop_back();
    // list.pop_back();
    // list.pop_back();
    // list.pop_back();
    // list.pop_back();
    // list.pop_back();
    // list.pop_back();
    // list.pop_back();
    list.push_front(15);
    list.push_back(5);
    list.push_front(1);
    // list.pop_front();
    // list.pop_front();
    // list.pop_front();

    std::cout << list.size() << std::endl;
    ;
    LinkedList<std::string> string_list;
    string_list.push_back("alireza");
    string_list.push_back("Borhan");
    string_list.push_back("hey");
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
    // for (LinkedList<std::string>::iterator it = string_list.begin(); it != string_list.end(); ++it)
    // {
    //     std::cout << it->data() << std::endl;
    // }
    return 0;
}