#ifndef OUTER_VECTOR_H
#define OUTER_VECTOR_H

#include "InnerVector.h"
#include <stdexcept>

template<typename T>
class OuterVector : public BaseVector<InnerVector<T>> {
public:
    OuterVector();
    OuterVector(const OuterVector<T>& other);
    virtual ~OuterVector();

    // ������ � ������� (���������� ��������)
    InnerVector<T>& getRow(size_t index);
    const InnerVector<T>& getRow(size_t index) const;

    
    // ���������� ������������ ���������� ��������� ����� ���� ���������� ��������
    size_t getMaxRowSize() const;
    // ������������� ������ ��� �������� �����
    void allocateNewMemory(size_t newSize);

    
    OuterVector<T> operator*(const T& scalar) const;
    T dotProduct(const OuterVector<T>& other) const;
    OuterVector<T> operator+(const OuterVector<T>& other) const;
    OuterVector<T> operator^(const OuterVector<T>& other) const;
};

#endif // OUTER_VECTOR_H
