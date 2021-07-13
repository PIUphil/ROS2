#include <iostream>

#include "Core.h"
#include "Grad.h"


int main()
{
    Core *pCore = new Grad();           // 부모클래스의 포인터는 자식클래스의 객체를 가리킬 수 있다  // 다형성 polymorphism


    return 0;
}
