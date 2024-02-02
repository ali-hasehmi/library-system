#ifndef ABSTRACT_USER_H
#define ABSTRACT_USER_H

#include <string>
#include <fstream>

#define USER_DIR "./user/"

class AbstractUser
{

public:
    virtual AbstractUser *logIn(const std::string &_user_name, const std::string &_password) = 0;
    virtual int loadFromFile(const std::string &_file_path) = 0;
    virtual int saveToFile() = 0;
    AbstractUser(const std::string &_first_name, const std::string &_last_name, const std::string &_national_code, const std::string &_user_name, const std::string &_password);
    int id();
protected:
    std::string m_first_name;
    std::string m_last_name;
    std::string m_national_code;
    std::string m_user_name;
    std::string m_password;
    int m_id;
};

#endif // ABSTRACT_USER_H