#ifndef BOOK_H
#define BOOK_H
#include <cstdint>
#include <string>
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
    Book(const std::string& _title,const std::string& _author,const std::string &_publish_date,Genre _genre);
private:
    std::string m_title;
    std::string m_author;
    std::string m_publish_date;
    int64_t m_give_time;
    bool m_is_available;
    queue<OrdinaryUser *> m_reservation_queue;
    Genre m_genre;
};

#endif // BOOK_H