#ifndef VECTOR_CLASS_H
#define VECTOR_CLASS_H
#include <new>

typedef char byte;

template <typename Vector_Type>
class Vector
{
private:
   Vector_Type* data_;
   size_t size_;
public:

   template < typename Other > friend class Vector ;

   explicit Vector(size_t size, const Vector_Type& value = Vector_Type())
   {
        size_ = size;
        data_ = (Vector_Type*)new byte[sizeof(Vector_Type)*size_];
        for(unsigned i = 0; i < size_; i++)
        {
            new(data_ + i) Vector_Type(value);
        }
    }

   template <typename Other>
   Vector(const Vector<Other> &other)
   {
       size_ = other.size_;
       data_ = (Vector_Type*)new byte[sizeof(Vector_Type)*size_];
       for(unsigned i = 0; i < size_; i++)
       {
           new(data_ + i) Vector_Type(other.data_[i]);
       }
   }

     Vector(const Vector &other)
     {
         size_ = other.size_;
         data_ = (Vector_Type*)new byte[sizeof(Vector_Type)*size_];
         for(unsigned i = 0; i < size_; i++)
         {
             new(data_ + i) Vector_Type(other.data_[i]);
         }
     }

     ~Vector()
     {
         for (unsigned i = 0; i < size_; i++)
          {
              data_[i].~Vector_Type();
          }
         delete[] ((byte*)data_);
     }

    Vector& operator=(Vector &other)
    {
        if(this != &other)
        {
            this->~Vector_Type();
            size_ = other.size_;
            data_ = (Vector_Type*)new byte[sizeof(Vector_Type)*size_];
            for(unsigned i = 0; i < size_; i++)
            {
                new(data_ + i) Vector_Type(other.data_[i]);
            }
        }
        return *this;
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


    template <class Other>
    Vector& operator =(Vector<Other> const &other)
    {
        this->~Vector_Type();
        size_ = other.size_;
        data_ = (Vector_Type*)new byte[sizeof(Vector_Type)*size_];
        for(unsigned i = 0; i < size_; i++)
        {
            new(data_ + i) Vector_Type(other.data_[i]);
        }
        return *this;
    }

};


#endif // VECTOR_CLASS_H
