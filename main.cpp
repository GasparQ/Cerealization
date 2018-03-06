#include <iostream>

#include "Tuple.hpp"

class Tutu
{
public:
    Tutu() = default;

public:
    template <typename Any>
    void operator()(Any &hey)
    {
        std::cout << "Hello: " << hey << std::endl;
        hey = 50;
        std::cout << "  Set: " << hey << std::endl;
    }
};

class Test2 : public Ceralization::Tuple<int, int>
{
public:
    Test2() :
        Tuple(a, b),
        a(3),
        b(0)
    {

    }

private:
    int a;
    int b;
};

int main()
{
    Ceralization::Tuple<int, int> toto(2, 3);
    Test2 test;
    Tutu tutu;

    toto.forEach(tutu);

    toto.forEach(tutu);

    test.forEach(tutu);

    test.forEach(tutu);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}