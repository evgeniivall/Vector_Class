#include <iostream>
#include "vector_class.h"



int main()
{
    Vector<int> v(10);
    for(int i = 0; i < 10; i++)
    {
        v[i] = i;
    }
    for(int i = 0; i < 10; i++)
    {
        std::cout << v[i];
    }

    return 0;
}
