#ifndef ORDINARY_USER_H
#define ORDINARY_USER_H

#include "AbstractUser.h"
#include "LinkedList.h"
#include "book.h"

class OrdinaryUser : public AbstractUser
{

public:
    enum CompTag
    {
        IDBase,
        UserNameBase
    };

    virtual AbstractUser *logIn(const std::string &_user_name, const std::string &_password) override;
    virtual int loadFromFile(const std::string &_file_path) override;
    virtual int saveToFile() override;
    static void changeCompTag(const CompTag &_tag);
    bool operator>(const OrdinaryUser &_ou);
    bool operator<(const OrdinaryUser &_ou);
    bool operator==(const OrdinaryUser &_ou);
    bool operator!=(const OrdinaryUser &_ou);

private:
    int m_penalty;
    int m_id;
    LinkedList<Book *> m_user_book_list;
    static CompTag m_comp_tag;
};

OrdinaryUser::CompTag m_comp_tag = OrdinaryUser::UserNameBase;
#endif // ORDINARY_USER_H