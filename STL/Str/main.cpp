#include <iostream>
#include <cstring>
#include "Str.h"


int main() {
    Str s1 = "hello, world";
    Str s2(10, 'A');
    Str s3;
    Str s4 = s1;
    Str s5(s1.cbegin(), s1.cend());

    s3 = s1;

    std::cout << s2 << std::endl;

    if(s1==s3)
        std::cout << "s1 and s3 are equal" << std::endl;
    else
        std::cout << "s1 and s3 are not equal" << std::endl;


    s4 += "greeting";

    s1 = s1 + Str(" greeting");

    for (Str::size_type i=0 ; i!=s1.size() ; ++i)
        std::cout << s1[i] << " ";
    std::cout << std::endl;

    std::cout << s1 << std::endl;

    std::cout << std::endl << "입력 : ";
    std::cin >> s1;
    std::cout << s1 << std::endl;


    const char *str = s1.c_str();
    std::cout << str << std::endl;


    char buf[1024];
    s1.copy(buf, s1.size()+1); // , s1.cbegin());

    std::cout << "buf : " << buf << std::endl;

    s1.insert(s1.begin()+2, s4.cbegin(), s4.cend());
    std::cout<< s1 << std::endl;

    return 0;
}
