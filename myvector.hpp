#pragma once
#include <stddef.h>

namespace my
{

    template <class T>
    class vector
    {
    private:
        size_t capacity;
        size_t size;
        T *data;

    public:
        vector();
        vector(size_t _size);
        vector(size_t _size, const T &value);
        vector(const vector &vec);
        ~vector();
    };

    template <class T>
    inline vector<T>::vector()
        : capacity(0),
          size(0),
          data(nullptr)
    {
    }

    template <class T>
    inline vector<T>::vector(size_t _size)
        : capacity(_size),
          size(_size),
          data(new T[_size])
    {
        for (size_t i = 0; i < _size; ++i)
        {
            data[i] = T();
        }
    }

    template <class T>
    inline vector<T>::vector(size_t _size, const T &value)
        : capacity(_size),
          size(_size),
          data(new T[_size])
    {
        for (size_t i = 0; i < _size; ++i)
        {
            data[i] = value;
        }
    }

    template <class T>
    inline vector<T>::vector(const vector<T> &vec)
        : capacity(vec.capacity),
          size(vec.size),
          data(new T[vec.capacity])
    {
        for (size_t i = 0; i < vec.size; ++i)
        {
            data[i] = vec.data[i];
        }
    }

    template <class T>
    vector<T>::~vector()
    {
        delete[] data;
    }

} // namespace my