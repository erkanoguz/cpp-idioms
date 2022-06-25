#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <cstddef>
#include<memory>


template <typename T>
class ArrayList 
{
public:
    ArrayList(std::size_t size = 0)
        : _size(size)
        , _array(std::make_shared<T[]>(_size))
    {
    }

    ArrayList(const ArrayList& rhs) 
    {
        std::copy(rhs._marray, rhs._array + _size, _array);
    }

    ArrayList& operator= (const ArrayList rhs) 
    {
        swap(*this, rhs);
        return *this;
    }

    ~ArrayList() 
    {
    }

private:
    friend void swap(ArrayList& first, ArrayList& second) noexcept 
    {
        using std::swap;

        swap(first._size, second._size);
        swap(first._array, second._array);
    }

    std::size_t _size;
    std::shared_ptr<T[]> _array;
};


#endif