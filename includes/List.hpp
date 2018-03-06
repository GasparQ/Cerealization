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
                iterable(&towatch),
                allocated(false)
        {

        }

        List(std::initializer_list<Element> &&value) :
                iterable{new Iterable{value}},
                allocated(true)
        {

        }

        explicit List() :
                iterable(new Iterable()),
                allocated(true)
        {

        }

        virtual ~List()
        {
            if (allocated)
                delete(iterable);
        }

    public:
        Iterable &get() const
        {
            return *iterable;
        }

    private:
        Iterable *iterable;
        const bool allocated;
    };
}

#endif //CEREALIZATION_LIST_HPP
