#include <iostream>
#include "menu.h"
#include "input_data.h"
#include "ImageHandler.h"
#include "main_view.h"

using namespace std;
Image original, negative;
//controller
int main()
{
    int res;
    int mistakes = 0,n=0,m=0;
    do {
        res = menu();
        switch (res) {
        case COM_INPUT_FILE:
            ErrorHandler(InputHandler(Ask("Name of file: "), original, negative, n, m));
            break;
        case COM_INPUT_KEYBOARD:
            ErrorHandler(InputHandler(original, negative, n, m));
            break;
        case COM_FIND_MISTAKES:
            if (n == 0) ErrorHandler(ERROR_PROCESSING_OF_EMPTY_DATA);
            else {            
                PrintData(FindMistakes(original, negative, n, m));
            }
            break;
         case COM_SHOW_DATA:
             if (n == 0) ErrorHandler(ERROR_PROCESSING_OF_EMPTY_DATA);
             else {
                 PrintData(original, negative, n, m);
             }
             break;
        }
    } while (res != 0);
    EndOfProgram();
    return 0;
}
