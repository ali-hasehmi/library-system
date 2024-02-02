// #include "book.h"
#include "OrdinaryUser.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>
#include "queue.h"

using namespace std::chrono;

int main()
{
    //    auto time_point = system_clock::now();
    //    Book b("One Night", "Nemo", "11/13/1382", Book::Mystery);
    //    Book c;
    //    inputDataStream ods(&i);
    //    ods >> b;
    //    std::cout << b;
    queue<int> bigQ(5);
    for (int i = 0; i < 5; ++i)
    {
        bigQ.enqueue(i);
    }
    std::ofstream i("test.txt");
    outputDataStream osd(&i);
    osd << bigQ;
    i.close();
    std::cout << bigQ.capacity()  << " "<<bigQ.count() << std::endl;
    queue<int> lilQ;
    std::ifstream in("test.txt");
    inputDataStream isd(&in);
    isd >> lilQ;
    for (int j = 0; j < lilQ.capacity(); ++j)
    {
        std::cout << lilQ.dequeue() << " ";
    }
    std::cout << std::endl << lilQ.capacity() << " " <<bigQ.count() << std::endl;
    //    std::cout << duration_cast<years>(time_point.time_since_epoch()).count() << std::endl;
    //    std::cout << sizeof(Book::Genre);
    return 0;
}