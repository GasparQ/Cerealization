#include <iostream>
#include <list>

#include <List.hpp>
#include <Scalar.hpp>

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

class Test2 : public Cerealization::Tuple<int, int>
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

class Test3 : public Cerealization::List<int, std::list<int>>
{
public:
    Test3() :
        List(toto),
        toto{4, 3, 2, 1}
    {

    }

private:
    std::list<int> toto;
};

class Test1 : public Cerealization::Scalar<int>
{
public:
    Test1() :
        Scalar(x),
        x(50)
    {

    }

private:
    int x;
};

int main()
{
    Cerealization::Scalar<int> titi(42);
    Cerealization::Tuple<int, int> toto(2, 3);
    Cerealization::List<int> tata{3, 2, 1, 4, 2, 3};

    Test1 test1;
    Test2 test2;
    Test3 test3;

    std::cout << "Titi: " << titi.get() << std::endl;
    std::cout << "Test1: " << test1.get() << std::endl;

    Tutu tutu;

    toto.forEach(tutu);

    toto.forEach(tutu);

    test2.forEach(tutu);

    test2.forEach(tutu);

    for (int curr : tata.get())
    {
        std::cout << "Tata: " << curr << std::endl;
    }

    for (int curr : test3.get())
    {
        std::cout << "Test3: " << curr << std::endl;
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}