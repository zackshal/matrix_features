#include "InnerVector.h"

template<typename T>
InnerVector<T>::InnerVector() : BaseVector<T>() {}

template<typename T>
InnerVector<T>::InnerVector(const InnerVector<T>& other) : BaseVector<T>(other) {}

template<typename T>
InnerVector<T>::~InnerVector() {}

template<typename T>
InnerVector<T> InnerVector<T>::operator*(const T& scalar) const {
    InnerVector<T> result(*this);
    for (size_t i = 0; i < result.size(); ++i) {
        result[i] = result[i] * scalar;
    }
    return result;
}

template<typename T>
InnerVector<T> InnerVector<T>::operator+(const InnerVector<T>& other) const {
    if (this->size() != other.size()) {
        throw std::invalid_argument("������� ������ ���� ����������� ������� ��� ��������.");
    }
    InnerVector<T> result(*this);
    for (size_t i = 0; i < result.size(); ++i) {
        result[i] += other[i];
    }
    return result;
}

template<typename T>
T InnerVector<T>::dotProduct(const InnerVector<T>& other) const {
    if (this->size() != other.size()) {
        throw std::invalid_argument("������� ������ ���� ����������� ������� ��� ���������� ������������.");
    }
    T sum = T();
    for (size_t i = 0; i < this->size(); ++i) {
        sum += (*this)[i] * other[i];
    }
    return sum;
}

// ���������� ���������� (�����-) ������������ ��� 3-������ ��������
template<typename T>
InnerVector<T> InnerVector<T>::crossProduct(const InnerVector<T>& other) const {
    if (this->size() != 3 || other.size() != 3) {
        throw std::invalid_argument("������������ ������������ ���������� ������ ��� 3-������ ��������.");
    }
    InnerVector<T> result;
    result.addElement((*this)[1] * other[2] - (*this)[2] * other[1]);
    result.addElement((*this)[2] * other[0] - (*this)[0] * other[2]);
    result.addElement((*this)[0] * other[1] - (*this)[1] * other[0]);
    return result;
}

// ����� ������������ ��� ���� int
template class InnerVector<int>;
