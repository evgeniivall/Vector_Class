#include <iostream>
#include "vector_class.h"



int main()
{
    Vector<int> v(10, 2);


    v.resize(20, 4);
    v.resize(11);
    v.push_back(0);
    v.push_back(0);

    while(v.size() > 0)
    {
        v.pop_back();
        std::cout  << "Size: " << v.size() << std::endl;
    }
    std::cout << v.empty();
    std::cout << "size: " << v.size();

    return 0;
}
