#ifndef VECTOR_CLASS_IMPL_H
#define VECTOR_CLASS_IMPL_H


namespace vector
{

template <typename Vector_Type>
Vector<Vector_Type>::Vector(std::size_t size, const Vector_Type& value)
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

template <class Vector_Type>
Vector<Vector_Type>::Vector(std::initializer_list<Vector_Type> list)
{
    size_ = list.size();
    data_ = new Vector_Type[size_];
    int i = 0;
    for(auto l = list.begin(); l != list.end(); l++, i++)
    {
        data_[i] = *l;
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
void Vector<Vector_Type>::resize( std::size_t count, Vector_Type value )
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

template <class Vector_Type>
iterator<Vector_Type> Vector<Vector_Type>::erase( iterator<Vector_Type> first, iterator<Vector_Type> last )
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

template <class Vector_Type>
iterator<Vector_Type> Vector<Vector_Type>::erase(iterator<Vector_Type> pos)
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


}
#endif // VECTOR_CLASS_IMPL_H
