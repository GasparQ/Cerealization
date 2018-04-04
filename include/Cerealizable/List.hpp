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
#include <unordered_map>

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
                    iterable{new Iterable(value.begin(), value.end())},
                    allocated(true)
            {

            }

            explicit List() :
                    iterable(new Iterable()),
                    allocated(true)
            {

            }

            List(List<Element, Iterable> const &ref) :
                iterable(new Iterable(ref.get())),
                allocated(true)
            {

            }

            virtual ~List()
            {
                if (allocated)
                    delete(iterable);
            }

            bool operator==(List<Element, Iterable> const &ref) const
            {
                return get() == ref.get();
            }

            bool operator!=(List<Element, Iterable> const &ref) const
            {
                return get() != ref.get();
            }

            List<Element, Iterable> &operator=(List<Element, Iterable> const &cpy)
            {
                get() = cpy.get();
                return *this;
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

            void set(Iterable const &ref)
            {
                get() = ref;
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

        public:
            operator Iterable() const
            {
                return *iterable;
            }

        private:
            Iterable *iterable;
            const bool allocated;
        };
    }
}

#endif //CEREALIZATION_LIST_HPP
