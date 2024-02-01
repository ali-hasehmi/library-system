#include "OrdinaryUser.h"

AbstractUser *OrdinaryUser::logIn(const std::string &_user_name, const std::string &_password)
{
    this->m_id = rand();
}

int OrdinaryUser::loadFromFile(const std::string &_file_path)
{
    return 0;
}

int OrdinaryUser::saveToFile()
{
    return 0;
}

void OrdinaryUser::changeCompTag(const CompTag &_tag)
{
    m_comp_tag = _tag;
}

bool OrdinaryUser::operator>(const OrdinaryUser &_ou)
{
    if (ms_comp_tag == OrdinaryUser::UserNameBase)
    {
        return this->m_user_name > _ou.m_user_name;
    }
    if (ms_comp_tag == OrdinaryUser::IDBase)
    {
        return this->m_id > _ou.m_id;
    }
}

bool OrdinaryUser::operator<(const OrdinaryUser &_ou)
{
    if (ms_comp_tag == OrdinaryUser::UserNameBase)
    {
        return this->m_user_name < _ou.m_user_name;
    }
    if (ms_comp_tag == OrdinaryUser::IDBase)
    {
        return this->m_id < _ou.m_id;
    }
}

bool OrdinaryUser::operator==(const OrdinaryUser &_ou)
{
    if (ms_comp_tag == OrdinaryUser::UserNameBase)
    {
        return this->m_user_name == _ou.m_user_name;
    }
    if (ms_comp_tag == OrdinaryUser::IDBase)
    {
        return this->m_id == _ou.m_id;
    }
}

bool OrdinaryUser::operator!=(const OrdinaryUser &_ou)
{
    if (ms_comp_tag == OrdinaryUser::UserNameBase)
    {
        return this->m_user_name != _ou.m_user_name;
    }
    if (ms_comp_tag == OrdinaryUser::IDBase)
    {
        return this->m_id != _ou.m_id;
    }
}
