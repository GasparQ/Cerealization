//
// Created by GasparQ on 07/03/2018.
//

#ifndef CEREALIZABLE_OPERATIONS_HPP
#define CEREALIZABLE_OPERATIONS_HPP

#include "Cerealizable/Scalar.hpp"
#include "Cerealizable/List.hpp"
#include "Cerealizable/Tuple.hpp"
#include "Cerealizable/Object.hpp"
#include "BinaryStream.hpp"
#include "BinaryTuple.hpp"
#include "BinaryObject.hpp"
#include "DefaultOperations.hpp"

using namespace Cerealization::Cerealizer;
using namespace Cerealization::Cerealizable;

template <typename T>
BinaryStream &operator<<(BinaryStream &output, Scalar<T> const &data)
{
    return output << data.get();
}

template <typename Element, typename Iterable>
BinaryStream &operator<<(BinaryStream &output, List<Element, Iterable> const &data)
{
    BinaryStream cpy;
    uint32_t size = 0;

    for (Element const &curr : data.get())
    {
        cpy << curr;
        ++size;
    }
    output << size << cpy;
}

//class BinaryTupleCerealizer
//{
//public:
//    explicit BinaryTupleCerealizer(BinaryStream &out) :
//        out(out)
//    {
//
//    }
//
//    template <typename T>
//    void operator()(T const &dat)
//    {
//        out << dat;
//    }
//
//private:
//    BinaryStream &out;
//};
template <typename First, typename ... Nexts>
BinaryStream &operator<<(BinaryStream &output, Tuple<First, Nexts...> const &data)
{
    BinaryTuple::Cerealizer ser(output);

    data.forEach(ser);

    return output;
}

//class BinaryObjectCerealizer
//{
//public:
//    explicit BinaryObjectCerealizer(BinaryStream &out) :
//            out(out)
//    {
//
//    }
//
//    template <typename T>
//    void operator()(std::string const &name, T const &data)
//    {
//        out << name << data;
//    }
//
//private:
//    BinaryStream &out;
//};
template <typename First, typename ... Nexts>
BinaryStream &operator<<(BinaryStream &output, Object<First, Nexts...> const &data)
{
    BinaryObject::Cerealizer ser(output);

    data.forEach(ser);

    return output;
}

template <typename T>
BinaryStream &operator>>(BinaryStream &output, Scalar<T> &data)
{
    return output >> data.get();
}

template <typename Element, typename Iterable>
BinaryStream &operator>>(BinaryStream &output, List<Element, Iterable> const &data)
{
    uint32_t size;

    data.clear();
    output >> size;
    for (uint32_t i = 0; i < size; i++)
    {
        Element e;

        output >> e;
        data.push_back(e);
    }
    return output;
}

//class BinaryTupleDecerealizer
//{
//public:
//    explicit BinaryTupleDecerealizer(BinaryStream &out) :
//            out(out)
//    {
//
//    }
//
//    template <typename T>
//    void operator()(T &data)
//    {
//        out >> data;
//    }
//
//private:
//    BinaryStream &out;
//};
template <typename First, typename ... Nexts>
BinaryStream &operator>>(BinaryStream &output, Tuple<First, Nexts...> const &data)
{
    BinaryTuple::Decerealizer des(output);

    data.forEach(des);

    return output;
}

class BinaryObjectDecerealizer
{
public:
    explicit BinaryObjectDecerealizer(BinaryStream &out) :
            out(out)
    {

    }

    template <typename T>
    void operator()(std::string &name, T &data)
    {
        out >> name >> data;
    }

private:
    BinaryStream &out;
};
template <typename First, typename ... Nexts>
BinaryStream &operator>>(BinaryStream &output, Object<First, Nexts...> const &data)
{
    BinaryObjectDecerealizer des(output);

    data.forEach(des);

    return output;
}

#endif //CEREALIZABLE_OPERATIONS_HPP
