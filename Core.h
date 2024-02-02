#ifndef CORE_H
#define CORE_H

#include <filesystem>

#include "LinkedList.h"
#include "book.h"
#include "OrdinaryUser.h"
#include "AvlTree.h"

class Core {
public:
    Core();

    Core(bool isAdmin);

    static void createDir();

    Book *searchAllBooks(int64_t argId);

    Book *searchAllBooks(std::string argTitle);

    void sortAllBooksId();

    void sortAllBooksTitle();

    void printBookList();

    OrdinaryUser *searchUsers(int userId);

    OrdinaryUser *searchUsers(std::string userName);

private:
    void loadAllBooks();

    void loadAllUsers();


    LinkedList<Book> m_books_list;
    LinkedList<OrdinaryUser> m_all_user_list;
};

#endif // CORE_H
