#include "AbstractUser.h"

AbstractUser::AbstractUser(const std::string &_first_name, const std::string &_last_name, const std::string &_national_code, const std::string &_user_name,const std::string &_password)
: m_first_name(_first_name),
  m_last_name(_last_name),
  m_national_code(_national_code),
  m_user_name(_user_name),
  m_password(_password)
{
    this->m_id = rand();
}

int AbstractUser::id()
{
    return this->m_id;
}
