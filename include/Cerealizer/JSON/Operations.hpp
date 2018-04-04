//
// Created by GasparQ on 04/04/2018.
//

#ifndef CEREALIZATION_CEREALIZER_JSON_OPERATIONS_HPP
#define CEREALIZATION_CEREALIZER_JSON_OPERATIONS_HPP

#include <list>
#include <set>
#include <vector>
#include <map>

#include "DefaultOperations.hpp"
#include "Cerealizable/DataDecl.hpp"

/*
 * Operator <<
 */

template <typename T>
Cerealization::Cerealizer::JSONStream &operator<<(Cerealization::Cerealizer::JSONStream &stream, std::list<T> const &value);

template <typename T>
Cerealization::Cerealizer::JSONStream &operator<<(Cerealization::Cerealizer::JSONStream &stream, std::vector<T> const &value);

template <typename T>
Cerealization::Cerealizer::JSONStream &operator<<(Cerealization::Cerealizer::JSONStream &stream, std::set<T> const &value);

template <typename Key, typename Value>
Cerealization::Cerealizer::JSONStream &operator<<(Cerealization::Cerealizer::JSONStream &stream, std::pair<Key, Value> const &value);

template <typename Key, typename Value>
Cerealization::Cerealizer::JSONStream &operator<<(Cerealization::Cerealizer::JSONStream &stream, std::map<Key, Value> const &value);

template <typename T>
Cerealization::Cerealizer::JSONStream &operator<<(Cerealization::Cerealizer::JSONStream &output, Cerealization::Cerealizable::Scalar<T> const &data);

template <typename Element, typename Iterable>
Cerealization::Cerealizer::JSONStream &operator<<(Cerealization::Cerealizer::JSONStream &output, Cerealization::Cerealizable::List<Element, Iterable> const &data);

Cerealization::Cerealizer::JSONStream &operator<<(Cerealization::Cerealizer::JSONStream &stream, Cerealization::Cerealizable::String const &value);

template <typename First, typename ... Nexts>
Cerealization::Cerealizer::JSONStream &operator<<(Cerealization::Cerealizer::JSONStream &output, Cerealization::Cerealizable::Tuple<First, Nexts...> const &data);

template <typename First, typename ... Nexts>
Cerealization::Cerealizer::JSONStream &operator<<(Cerealization::Cerealizer::JSONStream &output, Cerealization::Cerealizable::Object<First, Nexts...> const &data);

/*
 * Operator >>
 */

template <typename T>
Cerealization::Cerealizer::JSONStream &operator>>(Cerealization::Cerealizer::JSONStream &stream, std::list<T> &value);

template <typename T>
Cerealization::Cerealizer::JSONStream &operator>>(Cerealization::Cerealizer::JSONStream &stream, std::vector<T> &value);

template <typename T>
Cerealization::Cerealizer::JSONStream &operator>>(Cerealization::Cerealizer::JSONStream &stream, std::set<T> &value);

template <typename Key, typename Value>
Cerealization::Cerealizer::JSONStream &operator>>(Cerealization::Cerealizer::JSONStream &stream, std::pair<Key, Value> &value);

template <typename Key, typename Value>
Cerealization::Cerealizer::JSONStream &operator>>(Cerealization::Cerealizer::JSONStream &stream, std::map<Key, Value> &value);

template <typename T>
Cerealization::Cerealizer::JSONStream &operator>>(Cerealization::Cerealizer::JSONStream &output, Cerealization::Cerealizable::Scalar<T> &data);

template <typename Element, typename Iterable>
Cerealization::Cerealizer::JSONStream &operator>>(Cerealization::Cerealizer::JSONStream &output, Cerealization::Cerealizable::List<Element, Iterable> &data);

Cerealization::Cerealizer::JSONStream &operator>>(Cerealization::Cerealizer::JSONStream &stream, Cerealization::Cerealizable::String &value);

template <typename First, typename ... Nexts>
Cerealization::Cerealizer::JSONStream &operator>>(Cerealization::Cerealizer::JSONStream &output, Cerealization::Cerealizable::Tuple<First, Nexts...> &data);

template <typename First, typename ... Nexts>
Cerealization::Cerealizer::JSONStream &operator>>(Cerealization::Cerealizer::JSONStream &output, Cerealization::Cerealizable::Object<First, Nexts...> &data);

#endif //CEREALIZATION_OPERATIONS_HPP
