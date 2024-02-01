#include "OrdinaryUser.h"
#include "book.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>
using namespace std::chrono;
int main()
{
    auto time_point = system_clock::now();
    Book b("One Night","Nemo","11/13/1382",Book::Mystery);
    std::ofstream o("test.book");
    outputDataStream ods(&o);
    ods << b;
    
    std::cout << duration_cast<years>(time_point.time_since_epoch()).count() << std::endl;;
    std::cout << sizeof(Book::Genre);
    return 0;
    
}