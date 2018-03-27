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
#include <map>

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

            List(Iterable const &value) :
                    iterable{new Iterable(value)},
                    allocated(true)
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
            Iterable &get()
            {
                return *iterable;
            }

            const Iterable &get() const
            {
                return *iterable;
            }

        public:
            void push_back(Element const &ref) const
            {
                iterable->insert(iterable->end(), ref);
            }

            void clear() const
            {
                iterable->clear();
            }

        private:
            Iterable *iterable;
            const bool allocated;
        };

        using String = List<char, std::string>;
        using CString = List<const char, const std::string>;

        template <typename T>
        using Vector = List<T, std::vector<T>>;

        template <typename T>
        using Set = List<T, std::set<T>>;

        template <typename T>
        using USet = List<T, std::unordered_set<T>>;

        template <typename Key, typename Value>
        using Map = List<std::pair<Key, Value>, std::map<Key, Value>>;
    }
}

#endif //CEREALIZATION_LIST_HPP
