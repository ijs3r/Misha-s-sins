#include "input_data.h"
#include <iostream>
#include <fstream>
#include "main_view.h"
#include "ImageHandler.h"
using namespace std;
template<class T>
char InputImage(T& f,Image image, int n, int m) {
    char ch;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m;) {
            if (!(f>>ch))return ERROR_NOT_ENOUGH_DATA;
            if (ch != 'W' && ch != 'B') {
                if (ch == ' ' || ch == '\n')continue;
                return ERROR_INCORRECT_IMAGE;
            }
            image[i][j++] = (ch == 'W');
        }
    }
    return NO_ERROR;
}

//char InputImage(Image image, int n, int m) {
//    char ch;
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m;) {
//            cin >> ch;
//            image[i][j];
//            if (ch != 'W' && ch != 'B') {
//                if (ch == ' ' || ch == '\n')continue;
//                return ERROR_INCORRECT_IMAGE;
//            }
//            image[i][j++] = (ch=='W');
//        }
//    }
//    return NO_ERROR;
//}

/// <summary>
/// Выделяет число (&lt;5 цифр) из форматированного ввода
/// </summary>
/// <param name="f">целевой файл</param>
/// <returns>Первое найденное по модулю число или -1 в противном</returns>
int GetNextNumber(ifstream& f) {
    char ch;
    int j = 0;
    char num[4] = {-1};
    while (f.read(&ch,1)) {
        if (ch < '0' || ch>'9') {
            if (ch == '.'||ch == '-')return -1;
            if (num[0]!=-1)return atoi(num);
            continue;
        }
        if (num[0] == -1 && ch == '0')continue;
        num[j++] = ch;
        if (j>3)return atoi(num);
    }
    return -1;
}

char InputHandler(const char* fname,Image original, Image negative, int& n, int& m)
{
    ifstream fIn(fname);
    if(!fIn)return ERROR_FAILED_TO_OPEN_FILE;
    n = GetNextNumber(fIn);
    m = GetNextNumber(fIn);
    if (1> n || 1 > m ||n > 100 || m > 100) {
        fIn.close();
        return ERROR_INCORRECT_ARRAY_SIZES;
    }
    char code = InputImage(fIn, original, n, m);
    if (code != NO_ERROR|| (code = InputImage(fIn, negative, n, m))!=NO_ERROR) {
        n = m = 0;
        fIn.close();
        return code;
    }
    PrintData(original, negative, n, m);
    fIn.close();
    return NO_ERROR;
}

char InputHandler(Image original, Image negative, int& n, int& m)
{
    cin>>n>>m;
    if (1 > n || 1 > m || n > 100 || m > 100) {
        return ERROR_INCORRECT_ARRAY_SIZES;
    }
    char code = InputImage(cin, original, n, m);
    if (code != NO_ERROR || (code = InputImage(cin, negative, n, m)) != NO_ERROR) {
        n = m = 0;
        return code;
    }
    PrintData(original, negative, n, m);
    return NO_ERROR;
}
