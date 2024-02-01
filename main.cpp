#include "OrdinaryUser.h"
#include "book.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std::chrono;
int main()
{
    auto time_point = system_clock::now();
    std::cout << duration_cast<years>(time_point.time_since_epoch()).count() << std::endl;;
    return 0;
}