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

    // ��������� ������� �� ������
    InnerVector<T> operator*(const T& scalar) const;

    // ������������ �������� ���� ��������
    InnerVector<T> operator+(const InnerVector<T>& other) const;

    // ���������� ���������� ������������ ���� ��������
    T dotProduct(const InnerVector<T>& other) const;

    // ��������� (�����-) ������������ ��� 3-������ ��������
    InnerVector<T> crossProduct(const InnerVector<T>& other) const;
};
#endif // INNER_VECTOR_H
