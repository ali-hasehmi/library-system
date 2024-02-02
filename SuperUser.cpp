#include "SuperUser.h"
#include <chrono>
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
    if(_book->isReservationEmpty()){

    }
    if (_book->FirstUserID() != _user->id())
    {
        return -1; // indicate rejection of the
    }
    _user->addBook(_book->id());
    _book->setAsUnAvailable();
    _book->popLastUserID();
}
