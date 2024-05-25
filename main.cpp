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

    // my::vector<int> vec(5, 5);
    // my::vector<int> v1 = {5, 123, -11, 33};

    my::vector<int> v2(std::move(my::vector<int>(10, 10)));

    // vec[0] = 16;
    // vec[1] = -16;
    // vec[2] = 126;
    // vec[3] = 77;
    // vec[4] = 0;

    // v1 = vec;

    // std::sort(vec.rbegin(), vec.rend());

    // foo(vec);

    for (auto &&i : v2)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    v2.push_back(-1);

    foo(v2);

    // v2.clear();

    v2.pop_back();

    int a = 2;

    v2.insert(v2.begin() + 1, a);

    v2.erase(v2.end() - 1);

    foo(v2);

    v2.resize(13, -1);

    foo(v2);

    my::vector<int> v3 = {3, 2, 1};

    v2.swap(v3);

    foo(v2);
    foo(v3);

    return 0;
}
