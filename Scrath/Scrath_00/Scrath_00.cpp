// Scrath_00.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class A {
public:
    virtual void Func1()
    {
        std::cout << "Hello World!\n";
    }
};
class B {
public:
    void Func1()
    {
        std::cout << "Hello World!\n";
    }
};
int main()
{
    A a;
    B b;
    std::cout << sizeof(a) << std::endl;
    std::cout << sizeof(b) << std::endl;
}
