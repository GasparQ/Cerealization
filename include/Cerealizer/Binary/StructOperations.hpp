//
// Created by GasparQ on 27/03/2018.
//

#ifndef CEREALIZATION_BINARY_STRUCTOPERATIONS_HPP
#define CEREALIZATION_BINARY_STRUCTOPERATIONS_HPP

#include "Cerealizable/List.hpp"
#include "Cerealizable/Tuple.hpp"

#include "ModelOperations.hpp"

template <typename T>
BinaryStream &operator<<(BinaryStream &stream, std::list<T> const &value)
{
    List<T> toser(value);

    stream << toser;
    return stream;
}

template <typename T>
BinaryStream &operator<<(BinaryStream &stream, std::vector<T> const &value)
{
    Vector<T> toser(value);

    stream << toser;
    return stream;
}

template <typename T>
BinaryStream &operator<<(BinaryStream &stream, std::set<T> const &value)
{
    Set<T> toser(value);

    stream << toser;
    return stream;
}

template <typename Key, typename Value>
BinaryStream &operator<<(BinaryStream &stream, std::pair<Key, Value> const &value)
{
    Pair<Key, Value> toser(value.first, value.second);

    stream << toser;
    return stream;
}

template <typename Key, typename Value>
BinaryStream &operator<<(BinaryStream &stream, std::map<Key, Value> const &value)
{
    Map<Key, Value> toser(value);

    stream << toser;
    return stream;
}

template <typename T>
BinaryStream &operator>>(BinaryStream &stream, std::list<T> &value)
{
    List<T> toser(value);

    stream >> toser;
    return stream;
}

template <typename T>
BinaryStream &operator>>(BinaryStream &stream, std::vector<T> &value)
{
    Vector<T> toser(value);

    stream >> toser;
    return stream;
}

template <typename T>
BinaryStream &operator>>(BinaryStream &stream, std::set<T> &value)
{
    Set<T> toser(value);

    stream >> toser;
    return stream;
}

template <typename Key, typename Value>
BinaryStream &operator>>(BinaryStream &stream, std::pair<Key, Value> &value)
{
    Pair<Key, Value> toser(value.first, value.second);

    stream >> toser;
    return stream;
}

template <typename Key, typename Value>
BinaryStream &operator>>(BinaryStream &stream, std::map<Key, Value> &value)
{
    Map<Key, Value> toser(value);

    stream >> toser;
    return stream;
}

#endif //CEREALIZATION_STRUCTOPERATIONS_HPP
