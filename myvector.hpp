#pragma once
#include <stddef.h>

namespace my
{

    template <class T>
    class vector
    {
    private:
        size_t capacity_;
        size_t size_;
        T *data_;

    public:
        // Constructors and destructor
        vector();
        vector(size_t _size);
        vector(size_t _size, const T &value);
        vector(const vector &vec);
        vector(const vector &&vec);
        const vector &operator=(const vector &vec);
        const vector &operator=(const vector &&vec);
        ~vector();

        // class iterator;
        // iterator begin();
        // const iterator cbegin();
        // iterator end();

        // Capacity
        size_t size() const noexcept;
        size_t capacity() const noexcept;
        constexpr bool empty() const noexcept;
        void reserve(size_t n);
        void shrink_to_fit();

        // 
    };

    template <class T>
    inline vector<T>::vector()
        : capacity_(0),
          size_(0),
          data_(nullptr)
    {
    }

    template <class T>
    inline vector<T>::vector(size_t _size)
        : capacity_(_size),
          size_(_size),
          data_(new T[_size])
    {
        for (size_t i = 0; i < _size; ++i)
        {
            data_[i] = T();
        }
    }

    template <class T>
    inline vector<T>::vector(size_t _size, const T &value)
        : capacity_(_size),
          size_(_size),
          data_(new T[_size])
    {
        for (size_t i = 0; i < _size; ++i)
        {
            data_[i] = value;
        }
    }

    template <class T>
    inline vector<T>::vector(const vector<T> &vec)
        : capacity_(vec.capacity_),
          size_(vec.size_),
          data_(new T[vec.capacity_])
    {
        for (size_t i = 0; i < vec.size_; ++i)
        {
            data_[i] = vec.data_[i];
        }
    }

    template <class T>
    inline vector<T>::vector(const vector<T> &&vec)
        : capacity_(vec.capacity_),
          size_(vec.size_),
          data_(vec.data_)
    {
    }

    template <class T>
    inline const vector<T> &vector<T>::operator=(const vector<T> &vec)
    {
        if (this == &vec)
        {
            return *this;
        }

        delete[] data_;
        data_ = new T[vec.capacity_];
        capacity_ = vec.capacity_;
        size_ = vec.size_;

        for (size_t i = 0; i < vec.capacity_; ++i)
        {
            data_[i] = vec.data_[i];
        }

        return *this;
    }

    template <class T>
    inline const vector<T> &vector<T>::operator=(const vector<T> &&vec)
    {
        capacity_ = vec.capacity_;
        size_ = vec.size_;
        std::swap(data_, vec.data_);

        return *this;
    }

    template <class T>
    vector<T>::~vector()
    {
        delete[] data_;
    }

    template <class T>
    inline size_t vector<T>::size() const noexcept
    {
        return size_;
    }

    template <class T>
    inline size_t vector<T>::capacity() const noexcept
    {
        return capacity_;
    }

    template <class T>
    inline constexpr bool vector<T>::empty() const noexcept
    {
        return size_ == 0;
    }

    template <class T>
    inline void vector<T>::reserve(size_t n)
    {
        if (n > capacity_)
        {
            T *a = new T[n];
            for (size_t i = 0; i < size_; i++)
            {
                a[i] = data_[i];
            }
            delete[] data_;
            data_ = a;
            capacity_ = n;
        }
    }

    template <class T>
    inline void vector<T>::shrink_to_fit()
    {
        T *a = new T[size_];
        for (size_t i = 0; i < size_; i++)
        {
            a[i] = data_[i];
        }
        delete[] data_;
        data_ = a;
        capacity_ = size_;
    }

} // namespace my