#include "Core.h"

Core::Core() {
}

Core::Core(bool isAdmin) {
    if (isAdmin) {
        loadAllBooks();
        loadAllUsers();
    } else {
        loadAllBooks();
    }
}

void Core::loadAllBooks() {
    for (const auto &entry: std::filesystem::directory_iterator(BOOK_DIR)) {
        if (std::filesystem::is_regular_file(entry)) {

            Book b;
            b.loadFromFile(entry.path().filename().stem().string());
            this->m_books_list.push_back(b);
        }
    }
}

void Core::loadAllUsers() {
    for (const auto &entry: std::filesystem::directory_iterator(USER_DIR)) {
        if (std::filesystem::is_regular_file(entry)) {
            OrdinaryUser u;
            u.loadFromFile(entry.path().filename().stem().string());
            this->m_all_user_list.push_back(u);
        }
    }
}

void Core::createDir() {
    try {
        if (!std::filesystem::create_directory(BOOK_DIR)) {
            std::cerr << "[!]Game::manageFileSystem() Error in Creating Map Directory\n";
        }
        if (!std::filesystem::create_directory(USER_DIR)) {
            std::cerr << "[!]Game::manageFileSystem() Error in Creating User Directory\n";
        }
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void Core::searchAllBooks(int64_t argId) {
    for (auto &i: m_books_list) {
        i.changeCompTag(Book::IDBase);
    }
    AVL::AvlTree<Book> searchTree(m_books_list);
    Book tempBook;
    tempBook.idSetter(argId);
    searchTree.search(tempBook);
}

void Core::searchAllBooks(std::string argTitle) {
    for (auto &i: m_books_list) {
        i.changeCompTag(Book::TitleBase);
    }
    AVL::AvlTree<Book> searchTree(m_books_list);
    Book tempBook;
    tempBook.titleSetter(argTitle);
    searchTree.search(tempBook);
}

void Core::sortAllBooksId() {
    for (auto &i: m_books_list) {
        i.changeCompTag(Book::IDBase);
    }
    AVL::AvlTree<Book> searchTree(m_books_list);
    searchTree.print();
}

void Core::sortAllBooksTitle() {
    for (auto &i: m_books_list) {
        i.changeCompTag(Book::TitleBase);
    }
    AVL::AvlTree<Book> searchTree(m_books_list);
    searchTree.print();
}

void Core::printBookList() {
    for (auto &i:m_books_list) {
        std::cout << i << std::endl;
    }
}

void Core::searchUsers(int userId) {
    for (auto &i:m_all_user_list) {
        i.changeCompTag(OrdinaryUser::IDBase);
    }
    AVL::AvlTree<OrdinaryUser> searchTree(m_all_user_list);
    searchTree.search()
}

void Core::searchUsers(std::string userName) {

}
