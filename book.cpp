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

inputDataStream &operator>>(inputDataStream &inputStream, Book &_book)
{
    inputStream >> _book.m_title >> _book.m_author >>
        _book.m_genre >> _book.m_give_time >>
        _book.m_publish_date >> _book.m_is_available;
}

outputDataStream &operator<<(outputDataStream &outputStream, const Book &_book)
{
    outputStream << _book.m_title << _book.m_author
                 << _book.m_genre << _book.m_give_time
                 << _book.m_publish_date << _book.m_is_available;

    return outputStream;
}

inputDataStream &operator>>(inputDataStream &inputStream, Book::Genre &_genre)
{
    inputStream >> (int32_t&)_genre;
    return inputStream;
}

outputDataStream &operator<<(outputDataStream &outputStream, const Book::Genre &_genre)
{
    outputStream << (int32_t&)_genre;
    return outputStream;
}
