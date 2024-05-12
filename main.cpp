#include <iostream>
#include <string>
#include <algorithm>

#include "myvector.hpp"

int main(int argc, char const *argv[])
{
    
    my::vector<int> vec(5, 5); 

    vec[0] = 16;
    vec[1] = -16;
    vec[2] = 126;
    vec[3] = 77;
    vec[4] = 0;


    std::sort(vec.rbegin(), vec.rend());

    for (auto &&i : vec)
    {
        std::cout << i << '\n';
    }
    


    return 0;
}
