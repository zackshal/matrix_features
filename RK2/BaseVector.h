#ifndef BASE_VECTOR_H
#define BASE_VECTOR_H

#include <vector>
#include <stdexcept>

// объ€вление шаблонного класса, реализующего базовый функционал динамического массива
template<typename T>
class BaseVector {
protected:
    std::vector<T> data;  // ’ранилище элементов

public:
    //конструкторы и деструктор
    BaseVector();
    BaseVector(const BaseVector<T>& other);
    virtual ~BaseVector();

    // объ€вление методов
    bool isEmpty() const;
    size_t size() const;
    virtual void addElement(const T& element);
    virtual void removeElement(size_t index);
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
};

#endif // BASE_VECTOR_H
