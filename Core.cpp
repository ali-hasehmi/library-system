#include "Core.h"

Core::Core() {
    this->loadAllBooks();
    this->loadAllUsers();
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


Book *Core::searchAllBooks(int64_t argId) {

    Book tempBook;
    tempBook.changeCompTag(Book::IDBase);

    AVL::AvlTree<Book> searchTree(m_books_list);
    tempBook.idSetter(argId);
    return searchTree.search(tempBook);
}


Book *Core::searchAllBooks(std::string argTitle) {

    Book tempBook;
    tempBook.changeCompTag(Book::TitleBase);

    AVL::AvlTree<Book> searchTree(m_books_list);
    tempBook.titleSetter(argTitle);
    return searchTree.search(tempBook);
}


void Core::sortAllBooksId() {
    Book temp;
    temp.changeCompTag(Book::IDBase);

    AVL::AvlTree<Book> searchTree(m_books_list);
    searchTree.print();
}


void Core::sortAllBooksTitle() {
    Book temp;
    temp.changeCompTag(Book::TitleBase);

    AVL::AvlTree<Book> searchTree(m_books_list);
    searchTree.print();
}

void Core::printBookList() {
    for (auto &i: m_books_list) {
        std::cout << i << std::endl;
    }
}


OrdinaryUser *Core::searchUsers(int userId) {
    OrdinaryUser tempUser;
    tempUser.changeCompTag(OrdinaryUser::IDBase);

    AVL::AvlTree<OrdinaryUser> searchTree(m_all_user_list);
    tempUser.idSetter(userId);
    return searchTree.search(tempUser);
}


OrdinaryUser *Core::searchUsers(std::string userName) {
    OrdinaryUser tempUser;
    tempUser.changeCompTag(OrdinaryUser::UserNameBase);
    AVL::AvlTree<OrdinaryUser> searchTree(m_all_user_list);
    tempUser.userNameSetter(userName);
    return searchTree.search(tempUser);
}