#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <cstdint>
#include <string>
#include "datastream.h"
#include "queue.h"
#include <fstream>

#define BOOK_DIR "./book/"

class OrdinaryUser;

class Book {

public:
    enum Genre {
        Novel,
        Fiction,
        Historical,
        Mystery,
        Biography
    };
    enum CompTag {
        IDBase,
        TitleBase,
    };

    Book(const std::string &_title, const std::string &_author, const std::string &_publish_date, Genre _genre);

    Book();

    int loadFromFile(const std::string &_file_path);

    int saveToFile();

    friend inputDataStream &operator>>(inputDataStream &inputStream, Book &_book);

    friend outputDataStream &operator<<(outputDataStream &outputStream, const Book &_book);

    friend inputDataStream &operator>>(inputDataStream &inputStream, Genre &_genre);

    friend outputDataStream &operator<<(outputDataStream &outputStream, const Genre &_genre);

    friend std::ostream &operator<<(std::ostream &os, const Book &_book);

    bool operator<(const Book &_b)const;

    bool operator>(const Book &_b)const ;

    bool operator==(const Book &_b)const;

    bool operator!=(const Book &_b)const;


    int64_t id();

    std::string title();

    void popLastUserID();

    static void changeCompTag(const CompTag _tag);

    void setAsAvailable();

    void setAsUnAvailable();

    int64_t FirstUserID();

    int64_t giveTime();

    bool isReservationEmpty();

    void idSetter(const int64_t &argId);

    void titleSetter(const std::string &argTitle);

    void addReserve(const int64_t& _user_id);

    void renew(int64_t _days);
    // friend std::istream& operator>>(std::istream &is,Book& _book);
private:
    std::string genreEnumToString(const Book::Genre &_genre) const;

    std::string m_title;
    std::string m_author;
    std::string m_publish_date;
    int64_t m_give_time;
    bool m_is_available;
    queue<int64_t> m_reservation_queue;
    Genre m_genre;
    int64_t m_id;
    static CompTag ms_comp_tag_book; // default on Title Base
};

#endif // BOOK_H