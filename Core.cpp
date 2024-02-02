#include "Core.h"

Core::Core()
{
}

void Core::loadAllBooks()
{
    for (const auto &entry : std::filesystem::directory_iterator(BOOK_DIR))
    {
        if (std::filesystem::is_regular_file(entry))
        {

            Book b;
            b.loadFromFile(entry.path().filename().stem().string());
            this->m_books_list.push_back(b);
        }
    }
}

void Core::loadAllUsers()
{
    for (const auto &entry : std::filesystem::directory_iterator(USER_DIR))
    {
        if (std::filesystem::is_regular_file(entry))
        {
            OrdinaryUser u;
            u.loadFromFile(entry.path().filename().stem().string());
            this->m_all_user_list.push_back(u);
        }
    }
}

 void Core::createDir()
{
    try
    {
        if (!std::filesystem::create_directory(BOOK_DIR))
        {
            std::cerr << "[!]Game::manageFileSystem() Error in Creating Map Directory\n";
        }
        if (!std::filesystem::create_directory(USER_DIR))
        {
            std::cerr << "[!]Game::manageFileSystem() Error in Creating User Directory\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
