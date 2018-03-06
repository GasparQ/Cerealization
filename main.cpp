#include <iostream>
#include <string>
#include <list>

#include <List.hpp>
#include <Scalar.hpp>
#include <Object.hpp>

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

class ObjRunner
{
public:
    ObjRunner() = default;

public:
    template <typename T>
    void operator()(std::string name, T &value)
    {
        std::cout << name << ": " << value << std::endl;
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

class TestJson : public Cerealization::Object <int, int>
{
public:
    TestJson() :
        Object{
                std::make_pair("x", &x),
                std::make_pair("y", &y)
        },
        x(102),
        y(2093)
    {

    }

private:
    int x, y;
};

int main()
{
    Cerealization::Scalar<int> titi(42);
    Cerealization::Tuple<int, int> toto(2, 3);
    Cerealization::List<int> tata{3, 2, 1, 4, 2, 3};
    Cerealization::Object<int, int> obj{
                                                std::make_pair("x", 30),
                                                std::make_pair("y", 41)
                                        };

    Test1 test1;
    Test2 test2;
    Test3 test3;
    TestJson testJson;

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

    ObjRunner runner;

    obj.forEach(runner);

    testJson.forEach(runner);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}