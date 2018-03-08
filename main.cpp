#include <iostream>
#include <string>
#include <list>
#include <cassert>

#include "Cerealizable/List.hpp"
#include "Cerealizable/Object.hpp"
#include "Cerealizable/Scalar.hpp"
#include "Cerealizable/Tuple.hpp"

#include "Cerealizer/Binary/BinaryStream.hpp"
#include "Cerealizer/Binary/Operations.hpp"

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

class Test2 : public Cerealization::Cerealizable::Tuple<int, int>
{
public:
    Test2() :
        Tuple(a, b),
        a(3),
        b(0)
    {

    }

public:
    bool operator==(Test2 const &ref) const
    {
        return a == ref.a && b == ref.b;
    }

private:
    int a;
    int b;
};

class Test3 : public Cerealization::Cerealizable::List<int, std::list<int>>
{
public:
    Test3() :
        List(toto),
        toto{4, 3, 2, 1}
    {

    }

public:
    bool operator==(Test3 const &ref) const
    {
        return toto == ref.toto;
    }

private:
    std::list<int> toto;
};

class Test1 : public Cerealization::Cerealizable::Scalar<int>
{
public:
    Test1() :
        Scalar(x),
        x(50)
    {

    }

public:
    bool operator==(Test1 const &ref) const
    {
        return x == ref.x;
    }

private:
    int x;
};

class TestJson : public Cerealization::Cerealizable::Object <int, int>
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

public:
    bool operator==(TestJson const &ref) const
    {
        return x == ref.x && y == ref.y;
    }

private:
    int x, y;
};

template <typename T>
void TestSerial(T const &data)
{
    Cerealization::Cerealizer::BinaryStream cerealizer;
    T witness;

    cerealizer << data;

    cerealizer >> witness;

    assert(data == witness);
}

int main()
{
    Cerealization::Cerealizable::Scalar<int> titi(42);
    Cerealization::Cerealizable::Tuple<int, int> toto(2, 3);
    Cerealization::Cerealizable::List<int> tata{3, 2, 1, 4, 2, 3};
    Cerealization::Cerealizable::Object<int, int> obj{
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

    TestSerial(test1);
    TestSerial(test2);
    TestSerial(test3);
    TestSerial(testJson);

    return 0;
}