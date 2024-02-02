#include "SuperUser.h"

void SuperUser::getBook(OrdinaryUser *_user, Book *_book)
{
    _user->removeBook(_book->id());
    _book.
    _book->setAsAvailable();
}
