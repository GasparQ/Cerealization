//
// Created by GasparQ on 05/03/2018.
//

#ifndef CEREALIZATION_LIST_HPP
#define CEREALIZATION_LIST_HPP

#include <type_traits>
#include <vector>

namespace Cerealization
{
    template <typename Element, typename Iterable = std::vector<Element>>
    class List
    {
    public:
        explicit List(Iterable &towatch) :
                iterable(&towatch)
        {

        }

        List(std::initializer_list<Element> &&value) :
                iterable{new Iterable{value}}
        {

        }

        explicit List() :
                iterable(new Iterable())
        {

        }

    public:
        Iterable &get() const
        {
            return *iterable;
        }

    private:
        Iterable *iterable;
    };
}

#endif //CEREALIZATION_LIST_HPP
