#include "BaseVector.h"
#include "InnerVector.h"  // ��� ������������� InnerVector � ����� ������������

template<typename T>
BaseVector<T>::BaseVector() : data() {
    // ����������� �� ���������
}

template<typename T>
BaseVector<T>::BaseVector(const BaseVector<T>& other) : data(other.data) {
    // ����������� �����������
}

template<typename T>
BaseVector<T>::~BaseVector() {
    // ���������� (������������ ������ ���������� �������������)
}

template<typename T>
bool BaseVector<T>::isEmpty() const {
    return data.empty();
}

template<typename T>
size_t BaseVector<T>::size() const {
    return data.size();
}

template<typename T>
void BaseVector<T>::addElement(const T& element) {
    data.push_back(element);
}

template<typename T>
void BaseVector<T>::removeElement(size_t index) {
    if (index < data.size())
        data.erase(data.begin() + index);
    else
        throw std::out_of_range("�������� ������ ��������");
}

template<typename T>
T& BaseVector<T>::operator[](size_t index) {
    if (index >= data.size())
        throw std::out_of_range("�������� ������ ��������");
    return data[index];
}

template<typename T>
const T& BaseVector<T>::operator[](size_t index) const {
    if (index >= data.size())
        throw std::out_of_range("�������� ������ ��������");
    return data[index];
}

//  ����� ������������ ������� ��� ���� int
template class BaseVector<int>;

//����� ������������ ������� ��� ���� InnerVector<int>, ����� ���������� 
//������� ���������� ��� BaseVector<InnerVector<int>>, ������������� � OuterVector. 
template class BaseVector<InnerVector<int>>;
