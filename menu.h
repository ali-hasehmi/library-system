#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>

#include "ioworker.h"
#include "ansi_color_code.h"

using MenuOptions = std::vector<std::string>;


#define SELECTED_COLOR GRN
#define NOT_SELECTED_COLOR WHT

class Menu
{

public:
    Menu();
    Menu(const MenuOptions& _menu_options);
    uint32_t size();
    void addNewOption(const std::string& new_option);
    int32_t display();
private:
    void clearScreen();
    void print();
    void parsOption(int32_t key);
    bool isOptionValid(int option);
    MenuOptions m_options;
    int32_t m_current_option;
    IOworker m_worker;

};

#endif // MENU_H