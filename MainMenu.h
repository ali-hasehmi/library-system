#ifndef MAINMENU_H
#define MAINMENU_H

#include <iostream>
#include "menu.h"
#include "OrdinaryUser.h"
#include "Core.h"

class MainMenu {
    bool isAdmin;
    AbstractUser* mp_user;
public:
    MainMenu();

    bool menu0_loginHandler();

    void menu0_signUpHandler();

    void menu1_normalUser();

    void menu1_adminInterface();
};


#endif //DS_MAINMENU_H
