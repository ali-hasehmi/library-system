#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <cstdint>
#include <string>
#include "datastream.h"
#include "queue.h"
class OrdinaryUser;
class Book
{

public:
    enum Genre
    {
        Novel,
        Fiction,
        Historical,
        Mystery,
        Biography
    };
    Book(const std::string &_title, const std::string &_author, const std::string &_publish_date, Genre _genre);
    Book();
    friend inputDataStream &operator>>(inputDataStream &inputStream, Book &_book);
    friend outputDataStream &operator<<(outputDataStream &outputStream, const Book &_book);
    friend inputDataStream &operator>>(inputDataStream &inputStream, Genre &_genre);
    friend outputDataStream &operator<<(outputDataStream &outputStream, const Genre &_genre);
    friend std::ostream& operator<<(std::ostream &os, const Book& _book);
    //friend std::istream& operator>>(std::istream &is,Book& _book);
private:
    std::string genreEnumToString(const Book::Genre& _genre)const;
    std::string m_title;
    std::string m_author;
    std::string m_publish_date;
    int64_t m_give_time;
    bool m_is_available;
    queue<OrdinaryUser *> m_reservation_queue;
    Genre m_genre;
};

#endif // BOOK_H