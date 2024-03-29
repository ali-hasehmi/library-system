#include "SuperUser.h"
#include <chrono>
SuperUser::SuperUser() : AbstractUser("Ali", "Hashemi", "012345657", "admin", "1234")
{
}
int SuperUser::getBook(OrdinaryUser *_user, Book *_book)
{
    using namespace std::chrono;
    _user->removeBook(_book->id());
    int64_t giveBookTime = _book->giveTime();
    int64_t Now = duration_cast<days>(std::chrono::system_clock::now().time_since_epoch()).count();
    _book->setAsAvailable();
    _user->saveToFile();
    _book->saveToFile();
    return _user->calculatePenalty(Now - giveBookTime);
}

int SuperUser::giveBook(OrdinaryUser *_user, Book *_book)
{
    std::cout << "int SuperUser::giveBook(OrdinaryUser *_user, Book *_book) : started\n";
    if (_book->isReservationEmpty())
    {
        std::cout << "int SuperUser::giveBook(OrdinaryUser *_user, Book *_book) : reservation is empty\n";
        _user->addBook(_book->id());
        std::cout << "int SuperUser::giveBook(OrdinaryUser *_user, Book *_book) : book added\n";
        _book->setAsUnAvailable();
        std::cout << "int SuperUser::giveBook(OrdinaryUser *_user, Book *_book) : set as unAvailable\n";
        _user->saveToFile();
        _book->saveToFile();
        return 0;
    }
    std::cout << "int SuperUser::giveBook(OrdinaryUser *_user, Book *_book) : reservation is not empty\n";

    if (_book->FirstUserID() == _user->id())
    {
        _user->addBook(_book->id());
        _book->setAsUnAvailable();
        _book->setAsUnAvailable();
        _book->popLastUserID();
        _user->saveToFile();
        _book->saveToFile();
        return 0;
    }
    return -1;
}

int SuperUser::Reserve(OrdinaryUser *_user, Book *_book)
{
    _book->addReserve(_user->id());
    _user->saveToFile();
    _book->saveToFile();
    return 0;
}

int SuperUser::ReNew(OrdinaryUser *_user, Book *_book, int64_t _days)
{
    if (!_book->isReservationEmpty())
    {
        return -1; // Can Not renew the subscription for the book
    }
    _book->renew(_days);
    _user->saveToFile();
    _book->saveToFile();
    return 0;
}
