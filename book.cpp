#include "book.h"
#include <string>

Book::CompTag Book::ms_comp_tag_book = Book::TitleBase;

Book::Book(const std::string &_title, const std::string &_author, const std::string &_publish_date, Genre _genre)
        : m_title(_title),
          m_author(_author),
          m_give_time(0),
          m_is_available(true),
          m_publish_date(_publish_date),
          m_genre(_genre) {
    this->m_id = rand();
}

Book::Book()
        : m_give_time(0),
          m_is_available(true) {
    this->m_id = rand();
}

int Book::loadFromFile(const std::string &_file_path) {
    std::ifstream target_file(BOOK_DIR + _file_path + ".book");
    if (!target_file.is_open()) {
        std::cerr << "Book::loadFromFile(string) : Could not open target file\n";
        return -1;
    }
    inputDataStream ids(&target_file);
    ids >> *this;
    target_file.close();
    return 0;
}

int Book::saveToFile() {
    std::ofstream target_file(BOOK_DIR + this->m_title + ".book");
    if (!target_file.is_open()) {
        std::cerr << "Book::loadFromFile(string) : Could not open target file\n";
        return -1;
    }
    outputDataStream ids(&target_file);
    ids << *this;
    target_file.close();
    return 0;
}

void Book::changeCompTag(const CompTag _tag) {
    ms_comp_tag_book = _tag;
}

void Book::setAsAvailable() {
    this->m_is_available = true;
}

void Book::setAsUnAvailable() {
    this->m_is_available = false;
}

int64_t Book::FirstUserID() {
    this->m_reservation_queue.front();
}

int64_t Book::giveTime() {
    return this->m_give_time;
}

bool Book::isReservationEmpty() {
    return this->m_reservation_queue.isEmpty();
}

std::string Book::genreEnumToString(const Book::Genre &_genre) const {
    std::string s[] = {
            "Novel",
            "Fiction",
            "Historical",
            "Mystery",
            "Biography"};
    return s[_genre];
}

inputDataStream &operator>>(inputDataStream &inputStream, Book &_book) {
    inputStream >> _book.m_title >> _book.m_author >>
                _book.m_id >> _book.m_genre >> _book.m_give_time >>
                _book.m_publish_date >> _book.m_is_available >> _book.m_reservation_queue;
    return inputStream;
}

outputDataStream &operator<<(outputDataStream &outputStream, const Book &_book) {
    outputStream << _book.m_title << _book.m_author
                 << _book.m_id << _book.m_genre << _book.m_give_time
                 << _book.m_publish_date << _book.m_is_available << _book.m_reservation_queue;

    return outputStream;
}

inputDataStream &operator>>(inputDataStream &inputStream, Book::Genre &_genre) {
    inputStream >> (int32_t &) _genre;
    return inputStream;
}

outputDataStream &operator<<(outputDataStream &outputStream, const Book::Genre &_genre) {
    outputStream << (int32_t &) _genre;
    return outputStream;
}

std::ostream &operator<<(std::ostream &os, const Book &_book) {
    os << "Title: " << _book.m_title
       << "\nAuthor: " << _book.m_author
       << "\nGenre: " << _book.genreEnumToString(_book.m_genre)
       << "\npublish Date: " << _book.m_publish_date;
    return os;
}

bool Book::operator<(const Book &_b) {
    if (ms_comp_tag_book == CompTag::TitleBase) {
        return this->m_title < _b.m_title;
    }
    if (ms_comp_tag_book == CompTag::IDBase) {
        return this->m_id < _b.m_id;
    }
}

bool Book::operator>(const Book &_b) {
    if (ms_comp_tag_book == CompTag::TitleBase) {
        return this->m_title > _b.m_title;
    }
    if (ms_comp_tag_book == CompTag::IDBase) {
        return this->m_id > _b.m_id;
    }
}

bool Book::operator==(const Book &_b) {
    if (ms_comp_tag_book == CompTag::TitleBase) {
        return this->m_title == _b.m_title;
    }
    if (ms_comp_tag_book == CompTag::IDBase) {
        return this->m_id == _b.m_id;
    }
}

bool Book::operator!=(const Book &_b) {
    if (ms_comp_tag_book == CompTag::TitleBase) {
        return this->m_title != _b.m_title;
    }
    if (ms_comp_tag_book == CompTag::IDBase) {
        return this->m_id != _b.m_id;
    }
}

int64_t Book::id() {
    this->m_id;
}

std::string Book::title() {
    return this->m_title;
}

void Book::popLastUserID() {
    if (!this->m_reservation_queue.isEmpty()) {
        this->m_reservation_queue.dequeue();
    }
}

void Book::idSetter(const int64_t &argId) {
    this->m_id = argId;
}

void Book::titleSetter(const std::string &argTitle) {
    this->m_title = argTitle;
}
