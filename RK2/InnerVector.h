#ifndef INNER_VECTOR_H
#define INNER_VECTOR_H

#include "BaseVector.h"
#include <stdexcept>

template<typename T>
class InnerVector : public BaseVector<T> {
public:
    InnerVector();
    InnerVector(const InnerVector<T>& other);
    virtual ~InnerVector();

    // Умножение вектора на скаляр
    InnerVector<T> operator*(const T& scalar) const;

    // Поэлементное сложение двух векторов
    InnerVector<T> operator+(const InnerVector<T>& other) const;

    // Вычисление скалярного произведения двух векторов
    T dotProduct(const InnerVector<T>& other) const;

    // Векторное (кросс-) произведение для 3-мерных векторов
    InnerVector<T> crossProduct(const InnerVector<T>& other) const;
};
#endif // INNER_VECTOR_H
