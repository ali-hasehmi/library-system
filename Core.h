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

    static void createDir();

private:
    void loadAllBooks();

    void loadAllUsers();

    void searchAllBooks(int64_t argId);

    void searchAllBooks(std::string argTitle);

    void sortAllBooksId();

    void sortAllBooksTitle();

    LinkedList<Book> m_books_list;
    LinkedList<OrdinaryUser> m_all_user_list;
};

#endif // CORE_H
