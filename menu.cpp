#include <iostream>

#include "menu.h"

Menu::Menu()
    : m_current_option(0),
      m_options({"NULL", "NULL", "NULL"})
{
}

Menu::Menu(const MenuOptions &_menu_options)
    : m_current_option(0),
      m_options(_menu_options)
{
}

uint32_t Menu::size()
{
    return this->m_options.size();
}

void Menu::addNewOption(const std::string &new_option)
{
    this->m_options.push_back(new_option);
}

int32_t Menu::display()
{
    uint32_t val;
    this->m_worker.start();
    this->print();
    while ((val = this->m_worker.key()) != KEY_ENTER)
    {
        if (val != KEY_NULL)
        {
            this->parsOption(val);
            this->print();
        }
    }
    this->m_worker.stop();
    return this->m_current_option;
}

void Menu::clearScreen()
{
    std::system("cls || clear");
}

void Menu::print()
{
    // First Clear the Screen
    this->clearScreen();
    // Iterate over all options and print them
    for (size_t i = 0; i < this->m_options.size(); i++)
    {
        // Check If the Current Options has been selected,
        // Print it with Special Color
        if (i == this->m_current_option)
        {
            std::cout << SELECTED_COLOR << this->m_options.at(i) << COLOR_RESET;
        }
        else
        {
            std::cout << NOT_SELECTED_COLOR << this->m_options.at(i) << COLOR_RESET;
        }
        std::cout << "\n";
    }
}

void Menu::parsOption(int32_t key)
{

    if (key == KEY_DOWN && this->isOptionValid(this->m_current_option + 1))
    {
        this->m_current_option++;
        return;
    }
    if (key == KEY_UP && this->isOptionValid(this->m_current_option - 1))
    {
        this->m_current_option--;
        return;
    }
}

bool Menu::isOptionValid(int option)
{
    /* If option is out of bound */
    if (option < 0 || option > this->m_options.size() - 1)
    {
        return false;
    }
    return true;
}
