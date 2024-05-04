#include <iostream>

#include "myvector.hpp"

int main(int argc, char const *argv[])
{
    
    my::vector<int> vec(my::vector<int>(5, 5));
    
    for (size_t i = 0; i < 5; i++)
    {
        std::cout << vec[i] << ' ';
    }
    

    return 0;
}
