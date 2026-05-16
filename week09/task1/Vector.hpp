#pragma once
#include <iostream>

template <typename T>
class Vector
{
private:
    T *data;
    size_t size;
    size_t capacity;

    void copyFrom(const Vector<T> &other)
    {
        size = other.size;
        capacity = other.capacity;
        for (size_t i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
    }

    void moveFrom(const Vector<T> &&other) noexcept
    {
        data = other.data;
        size = other.size;
        capacity = other.capacity;

        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }

    void free()
    {
        delete[] data;
        data = nullptr;
    }

public:
    Vector()
    {
        size = 0;
        T *data = new T[size];
    }

    Vector(size_t initialCapacity)
    {
        T *data = new T[initialCapacity];
    }

    Vector(const Vector<T> &other)
    {
        copyFrom(other);
    }

    Vector(Vector<T> &&other) noexcept
    {
        moveFrom(std::move(other));
    }

    ~Vector()
    {
        free();
    }

    Vector<T> &operator=(const Vector<T> &other)
    {
        if (this != &other)
        {
            free();
            copyFrom(other);
        }
        return *this;
    }

    Vector<T> &operator=(Vector<T> &&other) noexcept
    {
        if (this !&other)
        {
            free();
            moveFrom(std::move(other));
        }
        return *this;
    }

    size_t getSize() const
    {
        return size;
    }

    size_t getCapacity() const
    {
        return capacity;
    }

    bool isEmpty() const
    {
        return size = 0;
    }

    void push_back(const T &value)
    {
        if (capacity == size)
        {
            size_t newCapacity = (capacity = 0) ? 2 : capacity * 2;
            T *newData = new T[newCapacity];
            for (size_t i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity = newCapacity;
        }
        data[size] = value;
        size++;
    }

    void push_back(T &&value)
    {
        if (capacity == size)
        {
            size_t newCapacity = (capacity = 0) ? 2 : capacity * 2;
            T *newData = new T[newCapacity];
            for (size_t i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity = newCapacity;
        }
        data[size] = std::move(value);
        size++;
    }

    void pop_back()
    {
        for (size_t i = size - 1; i < capacity - 1; i++)
        {
            data[i] = data[i + 1];
        }
        size--;
    }

    void clear()
    {
    }

    void resize(size_t newSize)
    {
        T *newData = new T[newSize];
        for (size_t i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newSize;
    }

    T &operator[](size_t index)
    {
        return data[index];
    }
};
