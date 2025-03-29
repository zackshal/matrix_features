#include "BaseVector.h"
#include "InnerVector.h"  // Для использования InnerVector в явной инстанциации

template<typename T>
BaseVector<T>::BaseVector() : data() {
    // Конструктор по умолчанию
}

template<typename T>
BaseVector<T>::BaseVector(const BaseVector<T>& other) : data(other.data) {
    // Конструктор копирования
}

template<typename T>
BaseVector<T>::~BaseVector() {
    // Деструктор (освобождение памяти происходит автоматически)
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
        throw std::out_of_range("Неверный индекс элемента");
}

template<typename T>
T& BaseVector<T>::operator[](size_t index) {
    if (index >= data.size())
        throw std::out_of_range("Неверный индекс элемента");
    return data[index];
}

template<typename T>
const T& BaseVector<T>::operator[](size_t index) const {
    if (index >= data.size())
        throw std::out_of_range("Неверный индекс элемента");
    return data[index];
}

//  явная инстанциация шаблона для типа int
template class BaseVector<int>;

//явная инстанциация шаблона для типа InnerVector<int>, чтобы обеспечить 
//наличие реализации для BaseVector<InnerVector<int>>, используемого в OuterVector. 
template class BaseVector<InnerVector<int>>;
