#include <iostream>
#include <string>
#include <list>
#include <cassert>

#include "Cerealizable/List.hpp"
#include "Cerealizable/Object.hpp"
#include "Cerealizable/Scalar.hpp"
#include "Cerealizable/Tuple.hpp"

#include "Cerealizer/Binary/Binary.hpp"
#include "Cerealizer/JSON/JSON.hpp"

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

class Test3 : public Cerealization::Cerealizable::List<int, std::vector<int>>
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
    std::vector<int> toto;
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

template <typename Cereal, typename T>
void TestSerial(T const &data)
{
    Cereal cerealizer;
    T witness;

    cerealizer << data;

    if (std::is_same<decltype(cerealizer.Data()), std::string>::value)
        std::cout << cerealizer.Data() << std::endl;

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

    TestSerial<Cerealization::Cerealizer::BinaryStream>(test1);
    TestSerial<Cerealization::Cerealizer::BinaryStream>(test2);
    TestSerial<Cerealization::Cerealizer::BinaryStream>(test3);
    TestSerial<Cerealization::Cerealizer::BinaryStream>(testJson);

    TestSerial<Cerealization::Cerealizer::JSONStream>(test1);
    TestSerial<Cerealization::Cerealizer::JSONStream>(test2);
    TestSerial<Cerealization::Cerealizer::JSONStream>(test3);
    TestSerial<Cerealization::Cerealizer::JSONStream>(testJson);

    std::list<int> test_list = {3, 4, 2, 1};

    std::map<std::string, int> test_map = {
            {"coucou", 3},
            {"salut", 39},
            {"932", 32}
    };

    TestSerial<Cerealization::Cerealizer::BinaryStream>(test_list);
    TestSerial<Cerealization::Cerealizer::JSONStream>(test_list);

    TestSerial<Cerealization::Cerealizer::BinaryStream>(test_map);
    TestSerial<Cerealization::Cerealizer::JSONStream>(test_map);

    return 0;
}