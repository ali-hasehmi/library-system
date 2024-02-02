#ifndef ORDINARY_USER_H
#define ORDINARY_USER_H

#include <filesystem>
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

    OrdinaryUser();
    OrdinaryUser(const std::string &_first_name, const std::string &_last_name, const std::string &_national_code, const std::string &_user_name,const std::string &_password);

    virtual AbstractUser *logIn(const std::string &_user_name, const std::string &_password) override;
    int signUp();
    virtual int loadFromFile(const std::string &_file_path) override;
    virtual int saveToFile() override;
    static void changeCompTag(const CompTag &_tag);
    bool operator>(const OrdinaryUser &_ou);
    bool operator<(const OrdinaryUser &_ou);
    bool operator==(const OrdinaryUser &_ou);
    bool operator!=(const OrdinaryUser &_ou);
    friend inputDataStream &operator>>(inputDataStream &inputStream, OrdinaryUser &_ou);
    friend outputDataStream &operator<<(outputDataStream &outputStream, const OrdinaryUser &_ou);
    void addBook(int64_t _book_id);
    void removeBook(int64_t _book_id);
    int  calculatePenalty(int64_t _diff);
    void idSetter(int id);
    void userNameSetter(std::string argUserName);
private:
    int64_t m_penalty;
    LinkedList<int64_t> m_user_book_id_list;
    static CompTag ms_comp_tag_user;
};


#endif // ORDINARY_USER_H