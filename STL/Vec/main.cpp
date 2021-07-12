#include <iostream>
#include <iterator>
#include "Vec.h"


int main()
{
    int nums[] = {1, 2, 3, 4, 5};

    Vec<int> v4(nums, nums+5);
    Vec<int> v5 = v4;
    Vec<int> v2(100, 0);
    Vec<int> v3(10);            // Vec<int> v3 = 10;  X
    Vec<int> v1;


    for (int i=0; i<10; ++i)
        v1.push_back(i+1);

    std::copy(v1.cbegin(), v1.cend(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    for (auto iter=v1.cbegin() ; iter!=v1.cend() ; ++iter)
        std::cout << *iter << std::endl;


    v3 = v1;


    for(Vec<int>::size_type i=0 ; i<v3.size() ; ++i)
        std::cout << v3[i] << std::endl;

    for(auto iter = v5.cbegin() ; iter!=v5.cend() ; ++iter)
        std::cout << *iter << std::endl;


    return 0;
}
