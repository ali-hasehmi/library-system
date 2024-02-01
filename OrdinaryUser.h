#ifndef ORDINARY_USER_H
#define ORDINARY_USER_H

#include "AbstractUser.h"
#include "LinkedList.h"
#include "book.h"

class OrdinaryUser : public AbstractUser
{
    public:
    virtual AbstractUser *logIn(const std::string &_user_name, const std::string &_password) override;
    virtual int loadFromFile(const std::string & _file_path) override;
    virtual int saveToFile() override;
    private:
    int m_penalty;
    LinkedList<Book*> m_user_book_list;

};


#endif // ORDINARY_USER_H