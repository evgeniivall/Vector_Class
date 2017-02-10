#include <iostream>
#include "vector_class.h"

using namespace vector;
int main()
{
    //Create a vector containig 4 integers
    Vector <int> v = {1, 2, 3, 4};

    //Add two more integers to the vector
    v.push_back(25);
    v.push_back(16);

    //Iterate and print values of the vector
    for(int n:v)
    {
        std::cout << n << ' ';
    }
    return 0;
}
