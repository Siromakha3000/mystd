#pragma once
#include <stdexcept>
#include <ostream>
#include <omp.h>

template<typename T>
class Array
{
    size_t length {};
    T* data {nullptr};

public:
    explicit Array(const size_t len) : length(len), data(new T[len]()) {}
    ~Array() { delete[] data; }

    [[nodiscard]] size_t size() const { return length; }

    T& operator[](size_t index) { return data[index]; }

    T& get(const size_t index)
    {
        if (index >= length)
            throw std::out_of_range("Array::get");
        return data[index];
    }

    void put(const size_t index, const T& value)
    {
        if (index >= length)
            throw std::out_of_range("Array::put");
        data[index] = value;
    }

    void push_back(const T& value)
    {
        T* newData = new T[length + 1];
        memcpy(newData, data, length * sizeof(T));
        data[length] = value;
        delete[] data;
        data = newData;
    }

    void resize(const size_t newLength)
    {
        T* newData = new T[newLength];
        if (this->length > newLength)
            memmove(newData, this->data, newLength * sizeof(T));
        else
            memmove(newData, this->data, this->length * sizeof(T));
        delete[] this->data;
        this->data = newData;
        this->length = newLength;
    }

    void join (const Array<T>& other)
    {
        T* newData = new T[length + other.length];
        memcpy(newData, data, length * sizeof(T));
        memcpy(newData + length, other.data, other.length * sizeof(T));
        delete[] data;
        data = newData;
        length += other.length;
    }

    void filter (bool(*func)(const T& element, const size_t index))
    {
        T* filteredData = new T[length];
        size_t newLength = 0;
#pragma omp parallel for reduction(+:newLength)
        for (size_t i = 0; i < length; i++)
        {
            if (func(data[i], i))
                filteredData[newLength++] = data[i];
        }
        T* newData = new T[newLength];
        memcpy(newData, data, newLength * sizeof(T));
        delete[] data;
        data = filteredData;
        length = newLength;
    }

    void map(T(*func)(const T& element, const size_t index))
    {
        T* newData = new T[length];
#pragma omp parallel for
        for (size_t i = 0; i < length; i++)
        {
            newData[i] = func(data[i], i);
        }
        delete[] data;
        data = newData;
    }

    void forEachAsync(void(*func)(const T& element, const size_t index))
    {
#pragma omp parallel for
        for (size_t i = 0; i < length; i++)
        {
            func(data[i], i);
        }
    }

    void forEachSync(void(*func)(const T& element, const size_t index))
    {
        for (size_t i = 0; i < length; i++)
        {
            func(data[i], i);
        }
    }

    void sort()
    {
    }

};

template <typename T>
std::ostream& operator<<(std::ostream& os, Array<T>& obj)
{
    os << "[";
    for (size_t i = 0; i < obj.count(); i++)
    {
        os << obj[i] << (i != obj.count() - 1 ? ", " : "");
    }
    os << "]";
    return os;
};
