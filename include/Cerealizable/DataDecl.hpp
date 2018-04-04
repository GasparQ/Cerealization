//
// Created by GasparQ on 04/04/2018.
//

#ifndef CEREALIZATION_CEREALIZABLE_DATADECL_HPP
#define CEREALIZATION_CEREALIZABLE_DATADECL_HPP

#include <string>
#include <set>
#include <vector>
#include <map>

namespace Cerealization
{
    namespace Cerealizable
    {
        template <typename T> class Scalar;
        template <typename T, typename I> class List;
        template <typename F, typename ... As> class Tuple;
        template <typename F, typename ... As> class Object;

        using Char = Scalar<char>;
        using UChar = Scalar<unsigned char>;
        using Short = Scalar<short>;
        using UShort = Scalar<unsigned short>;
        using Int = Scalar<int>;
        using UInt = Scalar<unsigned int>;
        using Long = Scalar<long>;
        using ULong = Scalar<unsigned long>;
        using LongLong = Scalar<long long>;
        using ULongLong = Scalar<unsigned long long>;
        using Float = Scalar<float>;
        using Double = Scalar<double>;

        using String = List<char, std::string>;
        template <typename T> using Vector = List<T, std::vector<T>>;
        template <typename T> using Set = List<T, std::set<T>>;
        template <typename Key, typename Value> using Map = List<std::pair<Key, Value>, std::map<Key, Value>>;

        template <typename Key, typename Value> using Pair = Tuple<Key, Value>;
    }
}

#endif //CEREALIZATION_CEREALIZABLE_DATADECL_HPP
