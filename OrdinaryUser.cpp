#include "OrdinaryUser.h"

#include <iostream>
OrdinaryUser::CompTag OrdinaryUser::ms_comp_tag_user = OrdinaryUser::UserNameBase;

OrdinaryUser::OrdinaryUser()
    : m_penalty(0),
      AbstractUser("Black", "Box", "00000000000", "blackbox1", "12345")
{
    this->m_id = rand();
}

OrdinaryUser::OrdinaryUser(const std::string &_first_name, const std::string &_last_name, const std::string &_national_code, const std::string &_user_name, const std::string &_password)
    : AbstractUser(_first_name, _last_name, _national_code, _user_name, _password)
{
}

AbstractUser *OrdinaryUser::logIn(const std::string &_user_name, const std::string &_password)
{
    for (const auto &entry : std::filesystem::directory_iterator(USER_DIR))
    {
        if (std::filesystem::is_regular_file(entry))
        {

            if ((entry.path().filename().stem().string()) == _user_name)
            {
                AbstractUser *login_user = new OrdinaryUser();
                ((OrdinaryUser *)login_user)->loadFromFile(entry.path().filename().stem().string());
                if (((OrdinaryUser *)login_user)->m_password == _password)
                {
                    return login_user;
                }
                delete login_user;
            }
        }
    }
    return nullptr;
}

int OrdinaryUser::signUp()
{
    for (const auto &entry : std::filesystem::directory_iterator(USER_DIR))
    {
        if (std::filesystem::is_regular_file(entry))
        {

            if ((entry.path().filename().stem().string()) == this->m_user_name)
            {
                return -1; // User Already Exist
            }
        }
    }
    this->saveToFile();
    std::cout << "int OrdinaryUser::signUp() passed\n";
    return 0;
}

int OrdinaryUser::loadFromFile(const std::string &_file_path)
{
    std::ifstream target_file(USER_DIR + _file_path + ".user");
    if(!target_file.is_open()){
        return -1;
    }
    inputDataStream isd(&target_file);
    isd >> *this;
    target_file.close();
    return 0;
}

int OrdinaryUser::saveToFile()
{
    std::ofstream target_file(USER_DIR + this->m_user_name + ".user");
    if(!target_file.is_open()){
        return -1;
    }
    outputDataStream osd(&target_file);
    osd << *this;
    target_file.close();
    std::cout << "int OrdinaryUser::saveToFile() passed\n";
    return 0;
}

void OrdinaryUser::changeCompTag(const CompTag &_tag)
{
    ms_comp_tag_user = _tag;
}

bool OrdinaryUser::operator>(const OrdinaryUser &_ou)
{
    if (ms_comp_tag_user == OrdinaryUser::UserNameBase)
    {
        return this->m_user_name > _ou.m_user_name;
    }
    if (ms_comp_tag_user == OrdinaryUser::IDBase)
    {
        return this->m_id > _ou.m_id;
    }
}

bool OrdinaryUser::operator<(const OrdinaryUser &_ou)
{
    if (ms_comp_tag_user == OrdinaryUser::UserNameBase)
    {
        return this->m_user_name < _ou.m_user_name;
    }
    if (ms_comp_tag_user == OrdinaryUser::IDBase)
    {
        return this->m_id < _ou.m_id;
    }
}

bool OrdinaryUser::operator==(const OrdinaryUser &_ou)
{
    if (ms_comp_tag_user == OrdinaryUser::UserNameBase)
    {
        return this->m_user_name == _ou.m_user_name;
    }
    if (ms_comp_tag_user == OrdinaryUser::IDBase)
    {
        return this->m_id == _ou.m_id;
    }
}

bool OrdinaryUser::operator!=(const OrdinaryUser &_ou)
{
    if (ms_comp_tag_user == OrdinaryUser::UserNameBase)
    {
        return this->m_user_name != _ou.m_user_name;
    }
    if (ms_comp_tag_user == OrdinaryUser::IDBase)
    {
        return this->m_id != _ou.m_id;
    }
}

void OrdinaryUser::addBook(int64_t _book_id)
{
    this->m_user_book_id_list.push_back(_book_id);
}

void OrdinaryUser::removeBook(int64_t _book_id)
{
    this->m_user_book_id_list.remove(_book_id);
}

inputDataStream &operator>>(inputDataStream &inputStream, OrdinaryUser &_ou)
{
    inputStream >> _ou.m_first_name >> _ou.m_last_name >> _ou.m_national_code >> _ou.m_password >>
        _ou.m_user_name >> _ou.m_user_book_id_list >> _ou.m_penalty;
    return inputStream;
}

outputDataStream &operator<<(outputDataStream &outputStream, const OrdinaryUser &_ou)
{
    outputStream << _ou.m_first_name << _ou.m_last_name << _ou.m_national_code << _ou.m_password
                 << _ou.m_user_name << _ou.m_user_book_id_list << _ou.m_penalty;
    std::cout << "outputDataStream &operator<<(outputDataStream &outputStream, const OrdinaryUser &_ou) passed\n";
    return outputStream;
}
