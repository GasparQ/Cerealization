//
// Created by GasparQ on 07/03/2018.
//

#ifndef CEREALIZABLE_BINARY_OPERATIONS_HPP
#define CEREALIZABLE_BINARY_OPERATIONS_HPP

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
    return output;
}

template <typename First, typename ... Nexts>
BinaryStream &operator<<(BinaryStream &output, Tuple<First, Nexts...> const &data)
{
    BinaryTuple::Cereal ser(output);

    data.forEach(ser);

    return output;
}

template <typename First, typename ... Nexts>
BinaryStream &operator<<(BinaryStream &output, Object<First, Nexts...> const &data)
{
    BinaryObject::Cereal ser(output);

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

template <typename First, typename ... Nexts>
BinaryStream &operator>>(BinaryStream &output, Tuple<First, Nexts...> const &data)
{
    BinaryTuple::Decereal des(output);

    data.forEach(des);

    return output;
}


template <typename First, typename ... Nexts>
BinaryStream &operator>>(BinaryStream &output, Object<First, Nexts...> const &data)
{
    BinaryObject::Decereal des(output);

    data.forEach(des);

    return output;
}

#endif //CEREALIZABLE_BINARY_OPERATIONS_HPP
