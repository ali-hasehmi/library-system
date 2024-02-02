#ifndef SuperUser_H
#define SuperUser_H

#include "AbstractUser.h"
#include "book.h"
#include "OrdinaryUser.h"
class SuperUser : public AbstractUser
{
public:
    virtual AbstractUser *logIn(const std::string &_user_name, const std::string &_password){};
    virtual int loadFromFile(const std::string &_file_path){};
    virtual int saveToFile(){};
    SuperUser();
    int getBook(OrdinaryUser *_user, Book *_book);
    int giveBook(OrdinaryUser *_user, Book *_book);
    int Reserve(OrdinaryUser *_user, Book *_book);
    int ReNew(OrdinaryUser *_user, Book *_book, int64_t _days);

private:
};
#endif