#ifndef IMAGE_HANDLER_CPP
#define IMAGE_HANDLER_CPP
#include <math.h>
typedef bool Image[100][100];
/// <summary>
/// Сравнивает негатив исходного изображения с переданным негативом, находя кол-во различий
/// </summary>
/// <param name="original">Исходное изображение</param>
/// <param name="negative">Негатив</param>
/// <param name="n">кол-во строк</param>
/// <param name="m">кол-во столбцов</param>
/// <returns>кол-во ошибок в негативе</returns>
int FindMistakes(const Image original, const Image negative, int n, int m);
#endif  IMAGE_HANDLER_CPP
