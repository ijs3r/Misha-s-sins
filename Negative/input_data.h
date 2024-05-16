#include "ImageHandler.h"
#ifndef INPUT_DATA_H
#define INPUT_DATA_H
//модуль ввода данных
/// <summary>
/// Функция для ввода данных c клавиатуры через командную строку с преобразованием
/// </summary>
/// <param name="original">Адрес для размещения исходного изображения</param>
/// <param name="negative">Адрес для размещения негатива</param>
/// <param name="n">кол-во строк</param>
/// <param name="m">кол-во столбцов</param>
/// <returns>Код ошибки или NO_ERROR</returns>
char InputHandler(Image original, Image negative, int& n, int& m);
/// <summary>
/// Функция для ввода данных из файла с преобразованием
/// </summary>
/// <param name="fname">Название файла</param>
/// <param name="original">Адрес для размещения исходного изображения</param>
/// <param name="negative">Адрес для размещения негатива</param>
/// <param name="n">кол-во строк</param>
/// <param name="m">кол-во столбцов</param>
/// <returns>Код ошибки или NO_ERROR</returns>
char InputHandler(const char* fname, Image original, Image negative, int& n, int& m);
#endif  INPUT_DATA_H

