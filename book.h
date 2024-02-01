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
    enum CompTag
    {
        IDBase,
        TitleBase,
    };
    Book(const std::string &_title, const std::string &_author, const std::string &_publish_date, Genre _genre);
    Book();
    friend inputDataStream &operator>>(inputDataStream &inputStream, Book &_book);
    friend outputDataStream &operator<<(outputDataStream &outputStream, const Book &_book);
    friend inputDataStream &operator>>(inputDataStream &inputStream, Genre &_genre);
    friend outputDataStream &operator<<(outputDataStream &outputStream, const Genre &_genre);
    friend std::ostream &operator<<(std::ostream &os, const Book &_book);
    bool operator<(const Book &_b);
    bool operator>(const Book &_b);
    bool operator==(const Book &_b);
    bool operator!=(const Book &_b);
    static void changeCompTag(const CompTag _tag);
    // friend std::istream& operator>>(std::istream &is,Book& _book);
private:
    std::string genreEnumToString(const Book::Genre &_genre) const;
    std::string m_title;
    std::string m_author;
    std::string m_publish_date;
    int64_t m_give_time;
    bool m_is_available;
    queue<OrdinaryUser *> m_reservation_queue;
    Genre m_genre;
    int64_t m_id;
    static CompTag ms_comp_tag; // default on Title Base
};
Book::CompTag ms_comp_tag = Book::TitleBase;
#endif // BOOK_H