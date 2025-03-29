#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include "OuterVector.h"

// ������� ��� �������� ������� � ����������� �������� �� ������
std::string trim(const std::string& str);

// ������� ��� ���������������� ������ ������� (��� ���������)
void printMatrix(const OuterVector<int>& matrix);

// ������� ��� ������ ������� �������� ������� � ��������� ��� ���������
void printMatrixWithIndices(const OuterVector<int>& matrix);

#endif // UTILS_H
