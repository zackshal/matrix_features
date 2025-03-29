#ifndef BASE_VECTOR_H
#define BASE_VECTOR_H

#include <vector>
#include <stdexcept>

// ���������� ���������� ������, ������������ ������� ���������� ������������� �������
template<typename T>
class BaseVector {
protected:
    std::vector<T> data;  // ��������� ���������

public:
    //������������ � ����������
    BaseVector();
    BaseVector(const BaseVector<T>& other);
    virtual ~BaseVector();

    // ���������� �������
    bool isEmpty() const;
    size_t size() const;
    virtual void addElement(const T& element);
    virtual void removeElement(size_t index);
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
};

#endif // BASE_VECTOR_H
