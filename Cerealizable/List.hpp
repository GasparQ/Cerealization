//
// Created by GasparQ on 05/03/2018.
//

#ifndef CEREALIZATION_LIST_HPP
#define CEREALIZATION_LIST_HPP

#include <type_traits>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>

namespace Cerealization
{
    namespace Cerealizable
    {
        template <typename Element, typename Iterable = std::list<Element>>
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

        using String = List<char, std::string>;

        template <typename T>
        using Vector = std::vector<T>;

        template <typename T>
        using Set = std::set<T>;

        template <typename T>
        using USet = std::unordered_set<T>;
    }
}

#endif //CEREALIZATION_LIST_HPP
