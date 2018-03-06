//
// Created by GasparQ on 05/03/2018.
//

#ifndef CEREALIZATION_OBJECT_HPP
#define CEREALIZATION_OBJECT_HPP

#include <string>
#include <vector>
#include <functional>

#include "Tuple.hpp"

namespace Cerealization
{
    template <typename First, typename ... Args>
    class Object : private Tuple<First, Args...>
    {
    private:
        template <typename Callable>
        class Injector
        {
        public:
            Injector(Callable &callback, std::vector<std::string> const &names) :
                callback(callback),
                names(names),
                index(0)
            {

            }

        public:
            template <typename T>
            void operator()(T &curr)
            {
                callback(names[index++], curr);
            }

        private:
            Callable &callback;
            const std::vector<std::string> &names;
            unsigned int index;
        };

    public:
        template <typename T>
        using Element = std::pair<std::string, T>;

    public:
        explicit Object(Element<First*> const &attr, Element<Args*> const &... attrs) :
                Tuple<First, Args...>{*attr.second, *attrs.second...},
                names{attr.first, attrs.first...}
        {

        }

        explicit Object(Element<First> &&fval, Element<Args> &&... ovals) :
                Tuple<First, Args...>{fval.second, ovals.second...},
                names{fval.first, ovals.first...}
        {

        }

        Object(std::initializer_list<std::string> const &names) :
            Tuple<First, Args...>{},
            names(names)
        {

        }

    public:
        template <typename Callable>
        void forEach(Callable &tocall) const
        {
            Injector<Callable> injector(tocall, names);

            Tuple<First, Args...>::forEach(injector);
        }

    private:
        std::vector<std::string> names;
    };
}

#endif //CEREALIZATION_OBJECT_HPP
