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
    Book c;
    std::ifstream i("test.book");
    inputDataStream ods(&i);
    ods >> b;
    std::cout << b;
    std::cout << duration_cast<years>(time_point.time_since_epoch()).count() << std::endl;
    std::cout << sizeof(Book::Genre);
    return 0;
    
}