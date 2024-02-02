#ifndef SuperUser_H
#define SuperUser_H

#include "AbstractUser.h"
#include "book.h"
#include "OrdinaryUser.h"
class SuperUser : public AbstractUser
{
public:
    SuperUser();
    int  getBook(OrdinaryUser *_user, Book *_book);
    int giveBook(OrdinaryUser *_user, Book *_book);
    int Reserve(OrdinaryUser *_user, Book *_book);
    int ReNew(OrdinaryUser *_user, Book *_book);
    
private:
};
#endif