#include <iostream>
#include <string>

#include "Handle.h"

using std::string;

int main()
{
    Handle<string> pStr(new string("Hello, world"));
    Handle<string> pStr2 = pStr;

    (*pStr) = "wonderful tonight";

    std::cout << "*pStr2 : " << *pStr2 << std::endl;


    return 0;
}
