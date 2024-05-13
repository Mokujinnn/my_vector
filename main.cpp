#include <iostream>
#include <string>
#include <algorithm>

#include "myvector.hpp"

void foo(const my::vector<int> v)
{
    for (const auto &i : v)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}

int main(int argc, char const *argv[])
{
    
    my::vector<int> vec(5, 5);
    my::vector<int> v1 = {5, 123, -11, 33};

    my::vector<int>&& v2 = my::vector<int>(5, 5);
    my::vector<int> v3(v2);


    vec[0] = 16;
    vec[1] = -16;
    vec[2] = 126;
    vec[3] = 77;
    vec[4] = 0;

    v1 = vec;

    std::sort(vec.rbegin(), vec.rend());

    foo(vec);


    for (auto &&i : vec)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}
