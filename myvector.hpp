#pragma once
#include <cstddef>
#include <initializer_list>
#include <iterator>

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
        vector(std::initializer_list<T> l);
        const vector &operator=(const vector &vec);
        const vector &operator=(const vector &&vec);
        ~vector();

        // Capacity
        size_t size() const noexcept;
        size_t capacity() const noexcept;
        constexpr bool empty() const noexcept;
        void reserve(size_t n);
        void shrink_to_fit();

        // Access to class members
        T &front();
        const T &front() const;
        T &back();
        const T &back() const;
        T *data();
        const T *data() const;
        T &operator[](size_t i);
        const T &operator[](size_t i) const;
        T &at(size_t i);
        const T &at(size_t i) const;

        // Modifiers
        void clear();
        void insert();
        void erase();
        void push_back();
        void pop_back();
        void resize();
        void swap(my::vector<T> &other);

        // Iterator
        template <class Iter>
        class myIterator
        {
        private:
            friend class my::vector<T>;

            myIterator(Iter *p) : value(p) {}

        public:
            typedef Iter iterator_type;
            typedef std::random_access_iterator_tag iterator_category;
            typedef iterator_type value_type;
            typedef iterator_type &reference;
            typedef iterator_type *pointer;
            typedef ptrdiff_t difference_type;

            iterator_type *value;

            myIterator(const myIterator &it) : value(it.value) {}

            bool operator==(const myIterator &other) const
            {
                return value == other.value;
            }

            bool operator!=(const myIterator &other) const
            {
                return value != other.value;
            }

            bool operator<(const myIterator &other) const
            {
                return value < other.value;
            }

            bool operator>(const myIterator &other) const
            {
                return value > other.value;
            }

            bool operator<=(const myIterator &other) const
            {
                return value <= other.value;
            }

            bool operator>=(const myIterator &other) const
            {
                return value >= other.value;
            }

            typename myIterator::reference operator*()
            {
                return *value;
            }

            typename myIterator::pointer operator->()
            {
                return value;
            }

            myIterator &operator++()
            {
                ++value;
                return *this;
            }

            myIterator operator++(int)
            {
                myIterator tmp(*this);
                ++value;
                return tmp;
            }

            myIterator &operator--()
            {
                --value;
                return *this;
            }

            myIterator operator--(int)
            {
                myIterator tmp(*this);
                --value;
                return tmp;
            }

            myIterator operator+(difference_type n) const
            {
                return myIterator(value + n);
            }

            myIterator operator-(difference_type n) const
            {
                return myIterator(value - n);
            }

            difference_type operator+(const myIterator &other) const
            {
                return value + other.value;
            }

            difference_type operator-(const myIterator &other) const
            {
                return value - other.value;
            }

            myIterator &operator+=(difference_type n)
            {
                value += n;
                return *this;
            }

            myIterator &operator-=(difference_type n)
            {
                value -= n;
                return *this;
            }

            friend myIterator operator+(difference_type n, const myIterator &it)
            {
                return myIterator(n + it.value);
            }

            friend myIterator operator-(difference_type n, const myIterator &it)
            {
                return myIterator(n - it.value);
            }

            reference operator[](difference_type n)
            {
                return value[n];
            }
        };

        typedef myIterator<T> iterator;
        typedef myIterator<const T> const_iterator;
        typedef std::reverse_iterator<iterator> reverse_iterator;
        typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

        iterator begin();
        iterator end();
        const_iterator begin() const;
        const_iterator end() const;
        reverse_iterator rbegin();
        reverse_iterator rend();
        const_reverse_iterator rbegin() const;
        const_reverse_iterator rend() const;
    };

    //
    // Constructors and destructor
    //

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
          data_(new T[size_])
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
    inline vector<T>::vector(std::initializer_list<T> l)
        : capacity_(l.size()),
          size_(capacity_),
          data_(new T[capacity_])
    {
        auto it = l.begin();
        for (size_t i = 0; i < size_; i++)
        {
            data_[i] = *it++;
        }
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
        data_ = std::move(vec.data_);

        return *this;
    }

    template <class T>
    vector<T>::~vector()
    {
        delete[] data_;
    }

    //
    // Constructors and destructor end
    //

    //
    // Capacity
    //

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

    //
    // Capacity
    //

    //
    // Access to class members
    //

    template <class T>
    inline T &vector<T>::front()
    {
        return data_[0];
    }

    template <class T>
    inline const T &vector<T>::front() const
    {
        return data_[0];
    }

    template <class T>
    inline T &vector<T>::back()
    {
        return data_[size_ - 1];
    }

    template <class T>
    inline const T &vector<T>::back() const
    {
        return data_[size_ - 1];
    }

    template <class T>
    inline T *vector<T>::data()
    {
        return data_;
    }

    template <class T>
    inline const T *vector<T>::data() const
    {
        return data_;
    }

    template <class T>
    inline T &vector<T>::operator[](size_t i)
    {
        return data_[i];
    }

    template <class T>
    inline const T &vector<T>::operator[](size_t i) const
    {
        return data_[i];
    }

    template <class T>
    inline T &vector<T>::at(size_t i)
    {
        if (i < 0 || size_ <= i)
        {
            throw "out_of_range";
        }
        return data_[i];
    }

    template <class T>
    inline const T &vector<T>::at(size_t i) const
    {
        if (i < 0 || size_ <= i)
        {
            throw "out_of_range";
        }
        return data_[i];
    }

    //
    // Access to class members
    //

    //
    // Iterator
    //

    template <class T>
    inline typename vector<T>::iterator vector<T>::begin()
    {
        return data_;
    }

    template <class T>
    inline typename vector<T>::iterator vector<T>::end()
    {
        return data_ + size_;
    }

    template <class T>
    inline typename vector<T>::const_iterator vector<T>::begin() const
    {
        return data_;
    }

    template <class T>
    inline typename vector<T>::const_iterator vector<T>::end() const
    {
        return data_ + size_;
    }

    template <class T>
    inline typename vector<T>::reverse_iterator vector<T>::rbegin()
    {
        return std::reverse_iterator<my::vector<T>::iterator>(end());
    }

    template <class T>
    inline typename vector<T>::reverse_iterator vector<T>::rend()
    {
        return std::reverse_iterator<my::vector<T>::iterator>(begin());
    }

    template <class T>
    inline typename vector<T>::const_reverse_iterator vector<T>::rbegin() const
    {
        return std::reverse_iterator<my::vector<T>::iterator>(end());
    }

    template <class T>
    inline typename vector<T>::const_reverse_iterator vector<T>::rend() const
    {
        return std::reverse_iterator<my::vector<T>::iterator>(begin());
    }

    //
    // Iterator
    //

    //
    // Modifiers
    //

} // namespace my