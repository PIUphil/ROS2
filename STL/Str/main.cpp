#include <iostream>
#include "Str.h"


int main() {
    Str s1 = "hello, world";
    Str s2 = (10, 'A');
    Str s3;
    Str s4 = s1;
    Str s5(s1.cbegin(), s1.cend());

    s3 = s1;

    if(s1==s3)
        std::cout << "s1 and s3 are equal";
    else
        std::cout << "s1 and s3 are not equal";

    s4 += "greeting";


    for (Str::size_type i=0 ; i!=s1.size() ; ++i)
        std::cout << s1[i] << " ";
    std::cout << std::endl;

    std::cout << s1 << std::endl;

    const char *str = s1.c_str();
    std::cout << str << std::endl;



    return 0;
}
