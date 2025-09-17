#pragma once

class Collection
{
public:
    Collection();
    ~Collection();

    virtual void get(size_t index);
    virtual void put(size_t index, int value);
    virtual void pushBack();
    virtual void remove(size_t index);
    virtual void pop();
    virtual void clear();
    virtual size_t count();
    void join (const Array<T>& other);
    void filter (bool(*func)(const T& element, const size_t index));
    void map(T(*func)(const T& element, const size_t index));
    void forEachAsync(void(*func)(const T& element, const size_t index));
    void forEach(void(*func)(const T& element, const size_t index));
};
