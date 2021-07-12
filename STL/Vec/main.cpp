#include <iostream>
#include "Vec.h"


int main()
{
    int nums[] = {1, 2, 3, 4, 5};
    Vec<int> v5 = v4;
    Vec<int> v4(nums, nums+5);
    Vec<int> v2(100, 0);
    Vec<int> v3(10);            // Vec<int> v3 = 10;  X
    Vec<int> v1;

    for(Vec<int>::size_type i=0 ; i<v4.size() ; ++i)
        std::cout << v4[i] << std::endl;

    for(auto iter = v4.cbegin() ; iter!=v4.cend() ; ++iter)
        std::cout << *iter << std::endl;


    return 0;
}
