#include "book.h"

Book::Book(const std::string &_title, const std::string &_author, const std::string &_publish_date, Genre _genre)
: m_title(_title),
  m_author(_author),
  m_give_time(0),
  m_is_available(true),
  m_publish_date(_publish_date),
  m_genre(_genre)
{
}
