#ifndef VECTOR_CLASS_H
#define VECTOR_CLASS_H
#include <initializer_list>
#include "iterator.h"
#include <new>

namespace vector
{

template <class T>
void copy(T* destination, T* source, size_t count)
{
    for(unsigned i = 0; i < count; i++)
    {
        destination[i] = source[i];
    }
}

typedef char byte;

template <typename Vector_Type>
class Vector
{
private:
    Vector_Type* data_;
    std::size_t size_;

public:
    Vector():size_(0), data_(NULL){}
    explicit Vector(size_t size, const Vector_Type& value = Vector_Type());
    Vector(const Vector &other);
    Vector(std::initializer_list<Vector_Type> list);

    template <typename Other>
    Vector(const Vector<Other> &other);

    Vector& operator=(Vector &other);

    template <class Other>
    Vector& operator =(Vector<Other> const &other);

    ~Vector();

    void swap(Vector& other);
    void resize( size_t count, Vector_Type value = Vector_Type() );
    void push_back( const Vector_Type& value );
    void pop_back();

    Vector_Type& back()
    {
        return data_[size_ - 1];
    }

    const Vector_Type& back() const
    {
        return data_[size_ - 1];
    }

    Vector_Type* data()
    {
        return data_;
    }
    const Vector_Type* data() const
    {
        return data_;
    }

    Vector_Type& at(std::size_t pos )
    {
        return data_[pos];
    }

    const Vector_Type& at(std::size_t pos ) const
    {
        return data_[pos];
    }

    iterator<Vector_Type> erase( iterator<Vector_Type> first, iterator<Vector_Type> last );
    iterator<Vector_Type> erase(iterator<Vector_Type> pos);

    iterator<Vector_Type> begin()
    {
        iterator <Vector_Type>it(data_);
        return it;
    }

    iterator<Vector_Type> end()
    {
        iterator <Vector_Type>it(data_ + size_);
        return it;
    }

    bool empty()
    {
        return (size_ == 0)?true:false;
    }

    std::size_t size() const
    {
        return size_;
    }

    Vector_Type& operator[](std::size_t i)
    {
        return data_[i];
    }

    const Vector_Type& operator[](std::size_t i) const
    {
        return data_[i];
    }
};

}
#include "vector_class_impl.h"

#endif // VECTOR_CLASS_H
