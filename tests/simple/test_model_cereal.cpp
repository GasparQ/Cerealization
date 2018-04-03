//
// Created by GasparQ on 03/04/2018.
//

#include <cassert>
#include <iostream>
#include <typeinfo>

#include "Cerealizable/Scalar.hpp"
#include "Cerealizable/List.hpp"
#include "Cerealizable/Tuple.hpp"
#include "Cerealizable/Object.hpp"

#include "Cerealizer/Binary/Binary.hpp"
#include "Cerealizer/JSON/JSON.hpp"

using namespace Cerealization;

template <typename Cerealizer, typename Data>
bool test_cerealize(Data const &toser)
{
    Cerealizer cerealizer;
    Data    witness;

    std::string dataname(typeid(Data).name());
    std::string cername(typeid(Cerealizer).name());

    std::cout << "Cerealizing " << dataname.substr(31) << " into " << cername.substr(30) << " ===> ";

    cerealizer << toser;

    if (std::is_same<std::string, decltype(cerealizer.Data())>::value)
        std::cout << cerealizer.Data() << " ===> ";

    cerealizer >> witness;

    if (toser == witness)
    {
        std::cout << "Success" << std::endl;
        return true;
    }
    std::cout << "Failure" << std::endl;
    return false;
}

template <typename Cerealizer>
void test_scalar()
{
    assert(test_cerealize<Cerealizer>(Cerealizable::Char('t')));
    assert(test_cerealize<Cerealizer>(Cerealizable::Char(-128)));
    assert(test_cerealize<Cerealizer>(Cerealizable::UChar('t')));
    assert(test_cerealize<Cerealizer>(Cerealizable::UChar(255)));
    assert(test_cerealize<Cerealizer>(Cerealizable::Short(-42)));
    assert(test_cerealize<Cerealizer>(Cerealizable::UShort(42)));
    assert(test_cerealize<Cerealizer>(Cerealizable::Int(-2000000000)));
    assert(test_cerealize<Cerealizer>(Cerealizable::UInt(4000000000)));
    assert(test_cerealize<Cerealizer>(Cerealizable::Long(-2000000000)));
    assert(test_cerealize<Cerealizer>(Cerealizable::ULong(4000000000)));
    assert(test_cerealize<Cerealizer>(Cerealizable::LongLong(-8000000000000000000)));
    assert(test_cerealize<Cerealizer>(Cerealizable::ULongLong(9000000000000000000)));
    assert(test_cerealize<Cerealizer>(Cerealizable::Float(50.3f)));
    assert(test_cerealize<Cerealizer>(Cerealizable::Float(-50.3f)));
    assert(test_cerealize<Cerealizer>(Cerealizable::Double(50.3)));
    assert(test_cerealize<Cerealizer>(Cerealizable::Double(-50.3)));
}

template <typename Cerealizer>
void test_list()
{
    assert(test_cerealize<Cerealizer>(Cerealizable::String("Coucou")));
    std::string toto("coucou");
    assert(test_cerealize<Cerealizer>(Cerealizable::String(toto)));
    assert(test_cerealize<Cerealizer>(Cerealizable::List<int>({3, 1, 20})));
    assert(test_cerealize<Cerealizer>(
        Cerealizable::List<Cerealizable::String>(
        {
                Cerealizable::String("hey"),
                Cerealizable::String("ho"),
                Cerealizable::String("hello")
        }
    )));
    assert(test_cerealize<Cerealizer>(Cerealizable::Vector<int>({3, 1, 20})));
    assert(test_cerealize<Cerealizer>(
        Cerealizable::Vector<Cerealizable::String>(
        {
                Cerealizable::String("hey"),
                Cerealizable::String("ho"),
                Cerealizable::String("hello")
        }
    )));
    assert(test_cerealize<Cerealizer>(Cerealizable::Set <int>({3, 1, 20})));
    assert(test_cerealize<Cerealizer>(Cerealizable::Set <std::string>({ "hey", "ho", "hello" })));
    assert(test_cerealize<Cerealizer>(Cerealizable::Map <char, int>({ {'j', 3}, {'l', 1}, {'i', 20} })));
    assert(test_cerealize<Cerealizer>(
        Cerealizable::Map <std::string, Cerealizable::String>(
        {
           {"hey", Cerealizable::String("hey")},
           {"ho", Cerealizable::String("ho")},
           {"hello", Cerealizable::String("hello")}
        }
    )));
    assert(test_cerealize<Cerealizer>(Cerealizable::List<Tuple<int, String, Int>>{
        Tuple<int, String, Int>(43, String("toto"), 50),
        Tuple<int, String, Int>(78, String("tutu"), 90),
        Tuple<int, String, Int>(-78, String("tata"), 120),
        Tuple<int, String, Int>(-388, String("titi"), -3920)
    }));
}

template <typename Cerealizer>
void test_tuple()
{
    assert(test_cerealize<Cerealizer>(Tuple<int, int, int>(-43, 29, 39)));
    assert(test_cerealize<Cerealizer>(Tuple<int, char, double>(-43, 'd', 3.14)));
    assert(test_cerealize<Cerealizer>(Tuple<Scalar<int>, char, double>(-43, 'd', 3.14)));
    assert(test_cerealize<Cerealizer>(Tuple<Scalar<int>, String, double>(-43, String("Coucou"), 3.14)));
    assert(test_cerealize<Cerealizer>(Tuple<Scalar<int>, String, Tuple<int, int, int>>(-43, String("Coucou"), Tuple<int, int, int>(3, -42, 39))));
    assert(test_cerealize<Cerealizer>(Tuple<Scalar<int>, String, Tuple<int, String, int>>(-43, String("Coucou"), Tuple<int, String, int>(3, String("C'est moit"), 39))));
}

template <typename Cerelizer>
void test_object()
{
    assert(test_cerealize<Cerelizer>(Object<int, int, int>({"x", 42}, {"y", -42}, {"z", 390})));
    assert(test_cerealize<Cerelizer>(Object<int, char, double>({"x", 42}, {"id", 'k'}, {"radius", 3.14})));
    assert(test_cerealize<Cerelizer>(Object<Scalar<int>, char, double>({"x", 42}, {"id", 'k'}, {"radius", 3.14})));
    assert(test_cerealize<Cerelizer>(Object<Scalar<int>, String, double>({"x", 42}, {"id", String("Toto")}, {"radius", 3.14})));
    assert(test_cerealize<Cerelizer>(Object<Scalar<int>, String, Tuple<int, int, int>>({"x", 42}, {"id", String("Toto")}, {"radius", Tuple<int, int, int>(3, -42, 39)})));
    assert(test_cerealize<Cerelizer>(Object<Scalar<int>, String, Tuple<int, String, int>>({"x", 42}, {"id", String("Toto")}, {"radius", Tuple<int, String, int>(3, String("C'est moi"), 39)})));
}

int main()
{
    test_scalar<Cerealizer::BinaryStream>();
    test_scalar<Cerealizer::JSONStream>();

    test_list<Cerealizer::BinaryStream>();
    test_list<Cerealizer::JSONStream>();

    test_tuple<Cerealizer::BinaryStream>();
    test_tuple<Cerealizer::JSONStream>();

    test_object<Cerealizer::BinaryStream>();
    test_object<Cerealizer::JSONStream>();

    return 0;
}