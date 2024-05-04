#include <istream>

#include "myvector.hpp"

int main(int argc, char const *argv[])
{
    
    my::vector<int> vec(10, 0);

    my::vector<int> vec1(vec);
    
    return 0;
}
