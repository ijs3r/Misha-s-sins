#ifndef IMAGE_HANDLER_CPP
#define IMAGE_HANDLER_CPP
#include <math.h>
typedef bool Image[100][100];
/// <summary>
/// ���������� ������� ��������� ����������� � ���������� ���������, ������ ���-�� ��������
/// </summary>
/// <param name="original">�������� �����������</param>
/// <param name="negative">�������</param>
/// <param name="n">���-�� �����</param>
/// <param name="m">���-�� ��������</param>
/// <returns>���-�� ������ � ��������</returns>
int FindMistakes(const Image original, const Image negative, int n, int m);
#endif  IMAGE_HANDLER_CPP
