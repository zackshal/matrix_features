#include "OuterVector.h"
#include "InnerVector.h"
#include <algorithm>
using namespace std;
// ����������� �� ���������
template<typename T>
OuterVector<T>::OuterVector() : BaseVector<InnerVector<T>>() {}

// ����������� �����������
template<typename T>
OuterVector<T>::OuterVector(const OuterVector<T>& other) : BaseVector<InnerVector<T>>(other) {}

// ����������
template<typename T>
OuterVector<T>::~OuterVector() {}

// ������ � �������
template<typename T>
InnerVector<T>& OuterVector<T>::getRow(size_t index) {
    if (index >= this->data.size())
        throw out_of_range("�������� ������ ������");
    return this->data[index];
}

template<typename T>
const InnerVector<T>& OuterVector<T>::getRow(size_t index) const {
    if (index >= this->data.size())
        throw out_of_range("�������� ������ ������");
    return this->data[index];
}

// ����� ��������� ������������� ���������� ��������� ����� ���� ���������� ��������
template<typename T>
size_t OuterVector<T>::getMaxRowSize() const {
    size_t maxSize = 0;
    for (const auto& row : this->data) {
        if (row.size() > maxSize)
            maxSize = row.size();
    }
    return maxSize;
}

// ����� ������������� ������ ��� data
template<typename T>
void OuterVector<T>::allocateNewMemory(size_t newSize) {
    this->data.reserve(newSize);
}

// ���������� ��������� ��������� �� ������: �������� ������ ���������� ������ �� scalar
template<typename T>
OuterVector<T> OuterVector<T>::operator*(const T& scalar) const {
    OuterVector<T> result(*this);
    for (size_t i = 0; i < result.data.size(); ++i) {
        result.data[i] = result.data[i] * scalar;
    }
    return result;
}

// ��������� ������������ ���� OuterVector: ����� �������� ������������ ��������������� ���������
template<typename T>
T OuterVector<T>::dotProduct(const OuterVector<T>& other) const {
    if (this->data.size() != other.data.size())
        throw invalid_argument("������� OuterVector �� ���������");

    T sum = T();
    for (size_t i = 0; i < this->data.size(); ++i) {
        if (this->data[i].size() != other.data[i].size())
            throw invalid_argument("������� ���������� �������� �� ���������");
        for (size_t j = 0; j < this->data[i].size(); ++j) {
            sum += this->data[i][j] * other.data[i][j];
        }
    }
    return sum;
}

// ������������ �������� ���� OuterVector
template<typename T>
OuterVector<T> OuterVector<T>::operator+(const OuterVector<T>& other) const {
    if (this->data.size() != other.data.size())
        throw invalid_argument("������� OuterVector �� ���������");

    OuterVector<T> result(*this);
    for (size_t i = 0; i < this->data.size(); ++i) {
        if (this->data[i].size() != other.data[i].size())
            throw invalid_argument("������� ���������� �������� �� ���������");
        for (size_t j = 0; j < this->data[i].size(); ++j) {
            result.data[i][j] += other.data[i][j];
        }
    }
    return result;
}

// ��������� (�����-) ������������ ��� ������ ���� ���������� �������� (���������� ������ ��� 3-������)
template<typename T>
OuterVector<T> OuterVector<T>::operator^(const OuterVector<T>& other) const {
    if (this->data.size() != other.data.size())
        throw invalid_argument("������� OuterVector �� ���������");

    OuterVector<T> result;
    for (size_t i = 0; i < this->data.size(); ++i) {
        if (this->data[i].size() != 3 || other.data[i].size() != 3)
            throw invalid_argument("��������� ������������ ���������� ������ ��� 3-������ ���������� ��������");
        InnerVector<T> cross;
        // ��������� �����-������������:
        cross.addElement(this->data[i][1] * other.data[i][2] - this->data[i][2] * other.data[i][1]);
        cross.addElement(this->data[i][2] * other.data[i][0] - this->data[i][0] * other.data[i][2]);
        cross.addElement(this->data[i][0] * other.data[i][1] - this->data[i][1] * other.data[i][0]);
        result.addElement(cross);
    }
    return result;
}

// ����� ������������ ��� ���� int
template class OuterVector<int>;
