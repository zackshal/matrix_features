#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include "OuterVector.h"

// Функция для удаления ведущих и завершающих пробелов из строки
std::string trim(const std::string& str);

// Функция для форматированного вывода матрицы (без координат)
void printMatrix(const OuterVector<int>& matrix);

// Функция для вывода каждого элемента матрицы с указанием его координат
void printMatrixWithIndices(const OuterVector<int>& matrix);

#endif // UTILS_H
