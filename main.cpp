#include <iostream>
#include "vector_class.h"



int main()
{
    Vector<int> v(10, 2);
    int d = 0;
    for(auto i = v.begin(); i != v.end(); ++i)
    {
        *i = d++;
    }

    for(auto i = v.begin(); i != v.end(); ++i)
    {
     std::cout << *i;
    }

    v.erase(v.begin());
    std::cout << std::endl;
    for(auto i = v.begin(); i != v.end(); ++i)
    {
     std::cout << *i;
    }

     std::cout << *(v.erase((v.begin() + 2), (v.begin() + 5)));
    std::cout << std::endl;
    for(auto i = v.begin(); i != v.end(); ++i)
    {
     std::cout << *i;
    }


    return 0;
}
