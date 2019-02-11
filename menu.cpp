/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     Menu class contains a series of messages and
**                  prompts for the user. Menu class also validates
**                  user's input.
*********************************************************************/
#include "menu.hpp"

/*********************************************************************
** Description:     no-args default constructor
*********************************************************************/
Menu::Menu() {}

/*********************************************************************
** Description:     start menu that prompts user to select an option
*********************************************************************/
void Menu::startMenu() {
    cout << "WELCOME TO MY QUEUE!\n";
    cout << "+--------------------------------------------------+\n";
    cout << "Choose from the following options:\n";
    cout << "1. Enter a value to be added to the back of queue\n";
    cout << "2. Display first node (front) value\n";
    cout << "3. Remove first node (front) value\n";
    cout << "4. Display the queue contents\n";
    cout << "5. Exit\n";
}

/*********************************************************************
** Description:     prompts user to enter a value to add to the back
**                  of the queue
*********************************************************************/
void Menu::addValue() {
    cout << "+--------------------------------------------------+\n";
    cout << "Enter a positive integer:\n";
    cout << ">> ";
}

/*********************************************************************
** Description:     d
*********************************************************************/
void Menu::displayFirstNode() {
    cout << "+--------------------------------------------------+\n";
    cout << "First Node Value is: ";
}

/*********************************************************************
** Description:     d
*********************************************************************/
void Menu::removeFirstNode() {
    cout << "+--------------------------------------------------+\n";
    cout << "Removing the first node\n";
}

/*********************************************************************
** Description:     d
*********************************************************************/
void Menu::displayQueueContents() {
    cout << "+--------------------------------------------------+\n";
    cout << "Your queue is: ";
}

/*********************************************************************
** Description:     general validator where the parameters are the
**                  min and max numbers acceptable
*********************************************************************/
int Menu::validateNumber(int min, int max) {
    char choice[100];
    int validatedChoice = 0;
    std::stringstream convert;
    bool tooLong = false;
    bool isNotDigit = false;
    bool notInRange = false;

    // determine # of digits in max value acceptable
    long unsigned length = std::to_string(max).length();

    do {
        // store user input
        cin.getline(choice, 100);

        // reject any input that has more than digits than max parameter
        tooLong = false;
        if (strlen(choice) > length) {
            tooLong = true;
            cout << "enter only one number!\n";
        }

        // check if all characters entered are digits
        isNotDigit = false;
        for (unsigned i = 0; i < strlen(choice); i++) {
            // if digit is not a digit, then set it true so that
            // loop will repeat
            if (!isdigit(choice[i])) {
                isNotDigit = true;
            }
        }
        if (isNotDigit) {
            // prompt user to enter only digits
            cout << "enter only digits!\n";
        }

        // check if characters entered are within range
        notInRange = false;
        if (!isNotDigit && !tooLong) {
            convert.clear();
            convert << choice;
            convert >> validatedChoice;

            if (validatedChoice < min || validatedChoice > max) {
                notInRange = true;
                cout << "enter a number between "
                     << min << " or " << max << endl;
            }
        }
    } while (tooLong || isNotDigit || notInRange);

    return validatedChoice;
}

/*********************************************************************
** Description:     general integer validator where the parameters are
**                  the min and max numbers acceptable
*********************************************************************/
int Menu::validateInteger(int min, int max) {
    char choice[100];
    int validatedChoice = 0;
    bool tooLong = false;
    bool negativeFound = false;
    bool notInRange = true;
    bool characterFound = false;
    long unsigned length = 0;
    std::stringstream convert;

    do {
        cout << "Enter a number from " << min << " to " << max << endl;
        cout << ">> ";
        cin.getline(choice, 100);

        // determine # of digits in max value acceptable
        if (choice[0] == 45) { length = std::to_string(min).length(); }
        else { length = std::to_string(max).length(); }

        // reject any input that has more than digits than max parameter
        tooLong = false;
        if (strlen(choice) > length) {
            tooLong = true;
            cout << "Digits entered are too long!\n";
        }

        // check if a negative character has been found
        negativeFound = false;
        if (choice[0] == 45) { negativeFound = true; }

        // if a value entered is a negative, validate value
        notInRange = true;
        characterFound = false;
        if (negativeFound) {
            for (int index = 1; index < strlen(choice); index++) {
                if (choice[index] >= 48 && choice[index] <= 57) {
                    notInRange = false;
                }
                if (choice[index] < 48 || choice[index] > 57) {
                    characterFound = true;
                }
                if (characterFound) { notInRange = true; }
            }
            if (characterFound) { cout << "Make sure to only enter numbers!\n"; }
        }
        else { // if value entered is positive, validate value
            for (int index = 0; index < strlen(choice); index++) {
                if (choice[index] >= 48 && choice[index] <= 57) {
                    notInRange = false;
                }
                if (choice[index] < 48 || choice[index] > 57) {
                    characterFound = true;
                }
                if (characterFound) { notInRange = true; }
            }
            if (characterFound) { cout << "Make sure to only enter numbers!\n"; }
        }

    } while (tooLong || notInRange);

    convert << choice;
    convert >> validatedChoice;

    return validatedChoice;
}