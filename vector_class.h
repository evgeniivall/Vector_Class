#ifndef VECTOR_CLASS_H
#define VECTOR_CLASS_H
#include <new>

template <class T>
void copy(T* destination, T* source, size_t count)
{
    for(unsigned i = 0; i < count; i++)
    {
        destination[i] = source[i];
    }
}

typedef char byte;

//TODO:
template<class T>
class iterator
{
private:
    T* pointer;
public:
    iterator():pointer(NULL){}
    explicit iterator(T* ptr):pointer(ptr){}
    const int& operator*() const
    {
        return *pointer;
    }

    int& operator*()
    {
        return *pointer;
    }
    iterator& operator++()
    {
        pointer++;
        return *this;
    }
    iterator operator++(int)
    { return iterator(pointer++); }
    iterator& operator--()
    {
        pointer--;
        return *this;
    }
    iterator operator--(int)
     { return iterator(pointer--); }
    T* base() const { return pointer; }

    iterator& operator+=(const std::size_t& __n)
      { pointer += __n; return *this; }

      iterator operator+(const std::size_t& __n) const
      { return iterator(pointer + __n); }

      iterator& operator-=(const std::size_t& __n)
      { pointer -= __n; return *this; }

      iterator operator-(const std::size_t& __n) const
      { return iterator(pointer - __n); }


    size_t operator -(const iterator<T> & other)
    {
        return pointer - other.pointer;
    }


};
template <class T>
inline bool operator==(const iterator<T>& __lhs, const iterator<T>& __rhs)
{ return __lhs.base() == __rhs.base(); }

template <class T>
inline bool operator!=(const iterator<T>& __lhs, const iterator<T>& __rhs)
{ return __lhs.base() != __rhs.base(); }

class reverse_iterator;

template <typename Vector_Type>
class Vector
{
private:
    Vector_Type* data_;
    size_t size_;

public:
    //friend class iterator;
    //template < typename Other > friend class Vector ;
    Vector():size_(0), data_(NULL){}
    explicit Vector(size_t size, const Vector_Type& value = Vector_Type());
    Vector(const Vector &other);

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

    Vector_Type&       back()
    {
        return data_[size_ - 1];
    }

    const Vector_Type& back() const
    {
        return data_[size_ - 1];
    }

    Vector_Type*       data()
    {
        return data_;
    }
    const Vector_Type* data() const
    {
        return data_;
    }

    Vector_Type&       at( size_t pos )
    {
        return data_[pos];
    }
    const Vector_Type& at( size_t pos ) const
    {
        return data_[pos];
    }


    //TODO:


    iterator<Vector_Type> erase( iterator<Vector_Type> first, iterator<Vector_Type> last )
    {
        Vector<Vector_Type> temp(size_ - (last - first));

        iterator<Vector_Type> itr, temp_itr, ret_itr;
        for(itr = this->begin(), temp_itr = temp.begin(); itr != first; ++itr, ++temp_itr)
        {
            *temp_itr = *itr;
        }
        ret_itr = temp_itr;
        for(itr = last; temp_itr != temp.end(); ++itr, ++temp_itr)
        {
            *temp_itr = *itr;
        }
        this->swap(temp);
        return ret_itr;
    }

    iterator<Vector_Type> erase(iterator<Vector_Type> pos)
    {
        Vector<Vector_Type> temp(size_ - 1);

        iterator<Vector_Type> itr, temp_itr, ret_itr;
        for(itr = this->begin(), temp_itr = temp.begin(); itr != pos; ++itr, ++temp_itr)
        {
            *temp_itr = *itr;
        }
        ++itr;
         ret_itr = temp_itr;
        for(; temp_itr != temp.end(); ++itr, ++temp_itr)
        {
            *temp_itr = *itr;
        }
        this->swap(temp);
        return ret_itr;
    }

    iterator<Vector_Type> begin()
    {
        iterator <Vector_Type>it(data_);
        return it;
    }

    //reverse_iterator rbegin();
    iterator<Vector_Type> end()
    {
        iterator <Vector_Type>it(data_ + size_);
        return it;
    }
    //reverse_iterator rend();

    bool empty()
    {
        return (size_ == 0)?true:false;
    }

    size_t size() const
    {
        return size_;
    }

    Vector_Type& operator[](size_t i)
    {
        return data_[i];
    }

    const Vector_Type& operator[](size_t i) const
    {
        return data_[i];
    }



};
/////////////////////////////////////////////////////////////////////////////

template <typename Vector_Type>
Vector<Vector_Type>::Vector(size_t size, const Vector_Type& value)
{
     size_ = size;
     data_ = (Vector_Type*)new byte[sizeof(Vector_Type)*size_];
     for(unsigned i = 0; i < size_; i++)
     {
         new(data_ + i) Vector_Type(value);
     }
 }

template <typename Vector_Type>
Vector<Vector_Type>::Vector(const Vector &other)
{
    size_ = other.size_;
    data_ = (Vector_Type*)new byte[sizeof(Vector_Type)*size_];
    for(unsigned i = 0; i < size_; i++)
    {
        new(data_ + i) Vector_Type(other.data_[i]);
    }
}

template <typename Vector_Type>
template <typename Other>
Vector<Vector_Type>::Vector(const Vector<Other> &other)
{
    size_ = other.size_;
    data_ = (Vector_Type*)new byte[sizeof(Vector_Type)*size_];
    for(unsigned i = 0; i < size_; i++)
    {
        new(data_ + i) Vector_Type(other.data_[i]);
    }
}

template <typename Vector_Type>
Vector<Vector_Type>& Vector<Vector_Type>::operator=(Vector<Vector_Type> &other)
{
    if(this != &other)
    {
        this->~Vector();
        size_ = other.size_;
        data_ = (Vector_Type*)new byte[sizeof(Vector_Type)*size_];
        for(unsigned i = 0; i < size_; i++)
        {
            new(data_ + i) Vector_Type(other.data_[i]);
        }
    }
    return *this;
}

template <typename Vector_Type>
template <class Other>
Vector<Vector_Type>& Vector<Vector_Type>::operator =(Vector<Other> const &other)
{
    this->~Vector();
    size_ = other.size_;
    data_ = (Vector_Type*)new byte[sizeof(Vector_Type)*size_];
    for(unsigned i = 0; i < size_; i++)
    {
        new(data_ + i) Vector_Type(other.data_[i]);
    }
    return *this;
}

template <typename Vector_Type>
Vector<Vector_Type>::~Vector()
{
    for (unsigned i = 0; i < size_; i++)
    {
         data_[i].~Vector_Type();
    }
    delete[] ((byte*)data_);
}

template <typename Vector_Type>
void Vector<Vector_Type>::swap(Vector<Vector_Type>& other)
{
    Vector<Vector_Type> temp(other);
    other = *this;
    *this = temp;
}

template <typename Vector_Type>
void Vector<Vector_Type>::resize( size_t count, Vector_Type value )
{
    Vector_Type* temp_data_ = (Vector_Type*)new byte[sizeof(Vector_Type)*count];

    if(count > size_)
    {
        copy(temp_data_, data_, size_);
        for(unsigned i = size_; i < count; i++)
        {
            new(temp_data_ + i) Vector_Type(value);
        }
    }
    else
    {
        copy(temp_data_, data_, count);
    }
    this->~Vector();
    data_ = temp_data_;
    size_ = count;
}

template <typename Vector_Type>
void Vector<Vector_Type>::push_back( const Vector_Type& value )
{
    this->resize(size_ + 1, value);
}

template <typename Vector_Type>
void Vector<Vector_Type>::pop_back()
{
    if(!(this->empty()))
    {
        this->resize(size_ - 1);
    }
}

#endif // VECTOR_CLASS_H
