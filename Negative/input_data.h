#include "ImageHandler.h"
#ifndef INPUT_DATA_H
#define INPUT_DATA_H
//������ ����� ������
/// <summary>
/// ������� ��� ����� ������ c ���������� ����� ��������� ������ � ���������������
/// </summary>
/// <param name="original">����� ��� ���������� ��������� �����������</param>
/// <param name="negative">����� ��� ���������� ��������</param>
/// <param name="n">���-�� �����</param>
/// <param name="m">���-�� ��������</param>
/// <returns>��� ������ ��� NO_ERROR</returns>
char InputHandler(Image original, Image negative, int& n, int& m);
/// <summary>
/// ������� ��� ����� ������ �� ����� � ���������������
/// </summary>
/// <param name="fname">�������� �����</param>
/// <param name="original">����� ��� ���������� ��������� �����������</param>
/// <param name="negative">����� ��� ���������� ��������</param>
/// <param name="n">���-�� �����</param>
/// <param name="m">���-�� ��������</param>
/// <returns>��� ������ ��� NO_ERROR</returns>
char InputHandler(const char* fname, Image original, Image negative, int& n, int& m);
#endif  INPUT_DATA_H

