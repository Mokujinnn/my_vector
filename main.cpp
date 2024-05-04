#include <istream>

#include "myvector.hpp"

int main(int argc, char const *argv[])
{
    
    my::vector<int> vec(10, 1);
    
    my::vector<int> veclv(vec);

    my::vector<int> vecrv(my::vector<int>(5, 5));

    return 0;
}
