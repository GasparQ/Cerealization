//
// Created by GasparQ on 07/03/2018.
//

#ifndef CEREALIZABLE_JSON_OPERATIONS_HPP
#define CEREALIZABLE_JSON_OPERATIONS_HPP

#include "Cerealizable/Scalar.hpp"
#include "Cerealizable/List.hpp"
#include "Cerealizable/Object.hpp"
#include "Cerealizable/Tuple.hpp"
#include "JSONStream.hpp"
#include "DefaultOperations.hpp"
#include "JSONTuple.hpp"
#include "JSONObject.hpp"

using namespace Cerealization::Cerealizer;
using namespace Cerealization::Cerealizable;

template <typename T>
JSONStream  &operator<<(JSONStream &output, Scalar<T> const &data)
{
    return output << data.get();
}

template <typename Element, typename Iterable>
JSONStream &operator<<(JSONStream &output, List<Element, Iterable> const &data)
{
    JSONStream cpy;
    bool first = true;

    for (Element const &curr : data.get())
    {
        if (first)
            first = false;
        else
            cpy.Write(", ");
        cpy << curr;
    }
    output.Write("[");
    output << cpy;
    output.Write("]");
    return output;
}

template <typename First, typename ... Nexts>
JSONStream &operator<<(JSONStream &output, Tuple<First, Nexts...> const &data)
{
    JSONTuple::Cereal ser(output);

    output.Write("[");
    data.forEach(ser);
    output.Write("]");
    return output;
}

template <typename First, typename ... Nexts>
JSONStream &operator<<(JSONStream &output, Object<First, Nexts...> const &data)
{
    JSONObject::Cereal ser(output);

    output.Write("{");
    data.forEach(ser);
    output.Write("}");
    return output;
}

template <typename T>
JSONStream &operator>>(JSONStream &output, Scalar<T> &data)
{
    output >> data.get();
    return output;
}

template <typename Element, typename Iterable>
JSONStream &operator>>(JSONStream &output, List<Element, Iterable> &data)
{
    bool first = true;

    data.clear();
    output.ignore(1); //ignore "["
    while (output.Size() && output.nextCharacter() != ']')
    {
        Element e;

        if (first)
            first = false;
        else
            output.ignore(2); //ignore ", "
        output >> e;
        data.push_back(e);
    }
    output.ignore(1); //ignore "]"
    return output;
};

template <typename First, typename ... Nexts>
JSONStream &operator>>(JSONStream &output, Tuple<First, Nexts...> &data)
{
    JSONTuple::Decereal des(output);

    output.ignore(1);   //ignore "["
    data.forEach(des);
    output.ignore(1);   //ignore "]"

    return output;
}

template <typename First, typename ... Nexts>
JSONStream &operator>>(JSONStream &output, Object<First, Nexts...> &data)
{
    JSONObject::Decereal des(output);

    output.ignore(1);   //ignore "{"
    data.forEach(des);
    output.ignore(1);   //ignore "}"

    return output;
}

#endif //CEREALIZABLE_JSON_OPERATIONS_HPP
