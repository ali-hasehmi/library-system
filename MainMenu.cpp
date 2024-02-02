#include "MainMenu.h"
#include <windows.h>

MainMenu::MainMenu() {
    Menu mainMenu({"Login", "Signup"});
    int option = mainMenu.display();
    switch (option) {
        case 0:
            std::cout << "Login Selected";
            if (menu0_loginHandler()) {
                menu1_normalUser();
            } else {
                menu1_adminInterface();
            }
            break;
        case 1:
            std::cout << "signup Selected";
            menu0_signUpHandler();
            if (menu0_loginHandler()) {
                menu1_normalUser();
            } else {
                menu1_adminInterface();
            }
            break;
    }
}

void MainMenu::menu0_signUpHandler() {
    int res = 0;
    do {
        system("cls");
        if (res) {
            std::cout << "User Already Exists!\n";
            Sleep(1000);
        }
        std::string userName;
        std::string password;
        std::string first_name;
        std::string national_code;
        std::string last_name;
        std::cout << "first name: ";
        std::cin >> first_name;
        std::cout << "last name: ";
        std::cin >> last_name;
        std::cout << "national code : ";
        std::cin >> national_code;
        std::cout << "Username : ";
        std::cin >> userName;
        std::cout << "Password : ";
        std::cin >> password;
        OrdinaryUser ou(first_name, last_name, national_code, userName, password);
        res = ou.signUp();
        std::cout << "end of do While loop\n";
    } while (res);
    std::cout << "user created Successfully;";
    Sleep(1000);
    system("cls");

}

bool MainMenu::menu0_loginHandler() {
    while (true) {
        system("cls");
        std::cout << "Login Selected\n";
        std::string userName;
        std::string userPassword;
        std::cout << "Enter Username : ";
        std::cin >> userName;
        std::cout << "Enter Password : ";
        std::cin >> userPassword;
        if (userName == "admin") {
            /*   user is admin the compare password and etc
                    if (passwordCompare == true) */
            return false;
        } else {
            /*        compare passwords for user
                    if (passwordCompare == true) */
            OrdinaryUser ou;
            if (ou.logIn(userName, userPassword) == nullptr) {
                std::cout << "user not found\n";
            } else {
                std::cout << "logged in successfully\n";
                return true;
            }
        }
    }
}

void MainMenu::menu1_normalUser() {
    Core core(false);
    Menu normalUserMenu1({"Show All Books", "Show My Books", "Search Books", "Sort Books", "Exit"});
    bool loopCondition = true;
    while (loopCondition) {
        int option = normalUserMenu1.display();
        switch (option) {
            case 0:
                // show all books

                break;
            case 1:
                // show my books
                break;
            case 2:{
                // search books

                Menu searchMenu({"Search by ID","Search by Title"});
                int searchOption = searchMenu.display();
                if (!searchOption){
                    system("cls");
                    
                }else{

                }
                break;
            }
            case 3:
                // sort books
                break;
            case 4:
                loopCondition = false;
                break;
            default:
                std::cout << "\nInvalid Option";
                break;
        }
    }
}

void MainMenu::menu1_adminInterface() {
    Core core(true);
    Menu adminMenu1({"Get Book", "Give Book", "Reserve", "ReNew", "Exit"});
    bool loopCondition = true;
    while (loopCondition) {
        int option = adminMenu1.display();
        switch (option) {
            //                Get Book
            case 0: {
                system("cls");
                std::string bookTitle;
                std::string userName;
                std::cout << "Enter book name : ";
                std::cin >> bookTitle;
                std::cout << "Enter book owner : ";
                std::cin >> userName;
                system("cls");
                // code related to changing book ownership goes here
                break;
            }
            case 1: {
                system("cls");
                std::string bookTitle;
                std::string userName;
                std::cout << "Enter book name : ";
                std::cin >> bookTitle;
                std::cout << "Enter book owner : ";
                std::cin >> userName;
                system("cls");
                // code related to giving book goes here
                break;
            }
            case 2: {
                system("cls");
                std::string bookTitle;
                std::string userName;
                std::cout << "Enter book name : ";
                std::cin >> bookTitle;
                std::cout << "Enter book owner : ";
                std::cin >> userName;
                system("cls");
                //                code related to reserving book
                break;
            }
            case 3: {
                system("cls");
                std::string bookTitle;
                std::string userName;
                int extendedPeriod;
                std::cout << "Enter book name : ";
                std::cin >> bookTitle;
                std::cout << "Enter book owner : ";
                std::cin >> userName;
                std::cout << "Enter time to extend : ";
                std::cin >> extendedPeriod;
                system("cls");
                //                code to reNew
                break;
            }
            case 4:
                loopCondition = false;
                break;
            default:
                std::cout << "\nInvalid Option";
                break;
        }
    }
}
