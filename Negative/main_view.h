#ifndef MAIN_VIEW_CPP
#define MAIN_VIEW_CPP
#include <iostream>
#include "ImageHandler.h"

#define NO_ERROR 0
#define ERROR_DATA_NOT_INPUTED 1
#define ERROR_INCORRECT_ARRAY_SIZES 2
#define ERROR_FAILED_TO_OPEN_FILE 3
#define ERROR_NOT_ENOUGH_DATA 4
#define ERROR_PROCESSING_OF_EMPTY_DATA 5
#define ERROR_INCORRECT_IMAGE 6

#define STR_LINE "-----------------------------------\n"
using namespace std;
/// <summary>
/// Опрашивает и возвращает пользовательский ввод
/// </summary>
/// <param name="message">Сообщение пользователю</param>
/// <returns>Пользовательский ввод(&lt;= 200 символов)</returns>
inline char * Ask(const char* message,int max_size = 200){
    cout<<message;
    static char buffer[200];
    cin.getline(buffer, max_size);
    cin.getline(buffer, max_size);
    return buffer;
}
/// <summary>
/// Вывод благодарности
/// </summary>
inline void EndOfProgram(){
    cout<< STR_LINE <<"Thanks for using our program!\n"<< STR_LINE;
}
/// <summary>
/// Форматированный вывод кол-во ошибок в негативе
/// </summary>
/// <param name="mistakes">кол-во ошибок</param>
inline void PrintData(int mistakes){
    std::cout << STR_LINE << "Mistakes:" << mistakes <<'\n'<< STR_LINE;
}
/// <summary>
/// Вывод массивов с обратным преобразованием
/// </summary>
/// <param name="image1">2-мерный массив nxm</param>
/// <param name="image2">2-мерный массив nxm</param>
/// <param name="n">кол-во строк</param>
/// <param name="m">кол-во столбцов</param>
inline void PrintData(const Image image1, const Image image2, int n, int m) {
    std::cout << STR_LINE <<"n = " << n << ", m = " << m << "\n\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)std::cout << (image1[i][j]?'W' : 'B');
        std::cout << '\n';
    }
    std::cout<< "\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)std::cout << (image2[i][j] ? 'W' : 'B');
        std::cout << '\n';
    }
    std::cout << STR_LINE;
}
/// <summary>
/// Логирование сообщений об ошибке | игнорирование NO_ERROR
/// </summary>
/// <param name="error">код ошибки</param>
inline void ErrorHandler(char error) {
    const char* descriptions[] = { "Success", "Failed to get data", "Incorrect image sizes(n,m is int[1,100])", "Failed to open file","Not enough data",
    "Processing of empty data","Incorrect image(s)"};
    if (error == NO_ERROR)return;
    std::cout << STR_LINE << '(' << (int)error << ")Error:" << descriptions[error] << '\n' << STR_LINE;
}

#endif  MAIN_VIEW_CPP
