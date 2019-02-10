/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     Menu class contains a series of messages and
**                  prompts for the user. Menu class also validates
**                  user's input.
*********************************************************************/
#ifndef LAB7_MENU_HPP
#define LAB7_MENU_HPP

#include <iostream>
#include <cstring>
#include <sstream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;

class Menu {
public:
    Menu();
    void startMenu();
    int validateNumber(int min, int max);
    int validateInteger(int min, int max);

private:

};

#endif //LAB7_MENU_HPP