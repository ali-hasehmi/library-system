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
    int64_t Now = duration_cast<days>(std::chrono::system_clock::now().time_since_epoch());
    _book->setAsAvailable();
    return _user->calculatePenalty(Now - giveBookTime);
}

int SuperUser::giveBook(OrdinaryUser *_user, Book *_book)
{
    if (_book->isReservationEmpty())
    {
        _user->addBook(_book->id());
        _book->setAsUnAvailable();
        return 0;
    }
    if (_book->FirstUserID() == _user->id())
    {
        _user->addBook(_book->id());
        _book->setAsUnAvailable();
        _book->setAsUnAvailable();
        _book->popLastUserID();
        return 0;
    }
    return -1;
}

int SuperUser::Reserve(OrdinaryUser *_user, Book *_book)
{
    _book->addReserve(_user->id());
    return 0;
}

int SuperUser::ReNew(OrdinaryUser *_user, Book *_book, int64_t _days)
{
    if (!_book->isReservationEmpty())
    {
        return -1; // Can Not renew the subscription for the book
    }
    _book->renew(_days);
    return 0;
}
