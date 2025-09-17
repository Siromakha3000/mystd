#pragma once
#include <stdexcept>

template <typename T>
struct Node
{
    T value;
    Node* next;
    Node() : value{ }, next{ nullptr } { }
    explicit Node(T value)
    {
        this->value = value;
        next = nullptr;
    }
};


template <typename T>
class LinkedList
{
private:
    struct Node<T>* head;
    size_t size;

public:
    LinkedList() : head{ nullptr }, size{ 0 } {};
    ~LinkedList()
    {
        clear();
    }

    T& operator[](const size_t index)
    {
        Node<T>* current = head;
        for (size_t i = 1; i <= index; i++)
            current = current->next;
        return current->value;
    }
    T& get(const size_t index)
    {
        if (index >= size)
            throw std::out_of_range("LinkedList::get");
        Node<T>* current = head;
        for (size_t i = 1; i <= index; i++)
            current = current->next;
        return current->value;
    }
    void insert(const size_t index, T newData)
    {
        if (index > size)
            throw std::out_of_range("LinkedList::insert");
        Node<T>* current = head;
        for (size_t i = 1; i < index; i++)
        {
            current = current->next;
        }
        Node<T>* newNode = new Node<T>(newData);
        Node<T>* temp = current->next;
        current->next = newNode;
        newNode->next = temp;
        size++;
    }
    void push_back(T newData)
    {
        Node<T>* newNode = new Node(newData);
        if (head == nullptr)
        {
            head = newNode;
            size++;
            return;
        }
        Node<T>* current = head;
        do
        {
            if (current->next == nullptr)
            {
                current->next = newNode;
                size++;
                return;
            }
            current = current->next;
        }
        while (true);
    }
    void pop_back()
    {
        Node<T>* current = head;
        if (current == nullptr)
            return;
        if (current->next == nullptr)
        {
            delete current;
            head = nullptr;
            size--;
            return;
        }

        do
        {
            if (current->next->next == nullptr)
            {
                delete current->next;
                current->next = nullptr;
                size--;
                return;
            }
            current = current->next;
        }
        while (true);
    }
    void push_front(T newData)
    {
        Node<T>* temp = head;
        head = new Node<T>(newData);
        head->next = temp;
        size++;
    }
    void pop_front()
    {
        if (head == nullptr)
            return;
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node<T>* temp = head->next;
            delete head;
            head = temp;
        }
        size--;
    }
    void clear()
    {
        Node<T>* current = head;
        while (current != nullptr)
        {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        size = 0;
    }
    [[nodiscard]] size_t count() const
    {
        return size;
    }
};