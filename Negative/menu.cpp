#include "menu.h"
#include"main_view.h"
#include <iostream>
//view: console
using namespace std;
int menu()
{
    char choice;
    do {
        cout << STR_LINE;
        cout << "You can: " << endl;
        cout << "1. Input data from file" << endl;
        cout << "2. Input data from keyboard" << endl;
        cout << "3. How many mistakes " << endl;
        cout << "4. Show data" << endl;
        cout << "0. Exit" << endl;
        cout << STR_LINE;
        cout << "Your choice: ";

        cin >> choice;
        choice -= '0';
    } while ((choice < COM_EXIT) || (choice > COM_SHOW_DATA));
    return choice;
}


